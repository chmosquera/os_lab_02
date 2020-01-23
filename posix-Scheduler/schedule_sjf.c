#include <limits.h>
#include "schedulers.h"

struct node * head = NULL;

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

	// if no head, assign as head
	if (head == NULL) {
		head = n1;
	}
}

// invoke the scheduler
void schedule() {
	struct node *current = head;
	struct node *prev;
	prev = NULL;

	struct node *shortest = head;
	struct node *prev_shortest;
	prev_shortest = NULL;


	// Loop through the nodes, if you find one that is the next smallest, take note of the node and the one before and after it.
	// If we reach the end of the loop, run the smallest we found and remove it from the list
	while (current != NULL) {
		if (current->task->burst < shortest->task->burst) {
			prev_shortest = prev;
			shortest = current;
		}
		prev = current;
		current = current->next;

		// reached the end of the list. remove the shortest from the list and start at the head again
		if (current == NULL) {
			if (shortest == head) {
				head = shortest->next;
			}
			else {
				prev_shortest->next = shortest->next;
			}
			free(shortest);			
			current = head;							
		}
	}

	run(current->task, current->task->burst);
}