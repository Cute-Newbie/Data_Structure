#include <stdio.h>
//��� ��� �Լ� 
void printArray(int* num, int count);
void printArray(int* num, int count)
{
	for (int i = 0; i < count; i++) {

		printf("%d ", num[i]);

	}



}
//��� ����Լ� 

//��� ���� ���� �Լ� 
void deleteData(int* arr, int* count, int index);
void deleteData(int* arr, int* count, int index) {

	if (index < *count)
	{
		(*count)--;
		for (int i = index; i < *count; i++)
		{
			arr[i] = arr[i + 1];

		}

	}
	else
		return;


}
// ��� ���� �߰� �Լ�
void addData(int* arr, int* count, int index, int data);
void addData(int* arr, int* count, int index, int data) {

	if (index < *count)
	{
		for (int i = *count; i > index; i--) {
			arr[i] = arr[i-1];

		}
		arr[index] = data;
		(*count)++;



	}
	else {
		return;
	}

}



int main(void)
{
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int count = 10;
	printArray(num, count);
	printf("\n");
	deleteData(num, &count, 5);
	printArray(num, count);
	printf("\n");
	addData(num, &count, 5, 6);
	printArray(num, count);
	return 0;





}