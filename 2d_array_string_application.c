/*다섯 개의 문자열을 입력 받아 char 5행 80열 2 차원 배열에 순서대로
저장한 후 문자열 전체,첫 문자,마지막 문자를 출력하는
프로그램 작성하기*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char arr[5][80];
	int arr1[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%d번 문자열을 입력: ", i + 1);
		scanf("%s", arr[i]);
		arr1[i] = strlen(arr[i]);
	
	}
	for (int j = 0; j < 5; j++)
	{
		printf("str[%d] = ",j);
		for (int k = 0; k < arr1[j]; k++)
		{
			printf("%c", arr[j][k]);
		}
		printf(" ");
		printf("%c ", arr[j][0]);
		printf("%c", arr[j][arr1[j]-1]);
		printf("\n");


	}
	return 0;






}