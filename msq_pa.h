#define SAMPLE_FORMAT paInt32
#define BIG_BUFFER_LENGTH 10 // Seconds 

typedef struct {
    int ** b;
    unsigned int size;
    unsigned int nb_channels;
} msq_buffer;

msq_buffer* msq_buffer_create(unsigned int size, unsigned int nb_channels);
void msq_buffer_free(msq_buffer* buff);
void msq_buffer_set(msq_buffer* buff, int * b, unsigned int channel);
void msq_buffer_set_from_interleaved(msq_buffer* buff, int * b, unsigned int channels);

void msq_pa_print_err(int err);
void msq_audio_init();
void msq_audio_set_device();
void msq_audio_read_buffer_in_default_device();
void msq_audio_close();
void msq_list_audio_devices();