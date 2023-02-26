#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int palindrom_checker(char *word);
int palindrom_checker(char *word)
{
	int size;
	size = strlen(word);

	int* arr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++) 
	{
		arr[i] = word[i];

	}


	for (int i = 0; i < size/2; i++)
	{

		if (arr[i] != arr[size - 1 - i])
		{
			return -1;
		}

	}
	free(arr);
	return 1;


}




int main(void)
{

	char word[30];
	int a;
	scanf("%s", &word);
	//scanf("%s", &word);
	while (strcmp(word,"end")!=0)
	{
		
		a = palindrom_checker(word);
		if (a == 1) 
		{
			printf("%s 회문입니다.\n", word);
		}
		else
		{
			printf("회문이 아닙니다.\n");
		}
		scanf("%s", &word);
		

	}

	return 0;
}