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
#define FAILED 0xFF
#define SIZE 200

typedef struct triple_ring_buffer {
	float x[SIZE];
	float y[SIZE];
	float z[SIZE];
	uint16_t head;
	uint16_t tail;
} triple_ring_buffer;
typedef struct triplet {
	float x;
	float y;
	float z;
} triplet;

void init_buffer(triple_ring_buffer* buffer);
int add(triple_ring_buffer* buffer,float x, float y, float z);
int fetch(triple_ring_buffer* buffer, triplet* xyzTriplet);


#endif /* BUFFER_H_ */
