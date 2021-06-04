//Where we put semaphore data stuff
#include "threads.h"

struct Queue RunQ;

typedef struct semaphmore{
	int val;
	struct Queue *q;

} semaphore;


void InitSem(semaphore *sema, int val){
	sema->q = (struct Queue*)malloc(sizeof(struct Queue));
	Init_Q(sema->q);
	sema->val = val;

	return;
}

void P(semaphore *sema){

	sema->val = sema->val - 1;
	if(sema->val <= 0){
		//Blocks the process in the queue 
		struct TCB_t *temp;
		//delQ(&RunQ);
		
		//addQ(sema->q, temp);
		
		//Swap with head
		swapcontext((&temp->context), (&RunQ.head->context));
		
	}
	
	return;
}


void V(semaphore *sema){

	sema->val = sema->val + 1;
	if(sema->val <= 0){
		//Take a PCB out of emaphore q and adds to RunQ
		struct TCB_t *temp;
		//temp = delQ(RunQ);
		
		//addQ(sem, temp);
	
	}
	//Call yield
	yield();
	
	return;
}
