#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICLES 50
typedef struct GraphType GraphType;
struct GraphType {

	int n;
	int adg_mat[MAX_VERTICLES][MAX_VERTICLES];

};


//initFunction
void init(GraphType* graph);
void init(GraphType* graph)
{
	graph->n = 0;
	for (int i = 0; i < MAX_VERTICLES; i++)
	{
		for (int j = 0; j < MAX_VERTICLES; j++)
		{
			graph->adg_mat[i][j] = 0;

		}
	}
	return;
	
}
//initFunction ends here 

//insertVertex
void insertVertex(GraphType* graph, int data);
void insertVertex(GraphType* graph, int data)
{
	if (graph->n + 1 > MAX_VERTICLES)
	{
		return;
	}
	graph->n++;
	return;

}


//insertEdge 
void insertEdge(GraphType* graph, int start, int end);
void insertEdge(GraphType* graph, int start, int end)
{
	if (graph == NULL)
		return;

	graph->adg_mat[start][end] = 1;
	graph->adg_mat[end][start] = 1;

}

//printGraph
void printGraph(GraphType* graph);
void printGraph(GraphType* graph)
{
	int end = graph->n;
	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < end; j++)
		{
			printf("%d ", graph->adg_mat[i][j]);
		}
		printf("\n");
	}
	
}


//deleteVertex

//deleteEdge//

//isempty

//adjacen

//destroygraph 



int main(void)
{
	GraphType* graph;
	graph = (GraphType*)malloc(sizeof(GraphType));
	init(graph);

	for (int i = 0; i < 4; i++)
	{
		insertVertex(graph, i);
	}

	insertEdge(graph, 0, 1);
	insertEdge(graph, 0, 2);
	insertEdge(graph, 0, 3);
	insertEdge(graph, 1, 2);
	insertEdge(graph, 2, 3);
	printGraph(graph);
	free(graph);

	return 0;
}