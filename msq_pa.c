#include <stdio.h>
#include <portaudio.h>
#include <string.h>
#include <stdlib.h>
#include "msq.h"
#include "msq_pa.h"

msq_buffer* msq_buffer_create(uint size, uint nb_channels)
{
    msq_buffer *buff = malloc(sizeof(*buff)* nb_channels);
    buff->b = malloc(sizeof(int**)* nb_channels);
    for(int i = 0; i < nb_channels; i++)
        buff->b[i] = malloc(sizeof(int*) * size);
    return buff;
}

void msq_buffer_free(msq_buffer* buff)
{
    for(int i = 0; i < buff->nb_channels; i++)
        free(buff->b[i]);
    free(buff->b);
    free(buff);
}

void msq_buffer_set(msq_buffer* buff, int * b, uint channel)
{
    for(int i = 0; i < buff->size; i++)
        buff->b[channel][i] = b[i];
}

void msq_buffer_set_from_interleaved(msq_buffer* buff, int * b, uint channels)
{
    for(int i = 0; i < buff->nb_channels; i++)
        for(int j = 0; j < buff->size; j++)
            buff->b[i][j] = b[j*buff->nb_channels + i]; // this could be optimised further
}

PaStream *stream;
PaStreamParameters *in_parameters;
PaStreamParameters *out_parameters;
int** big_buffer;

void msq_audio_print_err(int err)
{
    printf("PortAudio error: %s\n", Pa_GetErrorText( err ) );
}

void msq_audio_init()
{
    PaError err;
    stream = 0;
    if(err = Pa_Initialize())
        msq_audio_print_err(err);
}

void msq_audio_close()
{
    PaError err;
    if(err = Pa_Terminate())
        msq_audio_print_err(err);
}

typedef struct {
    int ** buffer;
    uint position_in_buffer;
    uint nb_channels;
    uint buffer_length;
} user_data_template;

static int msq_audio_callback(  const void *input_buffer, 
                                void *output_buffer,
                                unsigned long frames_per_buffer,
                                const PaStreamCallbackTimeInfo* time_info,
                                PaStreamCallbackFlags status_flags,
                                void *user_data )
{
    user_data_template* data = (user_data_template*) user_data;
    int *out = (int*)output_buffer;
    int ** temp_buff;

    for(uint i = 0; i < frames_per_buffer * out_parameters->channelCount; i+=out_parameters->channelCount)
        for (uint j = 0; j < out_parameters->channelCount; j++)
            out[i*out_parameters->channelCount + j] = data->buffer[j][i + data->position_in_buffer];

    data->position_in_buffer += frames_per_buffer;
    return paContinue;
} 

void msq_audio_set_device(uint in_device, uint out_device, uint sample_rate, uint buffer_size)
{
    PaStreamParameters *output_parameters = msq_malloc(sizeof(*output_parameters), 0);
    output_parameters->device = out_device;
    output_parameters->channelCount = Pa_GetDeviceInfo(output_parameters->device)->maxOutputChannels;
    output_parameters->sampleFormat = SAMPLE_FORMAT;
    output_parameters->suggestedLatency = Pa_GetDeviceInfo(output_parameters->device)->defaultLowOutputLatency;
    output_parameters->hostApiSpecificStreamInfo = NULL;

    PaStreamParameters *input_parameters = msq_malloc(sizeof(*input_parameters), 0);
    input_parameters->device = in_device;
    input_parameters->channelCount = Pa_GetDeviceInfo(input_parameters->device)->maxOutputChannels;
    input_parameters->sampleFormat = SAMPLE_FORMAT;
    input_parameters->suggestedLatency = Pa_GetDeviceInfo(input_parameters->device)->defaultLowOutputLatency;
    input_parameters->hostApiSpecificStreamInfo = NULL;

    big_buffer = msq_malloc(sizeof(*big_buffer) * output_parameters->channelCount, 0);
    for(int i = 0; i < output_parameters->channelCount; i++)
        big_buffer[i] = msq_malloc(sizeof(*big_buffer[i])*BIG_BUFFER_LENGTH*sample_rate, 0);
        
    user_data_template * user_data = msq_malloc(sizeof(*user_data),0);
    user_data->buffer = big_buffer;
    user_data->position_in_buffer = 0;
    user_data->nb_channels = output_parameters->channelCount;
    user_data->buffer_length = BIG_BUFFER_LENGTH * sample_rate;

    PaError err = Pa_OpenStream(&stream, output_parameters, input_parameters, sample_rate, buffer_size, paClipOff, msq_audio_callback, user_data);
    if (err)
        msq_audio_print_err(err);
}

void msq_list_audio_devices()
{
    int numDevices;
        numDevices = Pa_GetDeviceCount();
    if( numDevices < 0 )
    {
        printf( "ERROR: Pa_CountDevices returned 0x%x\n", numDevices );
        msq_audio_print_err(numDevices);
    }
    const PaDeviceInfo *deviceInfo;
    for(int i=0; i<numDevices; i++ )
    {
        deviceInfo = Pa_GetDeviceInfo( i );
        const PaHostApiInfo *api = Pa_GetHostApiInfo(deviceInfo->hostApi);
        printf(
            "Device %d:\n\tName: %s,\n\tHost: %s,\n\tMaxIntputChannels: %d,\n\tMaxOutputChannels: %d \n", 
            i,deviceInfo->name, api->name ,deviceInfo->maxInputChannels, deviceInfo->maxOutputChannels);
    }
}
