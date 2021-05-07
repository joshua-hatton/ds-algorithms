// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// Performs BFS on a graph starting at a given 
// source vertex. Prints out visited vertices.
void breadthFirstSearch(Graph g, int src) {
	bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
	visited[src] = true;

	Queue q = QueueNew();
	QueueEnqueue(q, src);
	
	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);
		printf("%d ", v);
		for (int w = 0; w < GraphNumVertices(g); w++) {
			if (!visited[w] && GraphIsAdjacent(g, v, w)) {
				visited[w] = true;
				QueueEnqueue(q, w);
			}
		}
	}

	free(visited);
	QueueFree(q);
}
