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

	// if no tail, assign as tail
	if (heads[priority] == NULL) {
		heads[priority] = n1;
	}

	// this node is the new head of the list
	tails[priority] = n1;
        
}

// invoke the scheduler
void schedule() {
	struct node *temp;
	int quant_time = 10;

	//loop through tasks
        int j;
        for (j = 9; j >= 0; j--) {
	    int i = 0;
            struct node * head = heads[j];
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
}
