#include "msq_tape.h"
#include "msq.h"
#include <stdlib.h>

msq_tape * msq_tape_create(uint nb_channels, uint length, uint nb_read_heads)
{
    msq_tape *tape = malloc(sizeof(*tape));
    tape->buffer = malloc(sizeof(*tape->buffer) * length * nb_channels);
    tape->length = length;
    tape->nb_read_heads = nb_read_heads;
    tape->nb_channels = nb_channels;
    tape->write_head_position = 0;
    tape->read_head_positions = malloc(sizeof(*tape->buffer) * nb_read_heads);
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

void msq_tape_write(msq_tape *tape, int * data_to_write, uint length)
{
    for(int i = 0; i < length * tape->nb_channels; i++)
        tape->buffer[(tape->write_head_position+i)] = data_to_write[i];
    tape->write_head_position = (tape->write_head_position + length)%(tape->length * tape->nb_channels);
}

int * msq_tape_read(msq_tape *tape, uint length, uint read_head_index)
{
    int *b = malloc(sizeof(*b) * length * tape->nb_channels);
    for (int i = 0; i < length * tape->nb_channels; i++)
        b[i] = tape->buffer[(tape->read_head_positions[read_head_index]+i)%(tape->length * tape->nb_channels)];
    tape->read_head_positions[read_head_index] = (tape->read_head_positions[read_head_index] + length * tape->nb_channels)%(tape->length * tape->nb_channels);
    return b;
}