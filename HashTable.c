#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10

typedef struct _node{

	int key;
    struct _node* next;
}Node;

typedef struct _changing_hash {

	Node* hash;
	int size;
	int dataCnt;

}CHash;

//createHash Function
int createHash(CHash* hsp, int size);
int createHash(CHash* hsp, int size)
{
	hsp = (CHash*)malloc(sizeof(CHash));
	if (hsp == NULL)
	{
		return 0;
	}
	
	hsp->hash = (Node*)calloc(hsp->size, sizeof(Node));
	if (hsp->hash != NULL)
	{
		hsp->size = size;
		hsp->dataCnt = 0;
		return 1;
	}
	else // hash  동적 할당 실패 경우
	{
		return 0;
	}
	return 1;
}
//createHash Function ends here 

//
int hashFunction(CHash* hsp, int key);
int hashFunction(CHash* hsp, int key)
{
	int value = 0;
	if (hsp == NULL)
	{
		return 0;
	}
	while (key>0)
	{
		value += key % 10;
		key /= 10;
	}
	printf("key sum = %d\n", value);
	return value % hsp->size;
}
//hashFunction ends here 

//hashInput Functinon
int hashInput(CHash* hsp, int iData);
int hashInput(CHash* hsp, int iData)
{   
	int hashValue;
	Node* np;
	

	if (hsp == NULL)
	{
		return 0;
	}

	hashValue = hashFunction(hsp, iData);
	np = (Node*)malloc(sizeof(int));
	if(np == NULL)
	{
		return 0;
	}
	np->key = iData;
	np->next = hsp->hash[hashValue].next;
	hsp->hash[hashValue].next = np;
	hsp->dataCnt++;
	return 1;

}
// hashInput Function ends here 

//hashSearch Function
int hashSearch(CHash* hsp, int sData);
int hashSearch(CHash* hsp, int sData)
{    
	int hashValue;
	Node* sp;
	
	if (hsp == NULL)
	{
		return -1;
	}

	hashValue = hashFunction(hsp, sData);
	sp = hsp->hash[hashValue].next;
	while (sp != NULL)
	{
		if (sp->key == sData)
			return hashValue;
		sp = sp->next;
	}
	return -1;

}
//hashSearch Function ends here 

//hashDelete Function
int hashDelete(CHash* hsp, int* data);
int hashDelete(CHash* hsp, int* data)
{
	if (hsp == NULL)
	{
		return 0;
	}
	if (hashSearch(hsp, data) == -1)
	{
		return 0;
	}
	Node* sp;
	Node* pre;
	int hashValue;

	hashValue = hashFunction(hsp, data);
	pre = &hsp->hash[hashValue];
	sp = pre->next;
	while (sp != NULL)
	{
		if (sp->key == data)
		{
			pre->next == sp->next;
			free(sp);
			hsp->dataCnt--;
			return 1;
		}
		else
		{
			pre = sp;
			sp = sp->next;
		}
	
	
	}
	return 0;
	
}
//hashDelete Function ends here 

//destroyHash Function 
void destroyHash(CHash* hsp);
void destroyHash(CHash* hsp)
{
	int len = hsp->size;
	Node* curp;
	Node* nextp;

	if (hsp == NULL)
	{
		return;
	}


	for (int i = 0; i < len; i++)
	{
		curp = hsp->hash[i].next;
		while (curp != NULL)
		{
			nextp = curp->next;
			free(curp);
			curp = nextp;
		}
		free(hsp->hash);


	}
	hsp->hash = NULL;
	hsp->size = 0;
	hsp->dataCnt = 0;

	return;


}



int main(void)
{

	return 0;
}