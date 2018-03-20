#ifndef EDF_H
#define EDF_H

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"


void DEBUG(struct Task t);
//void EDF();
struct Schedule *EDF(struct Task tl[], int num_task, int sim_time);

#endif
