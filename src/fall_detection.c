/*
 * fall_detection.c
 *
 *  Created on: Sep 28, 2017
 *      Author: Station13
 */

#include "fall_detection.h"

void compute_velocity(triplet* velocity2, triplet velocity1, triplet xyz1, triplet xyz2)
{
	velocity2->x = (xyz2.x - xyz1.x) * DELTA_T * 9.8 + velocity1.x;
	velocity2->y = (xyz2.y - xyz1.y) * DELTA_T * 9.8 + velocity1.y;
	velocity2->z = (xyz2.z - xyz1.z) * DELTA_T * 9.8 + velocity1.z;
	return;
}


int compare_threshold(triplet velocity)
{
	if( velocity.x >= 1000 && velocity.z >= 1000)
		return EXCEED;
	else
		return BELOW;
}
