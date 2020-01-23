#include "schedulers.h"

struct node * head1 = NULL;
struct node * head2 = NULL;
struct node * head3 = NULL;
struct node * head4 = NULL;
struct node * head5 = NULL;
struct node * head6 = NULL;
struct node * head7 = NULL;
struct node * head8 = NULL;
struct node * head9 = NULL;
struct node * head10 = NULL;

struct node * tail1 = NULL;
struct node * tail2 = NULL;
struct node * tail3 = NULL;
struct node * tail4 = NULL;
struct node * tail5 = NULL;
struct node * tail6 = NULL;
struct node * tail7 = NULL;
struct node * tail8 = NULL;
struct node * tail9 = NULL;
struct node * tail10 = NULL;


// add a task to the list 
void add(char *name, int priority, int burst) {
	// create the task
	struct task * t1 = malloc(sizeof(Task));
	t1->name = name;
	t1->tid = 0; // what should this be?
	t1->priority = priority;
	t1->burst = burst;

        struct node * head = NULL;
        struct node * tail = NULL;

        switch (priority) {
            case 1:
                head = head1;
                tail = tail1;
                break;
            case 2:
                head = head2;
                tail = tail2;
                break;
            case 3:
                head = head3;
                tail = tail3;
                break;
            case 4:
                head = head4;
                tail = tail4;
                break;
            case 5:
                head = head5;
                tail = tail5;
                break;
            case 6:
                head = head6;
                tail = tail6;
                break;
            case 7:
                head = head7;
                tail = tail7;
                break;
            case 8:
                head = head8;
                tail = tail8;
                break;
            case 9:
                head = head9;
                tail = tail9;
                break;
            case 10:
                head = head10;
                tail = tail10;
                break;
        }

        
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
                        //if they have the same priority, schedule using rr
                        else if (temp->task->priority == highest->priority) {

                        }
			temp = temp->next;
		}
		
		//run and remove from list
		run(highest, highest->burst);
		delete(&head, highest);
	}

}
