#include "msq_tape.h"
#include "msq.h"

msq_tape * msq_tape_create(uint nb_channels, uint length, uint nb_read_heads)
{
    msq_tape * tape = msq_malloc(sizeof(*tape), 0);
    tape->buffer = msq_malloc(sizeof(*tape->buffer)*nb_channels, 0);
    for (int i = 0; i < nb_channels; i++)
        tape->buffer[i] = msq_malloc(sizeof(*tape->buffer[i])*length, 0);
    tape->length = length;
    tape->nb_read_heads = nb_read_heads;
    tape->write_head_position = 0;
    tape->nb_channels = nb_channels;
    tape->read_head_positions = msq_malloc(sizeof(*tape->read_head_positions)*nb_read_heads ,0);
    for (int i = 0; i < nb_read_heads; i++)
        tape->read_head_positions[i] = 0;
    return tape;
}

void msq_tape_set_read_positions(msq_tape *tape, uint * read_head_positions)
{
    for(int i = 0; i < tape->nb_read_heads; i++)
        tape->read_head_positions[i] = read_head_positions[i];
}
void msq_tape_set_read_position(msq_tape *tape, uint position, uint index)
{
    tape->read_head_positions[index] = position;
}

void msq_tape_seek(msq_tape *tape, int seek, uint index)
{
    tape->read_head_positions[index] += seek;
}

void msq_tape_set_write_position(msq_tape *tape, uint position)
{
    tape->write_head_position = position;
}

void msq_tape_write(msq_tape *tape, int ** data_to_write, uint length)
{
    for(int i = 0; i < tape->nb_channels; i++)
        for(int j = 0; j < length; j++)
            tape->buffer[i][(j+tape->write_head_position)%tape->length] = data_to_write[i][j]; // this could be optimised further
    tape->write_head_position = (tape->write_head_position + length)%tape->length;
}

void msq_tape_write_from_interleaved(msq_tape *tape, int * data_to_write, unsigned int length)
{
    for(int i = 0; i < tape->nb_channels; i++)
        for(int j = 0; j < length; j++)
            tape->buffer[i][(j+tape->write_head_position)%tape->length] = data_to_write[j*tape->nb_channels + i]; // this could be optimised further
    tape->write_head_position = (tape->write_head_position + length)%tape->length;
}

int ** msq_tape_read(msq_tape *tape, uint length, uint read_head_index)
{
    int ** new_buffer = msq_malloc(sizeof(*new_buffer), 0);
    for (int i = 0; i < tape->nb_channels; i++)
        new_buffer[i] = msq_malloc(sizeof(*new_buffer[i])*length, 0);

    for (int i = 0; i < tape->nb_channels; i++)
        for (int j = 0; j < length; j++)
            new_buffer[i][j] = tape->buffer[i][(tape->read_head_positions[read_head_index] + j)%tape->length]; // this could be optimised further

    tape->read_head_positions[read_head_index] = (tape->read_head_positions[read_head_index] + length)%tape->length;
    return new_buffer;
}