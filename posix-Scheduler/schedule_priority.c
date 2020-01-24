#include "schedulers.h"

struct node * heads[11] = {NULL};
struct node * tails[11] = {NULL};
int tid_counter = 0;

// add a task to the list 
void add(char *name, int priority, int burst) {
        __sync_fetch_and_add(&tid_counter, TID_ADD_BY);

	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1->name = name;
	t1->tid = tid_counter;
        t1->priority = priority;
	t1->burst = burst;

        int idx = 0;
        // special case for priority > 10
        if (priority > 10)                
            idx = 10;
        else 
            idx = priority - 1;

	// create the node and assign its task
        struct node * n1 = insert(&(tails[idx]), t1);

	// if no head, assign as head
	if (heads[idx] == NULL) {
		heads[idx] = n1;
	}

	// this node is the new tail of the list
	tails[idx] = n1;
}

// invoke the scheduler
void schedule() {
	struct node *temp;
	int j;

	//loop through tasks. 10 is highest priority, 1 is lowest
	for (j = 10; j >= 0; j--) {
		struct node * head = heads[j];
		temp = head;

		//run all tasks in current priority
		while (temp != NULL) {
			run(temp->task, temp->task->burst);
			temp = temp->next;
		}
	}
}
