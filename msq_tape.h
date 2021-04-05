typedef struct {
    int * buffer;
    unsigned int nb_channels;
    unsigned int length;
    unsigned int * read_head_positions;
    unsigned int nb_read_heads;
    unsigned int write_head_position;
} msq_tape;

msq_tape * msq_tape_create(unsigned int nb_channels, unsigned int length, unsigned int nb_read_heads);
void msq_tape_set_read_positions(msq_tape *tape, unsigned int * read_head_positions);
void msq_tape_set_read_position(msq_tape *tape, unsigned int position, unsigned int index);
void msq_tape_seek(msq_tape *tape, int seek, unsigned int index);
void msq_tape_set_write_position(msq_tape *tape, unsigned int position);
void msq_tape_write(msq_tape *tape, int * data_to_write, unsigned int length);
void msq_tape_write_from_interleaved(msq_tape *tape, int * data_to_write, unsigned int length);
int * msq_tape_read(msq_tape *tape, unsigned int length, unsigned int read_head_index);
