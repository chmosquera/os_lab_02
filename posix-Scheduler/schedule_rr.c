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
	int quant_time = 10;
	int i = 0;

	//loop through tasks
	while (head != NULL) {
		temp = head;

		//run each task until done or time up
		while (temp != NULL) {
			int remain_time = temp->task->burst - i * quant_time;
			//fprintf(stderr, "Task %s remaining time: %d\n", temp->task->name, remain_time);
			//compare burst time remaining
			if (remain_time <= quant_time) {
				run(temp->task, remain_time);
				delete(&head, temp->task);
			} else {
				//run for quantum time
				run(temp->task, quant_time);
			}
			temp = temp->next;
		}
		i++;
	}
}