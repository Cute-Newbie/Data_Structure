#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
struct _node {

	int data;
	Node* next;

};

typedef struct _queue {

	Node* head;
	Node* tail;

}Queue;

// createQueue Function 
int createQueue(Queue* qp);
int createQueue(Queue* qp)
{
	qp->head = (Node*)malloc(sizeof(int));
	if (qp->head == NULL)
		free(qp->head);
		return 0;
	qp->tail = (Node*)malloc(sizeof(int));
	if (qp->tail == NULL)
	{
		free(qp->tail);
		return 0;

	}	
	else
	{
		qp->head->next = qp->tail;
		qp->tail->next = qp->tail;
		return 1;
	}
	

}
//create Queue Function ends here 

//isQueueEmpty Function
int isQueueEmpty(const Queue* qp);
int isQueueEmpty(const Queue* qp)
{
	if (qp == NULL)
	{
		return 0;
	}
	if (qp->head->next = qp->tail)
	{
		return 1;
	}
	return 0;
}
//isQueueEmpty Function ends here 

//enqueue Function
int enqueu(Queue* qp, int enquedata);
int enqueu(Queue* qp, int enquedata)
{
	Node* newp; 
	Node* curp;
	if (qp == NULL)
	{
		return 0;
	}

	newp = (Node*)malloc(sizeof(Node));
	if (newp == NULL)
	{
		return 0;
	}
	
	curp = qp->head;
	while (curp->next != qp->tail)
	{
		curp = curp->next;

	}
	curp->next = newp;
	newp->next = qp->tail;
	newp->data = enquedata;
	return 1;
}
//encQueue Function ends here 

//dequeue Function
int dequeue(Queue* qp, int* dequeData);
int dequeue(Queue* qp, int* dequeData)
{
	Node* curp;
	if (qp == NULL)
	{
		return 0;
	}
	
	if (isQueueEmpty(qp) == 1)
	{
		return 0;
	}
	else
	{
		*dequeData = qp->head->next->data;
		curp = qp->head->next;
		qp->head->next = qp->head->next->next;
		free(curp);
		return 1;
	}
}
// dequeue Function ends here 

// printQueue Function
void printQueue(Queue* qp);
void printQueue(Queue* qp)
{
	
	Node* curp;
	if (qp == NULL)
	{
		return;
	}
	if (isQueueEmpty(qp) == 1)
	{
		return;
	}
	curp = qp->head->next;
	while (curp != qp->tail)
	{
		print("%d\n", curp->data);
		curp = curp->next;
	}
	printf("\n\n");
	return;

}
//print Queue Function ends here 

//destroyQueue Function
void destroyQueue(Queue* qp);
void destroyQueue(Queue* qp)
{
	Node* curp;
	Node* nextp;
	if (qp == NULL)
	{
		return;
	}

	curp = qp->head->next;
	while (curp != qp->tail)
	{
		nextp = curp->next;
		free(curp);
		curp = nextp;
	}
	free(qp->head);
	free(qp->tail);
	qp->head = NULL;
	qp->tail = NULL;
	return;

}
//destroyQueue Function ends here 

int main(void)
{

	return 0;
}