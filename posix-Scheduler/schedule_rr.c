#include "schedulers.h"

struct node * head = NULL;
struct node * tail = NULL;
tid_counter = 0;

// add a task to the list 
void add(char *name, int priority, int burst) {
        __sync_fetch_and_add(&tid_counter, TID_ADD_BY);

	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1->name = name;
	t1->tid = tid_counter; // what should this be?
	t1->priority = priority;
	t1->burst = burst;

	// create the node and assign its task
	struct node * n1 = insert(&tail, t1);

	// if no head, assign as head
	if (head == NULL) {
		head = n1;
	}

	// this node is the new tail of the list
	tail = n1;
}

// invoke the scheduler
void schedule() {
	struct node *temp;
	int quant_time = 10;

	//loop through tasks
	while (head != NULL) {
		temp = head;

		//run each task until done or time up
		while (temp != NULL) {
			//compare burst time remaining
			if (temp->task->burst <= quant_time) {
				run(temp->task, temp->task->burst);
				delete(&head, temp->task);
			} else {
				//run for quantum time
				run(temp->task, quant_time);
				temp->task->burst -= quant_time;
			}
			temp = temp->next;
		}
	}
}
