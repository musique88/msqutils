#include <stdio.h>
#include <portaudio.h>
#include "msq.h"
#include "msq_pa.h"

PaStream *stream;
int** big_buffer;

void msq_audio_print_err(int err)
{
    printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );
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
} user_data_template;

static int msq_audio_callback(const void *inputBuffer, void *outputBuffer,
                    unsigned long framesPerBuffer,
                    const PaStreamCallbackTimeInfo* timeInfo,
                    PaStreamCallbackFlags statusFlags,
                    void *userData )
{
    
} 

void msq_audio_set_device(uint in_device, uint out_device, uint sample_rate, uint buffer_size)
{
    PaStreamParameters *output_parameters = msq_malloc(sizeof(*output_parameters), 0);
    output_parameters->device = out_device;
    output_parameters->channelCount = Pa_GetDeviceInfo(output_parameters->device)->maxOutputChannels;
    output_parameters->sampleFormat = SAMPLE_FORMAT;
    output_parameters->suggestedLatency = Pa_GetDeviceInfo(output_parameters->device)->defaultLowOutputLatency; // Check if buffer_size is 0, assign the default
    output_parameters->hostApiSpecificStreamInfo = NULL;

    PaStreamParameters *input_parameters = msq_malloc(sizeof(*input_parameters), 0);
    input_parameters->device = in_device;
    input_parameters->channelCount = Pa_GetDeviceInfo(input_parameters->device)->maxOutputChannels;
    input_parameters->sampleFormat = SAMPLE_FORMAT;
    input_parameters->suggestedLatency = Pa_GetDeviceInfo(input_parameters->device)->defaultLowOutputLatency; // Check if buffer_size is 0, assign the default
    input_parameters->hostApiSpecificStreamInfo = NULL;

    big_buffer =  msq_malloc(sizeof(*big_buffer) * output_parameters->channelCount, 0);
    for(int i = 0; i < output_parameters->channelCount; i++)
        big_buffer[i] = msq_malloc(size_of(*big_buffer[i])*BIG_BUFFER_LENGTH*sample_rate, 0);
    user_data_template * user_data = msq_malloc(size_of(*user_data),0);
    user_data->buffer = big_buffer;
    user_data->position_in_buffer = 0;

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
