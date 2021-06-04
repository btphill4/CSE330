#include <stdlib.h>
#include "q.h"

struct Queue RunQ; //Global head pointer

void start_thread(void (*function)(void))
{
	int size = 8192;
	void *sptr = malloc(size);
	struct TCB_t *tcb = (struct TCB_t*) malloc(sizeof(struct TCB_t));
	init_TCB(tcb, function, sptr, size);
	addQ(&RunQ, tcb); //Add tcb to Queue 

}

void run()
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(RunQ.head->context));

}

void yield()
{
	RotateQ(&RunQ);
	//ucontext_t *prev = &(Ready
	//swapcontext(
}
