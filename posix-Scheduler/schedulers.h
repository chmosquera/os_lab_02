#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "cpu.h"


#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#define TID_ADD_BY 1

extern int tid_counter;

// add a task to the list 
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();

#endif //SCHEDULER_H
