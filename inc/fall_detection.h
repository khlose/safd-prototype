/*
 * fall_detection.h
 *
 *  Created on: Sep 28, 2017
 *      Author: Station13
 */

#ifndef FALL_DETECTION_H_
#define FALL_DETECTION_H_

#include "buffer.h"
#define DELTA_T 1 //derived from sampling rate (ms)
#define EXCEED 0x01
#define BELOW 0x00


void compute_velocity(triplet* velocity2, triplet velocity1, triplet xyz1, triplet xyz2);
int compare_threshold(triplet velocity);

#endif /* FALL_DETECTION_H_ */
