#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//2d-array-input
void inputarray(int(*p)[4], int row);
void inputarray(int(*p)[4], int row)
{
	int num;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d행 %d열 숫자 입력\n", i, j);
			scanf("%d", &p[i][j]);

		}


	}

}


// 2d-array-print
void printarray(int(*p)[4], int row);
void printarray(int(*p)[4], int row)
{
	for (int i = 0; i < row; i++) 
	{   
		printf("%d행 ", i);
		for (int j = 0; j < 4; j++) 
		{
			
			printf("%d ", p[i][j]);

		}
		printf("\n");

	}

}

//mainfunction

int main(void)
{
	int arr[3][4];
	int row;
	row = sizeof(arr) / sizeof(arr[0]);

	inputarray(arr, row);
	printarray(arr, row);
	getchar();
	return 0;



}

