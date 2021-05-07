// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// Returns the number of edges on the shortest path
// between two vertices. If no path, return -1.
// Implemented using BFS.
int shortestDistance(Graph g, int src, int dest) {
	int nV = GraphNumVertices(g);
	bool *visited = calloc(nV, sizeof(bool));
	visited[src] = true;
	
	int *pred = malloc(nV * sizeof(int));
	for (Vertex v = 0; v < nV; v++) {
		pred[v] = -1;
	}
	pred[src] = src;

	Queue q = QueueNew();
	QueueEnqueue(q, src);

	bool found = false;
	while (!QueueIsEmpty(q) && !found) {
		Vertex v = QueueDequeue(q);
		if (v == dest) {
			found = true;
		}
		for (Vertex w = 0; w < nV; w++) {
			if (!visited[w] && GraphIsAdjacent(g, v, w)) {
				visited[w] = true;
				QueueEnqueue(q, w);
				pred[w] = v;
			}
		}
	}

	int count = 0;
	if (!found) {
		count = -1;
	} else {
		Vertex v = dest;
		while (v != src) {
			v = pred[v];
			count++;
		}
	}

	free(visited);
	free(pred);
	QueueFree(q);
	return count;
}
