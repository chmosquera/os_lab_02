#include "schedulers.h"

struct node * head = NULL;
struct node * tail = NULL;

// add a task to the list 
void add(char *name, int priority, int burst) {

	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1->name = name;
	t1->tid = 0; // what should this be?
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

	//loop through tasks
	while (head != NULL) {
		temp = head;
		Task * highest = head->task;

		//find highest priority task
		while (temp != NULL) {

			//10 is highest priority, 1 is lowest
			if (temp->task->priority > highest->priority) {
				highest = temp->task;
			}
			temp = temp->next;
		}
		
		//run and remove from list
		run(highest, highest->burst);
		delete(&head, highest);
	}
}