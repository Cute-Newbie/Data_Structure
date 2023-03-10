#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICLES 50

typedef struct GraphNode {
	int ver;
	struct GraphNode* next;
}GraphNode;


typedef struct GraphType {
	int n;
	GraphNode* arr[MAX_VERTICLES];
}GraphType;


//initGraph Function
void initGraph(GraphType* graph);
void initGraph(GraphType* graph)
{
	for (int i = 0; i < MAX_VERTICLES; i++)
	{
		graph->arr[i] = NULL;

	}
	graph->n = 0;

}

//insertVertex Function 
void insertVertex(GraphType* graph, int data);
void insertVertex(GraphType* graph, int data)
{

	if (graph->n + 1 > MAX_VERTICLES)
	{
		return;
	}
	graph->n++;

}
//insertVertex Function ends here


//insertEdge Function 
void insertEdge(GraphType* graph, int start, int end);
void insertEdge(GraphType* graph, int start, int end)
{

	GraphNode* new_node;

	new_node = (GraphNode*)malloc(sizeof(GraphNode));
	new_node->ver = end;
	new_node->next = graph->arr[start];
	graph->arr[start] = new_node;



}
//insertEdge Function ends here 

//printGraph Function
void printGraph(GraphType* graph);
void printGraph(GraphType* graph)
{
	//GraphNode* curp;
	int end = graph->n;
	for (int i = 0; i < end; i++)
	{
		GraphNode* curp = graph->arr[i];
		while (curp != NULL)
		{
			printf("%d ", curp->ver);
			curp = curp->next;
		}
		printf("\n");
	}

}

int main(void)
{
	GraphType* graph;
	graph = (GraphType*)malloc(sizeof(GraphType));
	initGraph(graph);

	for (int i = 0; i < 4; i++)
	{
		insertVertex(graph, i);
	}

	insertEdge(graph, 0, 1);
	insertEdge(graph, 1, 0);
	insertEdge(graph, 0, 2);
	insertEdge(graph, 2, 0);
	insertEdge(graph, 0, 3);
	insertEdge(graph, 3, 0);
	insertEdge(graph, 1, 2);
	insertEdge(graph, 2, 1);
	insertEdge(graph, 2, 3);
	insertEdge(graph, 3, 2);
	printGraph(graph);
	free(graph);

	return 0;
}