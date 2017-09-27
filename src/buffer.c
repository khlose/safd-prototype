/*
 * buffer.c
 *
 *  Created on: Sep 26, 2017
 *      Author: spinkoh
 */

#include "buffer.h"

void init_buffer(triple_ring_buffer* buffer)
{
	memset(buffer->x, 0, sizeof(buffer->x));
	memset(buffer->y, 0, sizeof(buffer->y));
	memset(buffer->z, 0, sizeof(buffer->z));

	buffer->head = 0;
	buffer->tail = 1;
	return;
}

int add(triple_ring_buffer* buffer,float x, float y, float z)
{

	return SUCCESS;
}

int fetch(triple_ring_buffer* buffer, triplet* xyzTriplet)
{

	return SUCCESS;
}
