/*�ټ� ���� ���ڿ��� �Է� �޾� char 5�� 80�� 2 ���� �迭�� �������
������ �� ���ڿ� ��ü,ù ����,������ ���ڸ� ����ϴ�
���α׷� �ۼ��ϱ�*/
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
		printf("%d�� ���ڿ��� �Է�: ", i + 1);
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