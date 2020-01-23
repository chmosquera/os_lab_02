/**
 * list data structure containing the tasks in the system
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
struct node * insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
