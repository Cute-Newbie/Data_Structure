#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// int num[10]�� �迭�� 1-20 ������  ������ �ʱ�ȭ �� �� 
// �迭 ���� �����Ϳ��� ����ڰ� ������ ������ �˻��Ͽ�
// �迭 ���� ����� ��ġ�� ����Ѵ�.(5ȸ �ݺ�)

//Print Array
void printarray(int* arr, int len);
void printarray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);

	}
	return;
}

//Index Searcher 
int searcher(int* arr, int len, int num);
int searcher(int* arr, int len, int num)
{
	for (int i = 0; i < len; i++) 
	{
		if (arr[i] == num)
		{
			return i;

		}
	}
	return -1;

}

//main function 
int main(void) 
{

	int arr[10];
	int random;
	int num;
	int res;

	//  array_setting
	for (int i = 0; i < 10; i++)
	{
		random = rand() % 19 + 1;
		arr[i] = random;

	}
	// print_array
	printarray(arr, 10);
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("�˻��� ������ �Է��ϼ��� ");
		scanf("%d", &num);
		res = searcher(arr, 10,num);
		if (res == -1) 
		{ 
			printf("%d�� �������� �ʽ��ϴ�\n", num);

		}
		else 
		{
			printf("%d�� %d�� �����մϴ�.\n", num, res + 1);
		}




	}



	return 0;


}



