// Written by Joshua Hatton (z5215045) on 7/5/21
// Completed under time constraints

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static int doReachable(Graph g, int v, bool *visited);

// Returns the number of vertices reachable
// from a source vertex.
int numReachable(Graph g, int src) {
	bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
	int reach = doReachable(g, src, visited);
	free(visited);
	return reach;
}

static int doReachable(Graph g, int v, bool *visited) {
	visited[v] = true;
	int reach = 1;
	for (int w = 0; w < GraphNumVertices(g); w++) {
		if (!visited[w] && GraphIsAdjacent(g, v, w)) {
			reach += doReachable(g, w, visited);
		}
	}
	return reach;
}
