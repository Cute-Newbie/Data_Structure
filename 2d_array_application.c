//int num[3][4]�� �����Ͽ� �� ���� 1-20������ ������ �ʱ�ȭ
// �� ���� ���� �� ���� �հ� , ���� �հ踦 ����ϴ� ���α׷��ۼ�
#include <stdio.h>
#include <stdlib.h>
void row_adder(int (*p)[4]);
void row_adder(int(*p)[4])
{
	
	for (int i = 0; i < 3; i++)
	{
		printf("%5d�� ", i);
		int res = 0;
		for (int j = 0; j < 4; j++)
		{   
			printf("%2d ",p[i][j]);
			res += p[i][j];
		}
		printf("%2d���� �� %2d", i, res);
		printf("\n");


	}
	printf("���� ��: ");
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
	// �迭 ���� �ʱ�ȭ
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