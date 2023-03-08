#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

//Defining Heap
typedef struct _heap{

    int data[MAX_LEN];
    int size;
}Heap;

//Heap 초기화 함수
Heap *heapInit(Heap *hp);
Heap *heapInit(Heap *hp)
{
    hp = (Heap*)malloc(sizeof(Heap));
    hp->size = 0;
    return hp;
}


//heapAdd Function
void heapAdd(Heap *hp,int data);
void heapAdd(Heap *hp,int data)
{
    int i;
    int temp;
    ++hp->size;
    hp->data[hp->size] = data;
    i = hp->size;
    while(i/2>0)
    {
        if(hp->data[i] > hp->data[i/2])
        {
            temp = hp->data[i/2];
            hp->data[i/2] = hp->data[i];
            hp->data[i] = temp;
            i /= 2;

        }
        
        else
        {
            break;
        }
    }
    return;
}//headAdd Function ends here 


//return bigger
int bigger(int a, int b);
int bigger(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
//bigger Function ends here 

//heapDelete Function
void heapDelete(Heap* hp);
void heapDelete(Heap* hp)
{
    //--hp->size;
    hp->data[1] = hp->data[hp->size];
    hp->data[hp->size] = 0;
    --hp->size;
    int i = 1;
    int temp;
    int bigger;
    while(i<=hp->size)
    {
        if(hp->data[i]<hp->data[2*i] || hp->data[i]<hp->data[2*i])
        {
            if(hp->data[2*i] > hp->data[2*i+1])
            {
                temp = hp->data[i];
                hp->data[i] = hp->data[2*i];
                hp->data[2*i] = temp; 
                i  = 2*i;


            }

            else
            {

                 temp = hp->data[i];
                hp->data[i] = hp->data[2*i+1];
                hp->data[2*i+1] = temp; 
                i  = 2*i;

            }

            return;





        }
        return;


    }
    



}



int main(void)
{
    Heap* h = NULL;
	h = heapInit(h);

	heapAdd(h, 3);
	heapAdd(h, 5);
	heapAdd(h, 1);
	heapAdd(h, 23);
	heapAdd(h, 9);
    heapDelete(h);

	for (int i = 1; i <= h->size; i++) {
		printf("%d ", h->data[i]);
	}

    return 0;


}