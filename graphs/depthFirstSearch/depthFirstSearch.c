// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void doDFS(Graph g, int v, bool *visited);

// Performs a DFS using recursion. Prints out
// vertices as they are visited.
void depthFirstSearch(Graph g, int src) {
	bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
	doDFS(g, src, visited);
	free(visited);
}

static void doDFS(Graph g, int v, bool *visited) {
	printf("%d ", v);
	visited[v] = true;
	for (int w = 0; w < GraphNumVertices(g); w++) {
		if (!visited[w] && GraphIsAdjacent(g, v, w)) {
			doDFS(g, w, visited);
		}
	}
}
