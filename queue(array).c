#include <stdio.h>
#include <stdlib.h>
typedef struct _queue {

	int *queue;
	int size;
	int front;
	int rear;

}Queue;

// createQue Function
int createQueue(Queue* qp, int size);
int createQueue(Queue* qp, int size)
{
	if (qp == NULL)
	{
		return 0;
	}

	qp->queue = (int*)calloc(size, sizeof(int));
	if (qp->queue != NULL)
	{
		qp->size = size;
		qp->front = 0;
		qp->rear = 0;
		return 1;
	}
	else
		return 0;
}
//createQue Function ends here 

// isQueueEmpty Function
int isQueueEmpty(const Queue* qp);
int isQueueEmpty(const Queue* qp)
{
	if (qp == NULL)
		return 0;
	if (qp->front == qp->rear)
	{
		return 1;
	}
	else
		return 0;
}
// isQueueEmpty Function ends here

//isQueueFull Function
int isQueueFull(const Queue* qp);
int isQueueFull(const Queue* qp)
{
	int front, rear,size;
	front = qp->front;
	rear = qp->rear;
	size = qp->size;
	if (qp == NULL)
		return 0;

	if (front == (rear + 1) % size)
	{
		return 1;
	}
	else
		return 0;
}
//isQueueFull Function ends here

//enqueue Function 
int enqueue(Queue* qp, int enqueData);
int enqueue(Queue* qp, int enqueData)
{
	if (qp == NULL)
	{
		return 0;
	}
	if (isQueueFull(qp) == 1)
	{
		return 0;
	}

	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return 1;
}
// enqueue Function ends here 

//dequeue Function 
int dequeue(Queue* qp, int* dequeData);
int dequeue(Queue* qp, int* dequeData)
{
	if (qp == NULL)
	{
		return 0;
	}

	if (isQueueEmpty(qp) == 1)
	{
		return 0;
	}

	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;
	
	return 1;

}
//deque Function ends here 

//printQueue Function 
void printQueue(const Queue* qp);
void printQueue(const Queue* qp)
{
	if (qp == NULL)
	{
		return;
	}

	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("%d\n", qp->queue[i]);
	}
	printf("\n");
	return;
}
//printQueue Function ends here 

//destroyQueue Function

void destroyQueue(Queue* qp);
void destroyQueue(Queue* qp)
{
	if (qp == NULL)
	{
		return 0;
	}

	free(qp->queue);
	qp->queue = NULL;
	qp->size = 0;
	qp->rear = 0;
	qp->front = 0;
	return;

}
//destroyQueue Function ends here.


int main(void)
{

	return 0;
}