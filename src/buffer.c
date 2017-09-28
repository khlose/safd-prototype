/*
 * buffer.c
 *
 *  Created on: Sep 26, 2017
 *      Author: spinkoh
 */

#include "buffer.h"
#include <string.h>

void init_buffer(triple_ring_buffer* buffer)
{
	//Initialize the arrays to 0

	memset(buffer->tripletBuffer, 0 ,sizeof(float) * 3 * SIZE);

	buffer->head = 0;
	buffer->tail = 1;
	return;
}

int add(triple_ring_buffer* buffer,float x, float y, float z)
{
	if(buffer_status(buffer) == BUFFER_AVAILABLE)
	{
		buffer->tripletBuffer[0][buffer->tail] = x;
		buffer->tripletBuffer[1][buffer->tail] = y;
		buffer->tripletBuffer[2][buffer->tail] = z;

		buffer->tail = (buffer->tail + 1) % SIZE;
		return SUCCESS;
	}

	return FAILED;
}

int fetch(triple_ring_buffer* buffer, triplet* xyzTriplet)
{
	if(buffer_status(buffer) == BUFFER_AVAILABLE)
	{
		xyzTriplet->x = buffer->tripletBuffer[0][buffer->head];
		xyzTriplet->y = buffer->tripletBuffer[1][buffer->head];
		xyzTriplet->z = buffer->tripletBuffer[2][buffer->head];

		buffer->head = (buffer->head + 1) % SIZE;

		return SUCCESS;
	}

	return FAILED;
}

int buffer_status(triple_ring_buffer* buffer)
{
	if((buffer->tail + 1) % SIZE == buffer->head) return BUFFER_FULL;
	if((buffer->head + 1) % SIZE == buffer->tail) return BUFFER_EMPTY;
	else return BUFFER_AVAILABLE;
}
