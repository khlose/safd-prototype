/*
 * buffer.h
 *
 *  Created on: Sep 26, 2017
 *      Author: spinkoh
 */
#include <stdint.h>

#ifndef BUFFER_H_
#define BUFFER_H_

#define SUCCESS 0x00
#define BUFFER_AVAILABLE SUCCESS
#define BUFFER_FULL 0x01
#define BUFFER_EMPTY 0x02
#define FAILED 0xFF
#define SIZE 200

typedef struct triplet {
	float x;
	float y;
	float z;
} triplet;

typedef struct triple_ring_buffer {
	float tripletBuffer[3][SIZE];
	uint16_t head;
	uint16_t tail;
} triple_ring_buffer;

void init_buffer(triple_ring_buffer* buffer);
int add(triple_ring_buffer* buffer,float x, float y, float z);
int fetch(triple_ring_buffer* buffer, triplet* xyzTriplet);
int buffer_status(triple_ring_buffer* buffer);

#endif /* BUFFER_H_ */
