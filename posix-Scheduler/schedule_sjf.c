#include <limits.h>
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
	struct node *current = head;
	struct node *shortest = head;


	// Loop through the nodes, if you find one that is the next smallest, take note of the node and the one before and after it.
	// If we reach the end of the loop, run the smallest we found and remove it from the list
	while (head != NULL) {

            // special case, only one node
            if (head->next == NULL) {
                delete(&head, head->task);
                break;
            } 

	    if (current->task->burst < shortest->task->burst) {
    		shortest = current;
            }
	    current = current->next;

	    // reached the end of the list. remove the shortest from the list and start at the head again
	    if (current == NULL) {
	            run(shortest->task, shortest->task->burst);
                    delete(&head, shortest->task);
        	    current = head;
                    shortest = head;
    	    }
	}

}
