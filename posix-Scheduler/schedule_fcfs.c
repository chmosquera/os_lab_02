#include "schedulers.h"
#include "list.h"

struct node * head = NULL;
struct node * tail = NULL;

// add a task to the list 
void add(char *name, int priority, int burst) {

	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1 = {
		.name = name,
		.tid = 0, // what should this be?
		.priority = priority,
		.burst = burst
	};

	// create the node and assign its task
	struct node n1;
	*n1.task = t1;
	n1.next = NULL;
	insert(last_node, n1);

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