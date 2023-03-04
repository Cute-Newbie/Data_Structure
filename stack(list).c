#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _stacknode Snode;
struct _stacknode
{
	int data;
	Snode *next;

};

typedef struct _stack Stack;
struct _stack
{

	Snode* head;
	Snode* tail;

};

//createStack Function
int createStack(Stack* sp);
int createStack(Stack* sp)
{
	if (sp == NULL)
		return 0;

	sp->head = (Snode*)malloc(sizeof(Snode));
	if (sp->head == NULL)
		free(sp->head);
		return 0;
	
		sp->tail = (Snode*)malloc(sizeof(Snode));
	if (sp->tail == NULL)
		free(sp->tail);
		return 0;

	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;
	return 1;

}
//create StackFunction ends here

//isStackEmpty Function
int isStackEmpty(Stack *sp);
int isStackEmpty(Stack* sp)
{
	if (sp == NULL)
	{
		return 0;
	}
	if (sp->head->next == sp->tail)
	{
		return 1;
	}
	else
		return 0;

}
//isStackEmpty Function ends here

//push Function
int push(Stack* sp, int pushData);
int push(Stack* sp, int pushData)
{
	Snode* nptr;
	if (sp == NULL)
		return 0;
	
	nptr = (Snode*)malloc(sizeof(Snode));
	
	if (nptr == NULL)
		return 0;

	else
	{
		nptr->next = sp->head->next;
		sp->head->next = nptr;
		nptr->data = pushData;
		return 1;
	}
	
}
//push Function ends here

//pop Function
int pop(Stack* sp, int* popData);
int pop(Stack* sp, int* popData)
{
	Snode* curp;
	if (sp == NULL)
		return 0;
	if (isStackEmpty(sp) == 1)
		return 0;
	else
	{
		curp = sp->head->next;
		*popData = curp->data;
		sp->head->next = sp->head->next->next;
		free(curp);
		return 1;

	}

}
//free curp ends here

//printStack Function
void printStack(Stack* sp);
void printStack(Stack* sp)
{
	Snode* curp;
	

	if (sp == NULL)
		return;
	if (isStackEmpty(sp) == 1)
		return;
	
	else
	{
		curp = sp->head->next;
		while (curp != sp->tail)
		{
			printf("%d" , curp->data);
			curp = curp->next;
		}


	}
	printf("\n");
	return;
}
//printStack Function ends here

//destoryStack Function
void destroyStack(Stack* sp);
void destroyStack(Stack* sp)
{
	Snode* curp;
	//Snode* np;

	if (sp == NULL)
		return 0;
	else 
	{
		//curp = sp->head->next;
		while (sp->head->next != sp->tail)
		{
			curp = sp->head->next;
			sp->head->next = sp->head->next->next;

			free(curp);
		}
		free(sp->head);
		free(sp->tail);
		sp->head = NULL;
		sp->tail = NULL;
	}
	return;
	
}
int main(void) 
{
	return 0;
}
//destroyStack ends here