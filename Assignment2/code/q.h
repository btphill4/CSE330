#include <stdlib.h>
#include "TCB.h"

struct qNode {	//Struct for elements of queue
	int value;
	struct qNode *prev;
	struct qNode *next;

};


struct Queue{	//Struct of Queue containing the head and num in queue
	struct TCB_t* head;	//Head pointer
	int count;

};

void Init_Q(struct Queue *q){
	q->head = NULL;
	q->count = 0;

}

void addQ(struct Queue *q, TCB_t *item)
{
	if (q->head == NULL){
		q->head = item;
		q->head->next = item;
		q->head->prev = item;
		q->count = 1;
	} else {
		struct TCB_t *end = q->head->prev;	//Pointer to the last node
		item->next = q->head;			//Old head becomes items next
		item->prev = end;			//Old end becomes item's prev
		q->head->prev = item;
		end->next = item;
		q->count++;
	}
}

struct TCB_t* delQ(struct Queue *q){
	struct TCB_t *t;

	t = q->head;
	t->next = NULL;
	t->prev = NULL;
	if((q->head->next == q->head) && (q->head->prev == q->head)){ //Remove head and set everything to null and 0
		q->head = NULL;
		q->count = 0;

	} else { //Remove head and shift nodes
		q->head->prev = q->head->next;
		q->head->next = q->head->prev;
		q->head = q->head->next;
		q->count--;

	}


return t;
}

void RotateQ(struct Queue *q){
	if(q->count > 1){
		addQ(q, delQ(q));
	}

}
