#include "schedulers.h"

struct node * head = NULL;
struct node * tail = NULL;

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

	// if no tail, assign as tail
	if (head == NULL) {
		head = n1;
	}

	// this node is the new head of the list
	tail = n1;
}

// invoke the scheduler
void schedule() {
	struct node *temp;
	temp = head;

	while (temp != NULL) {
		run(temp->task, temp->task->burst);
		temp = temp->next;
	}
}
