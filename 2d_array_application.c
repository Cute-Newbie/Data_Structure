//int num[3][4]를 선언하여 각 방을 1-20사이의 난수로 초기화
// 각 방의 내용 및 행의 합계 , 열의 합계를 출력하는 프로그램작성
#include <stdio.h>
#include <stdlib.h>
void row_adder(int (*p)[4]);
void row_adder(int(*p)[4])
{
	
	for (int i = 0; i < 3; i++)
	{
		printf("%5d행 ", i);
		int res = 0;
		for (int j = 0; j < 4; j++)
		{   
			printf("%2d ",p[i][j]);
			res += p[i][j];
		}
		printf("%2d행의 합 %2d", i, res);
		printf("\n");


	}
	printf("열의 합: ");
	for (int i = 0; i < 4; i++)
	{
		int res1 = 0;
		for (int j = 0; j < 3; j++)
		{
			//printf("%2d ", p[j][i]);
			res1 += p[j][i];
		}
		
		printf("%2d ",res1);


	}


}




int main(void)
{   

	int arr[3][4];
	int num;
	// 배열 난수 초기화
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			num = rand() % 20 + 1;
			arr[i][j] = num;

		}


	}
	row_adder(arr);

}