#define SAMPLE_FORMAT paInt32
#define BIG_BUFFER_LENGTH 10 // Seconds 

void msq_pa_print_err(int err);
void msq_audio_init();
void msq_audio_set_device();
void msq_audio_read_buffer_in_default_device();
void msq_audio_close();
void msq_list_audio_devices();