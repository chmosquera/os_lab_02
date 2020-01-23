#include "schedulers.h"

struct node * heads[10] = {NULL};
struct node * tails[10] = {NULL};

// add a task to the list 
void add(char *name, int priority, int burst) {

	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1->name = name;
	t1->tid = 0; // what should this be?
	t1->priority = priority;
	t1->burst = burst;
	

	// create the node and assign its task
	struct node * n1 = insert(&(tails[priority]), t1);

	// if no tails, assign as tails
	if (heads[priority] == NULL) {
		heads[priority] = n1;
	}

	// this node is the new heads of the list
	tails[priority] = n1;
}

// invoke the scheduler
void schedule() {
	struct node *temp;
	int j;

	//loop through tasks. 10 is highest priority, 1 is lowest
	for (j = 9; j >= 0; j--) {
		struct node * head = heads[j+1];
		temp = head;

		//run all tasks in current priority
		while (temp != NULL) {
			run(temp->task, temp->task->burst);
			temp = temp->next;
		}
	}
}
