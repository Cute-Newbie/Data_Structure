#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//stack
// size; ������ ���� ũ��
// push: ���ÿ��� �����͸� �ִ� �۾�
// pop: ���ÿ��� �����͸� ������ �۾�
// top: ���ÿ��� ������� �������� ��ġ

struct _stack {

	int* stack; /*stack���� ���Ǵ� ���� �Ҵ� �迭�� ����Ű�� 
	������ ����*/ 
	int size; /*������ ũ��*/
	int top; /*������ ��,�ⱸ ��ġ ���� ����*/

};
typedef struct _stack Stack;

//creatStack Function
int createStack(Stack* sp, int size);
int createStack(Stack* sp, int size)
{
	if (sp == NULL)
	{
		return 0;
	}
	
	sp->stack = (int*)malloc(sizeof(int)*size);
	if (sp->stack != NULL)
	{
		sp->size = size;
		sp->top = 0;
		return 1;
	}
	else
	{
		return 0;
	}
	
}
//createStack Function ends here

//isStackFull Function
int isStackFull(Stack* sp);
int isStackFull(Stack* sp)
{
	if (sp->top == sp->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//isStackFull Function ends here

//isStackEmpty Function
int isStackEmpty(Stack* sp);
int isStackEmpty(Stack* sp)
{
	if (sp == NULL)
	{
		return 0;
	}
	if (sp->top == 0)
	{
		return 1;
	}
	else
		return 0;
	}
//isStackEmpty Function ends here

//push Function
int push(Stack* sp, int inData);
int push(Stack* sp, int inData)
{
	if (sp == NULL)
	{
		return 0;
	}
	if (isStackFull(sp) == 1)
	{
		return 0;
	}
	else
	{
		sp->stack[sp->top] = inData;
		sp->top += 1;
		return 1;
	}

}
//push Function ends here

//pop Function
int pop(Stack* sp, int* popData);
int pop(Stack* sp, int* popData)
{
	if (isStackEmpty(sp) == 1)
	{
		return 0;
	}
	else 
	{
		sp->top -= 1;
		*popData = sp->stack[sp->top];
		return 1;
	}
	
}
//pop Function ends here

//printStack Function
void printStack(const Stack* sp);
void printStack(const Stack* sp)
{
	int num = sp->top;
	if (sp == NULL)
	{
		return;
	}

	for (int i = num; i >= 0; i--)
	{
		printf("%d\n", sp->stack[i]);
	}
	printf("\n");
	return;

}
//printStack Function ends here

//destoryStack Function
void destroyStack(Stack* sp);
void destroyStack(Stack* sp)
{
	if (sp == NULL)
	{
		return;
	}
	if (sp->stack != NULL)
	{
		free(sp->stack);
		
		sp->size = 0;
		sp->stack = NULL;
		sp->top = 0;
	}
	
}
//destoryStack Function ends here




//Test Function
int main(void)
{

	
	return 0;
}