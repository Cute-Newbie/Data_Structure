#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// int num[10]의 배열을 1-20 사이의  난수로 초기화 한 후 
// 배열 내의 데이터에서 사용자가 지정한 정수를 검색하여
// 배열 내에 저장된 위치를 출력한다.(5회 반복)

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
		printf("검색할 정수를 입력하세요 ");
		scanf("%d", &num);
		res = searcher(arr, 10,num);
		if (res == -1) 
		{ 
			printf("%d는 존재하지 않습니다\n", num);

		}
		else 
		{
			printf("%d는 %d에 존재합니다.\n", num, res + 1);
		}




	}



	return 0;


}



