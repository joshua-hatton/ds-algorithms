// Written by Joshua Hatton (z5215045) on 8/5/21

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

static bool dfsCycleCheck(Graph g, Vertex v, Vertex prev, bool *visited);

// Determines if a graph contains a cycle.
// Takes into consideration all components.
bool hasCycle(Graph g) {
	bool cycle = false;
	bool *visited = calloc(GraphNumVertices(g), sizeof(bool));

	for (Vertex v = 0; v < GraphNumVertices(g); v++) {
		if (!visited[v]) {
			if (dfsCycleCheck(g, v, v, visited)) {
				cycle = true;
			}
		}
	}
	
	free(visited);
	return cycle;
}

static bool dfsCycleCheck(Graph g, Vertex v, Vertex prev, bool *visited) {
	visited[v] = true;
	for (Vertex w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w)) {
			if (visited[w] && w != prev) {
				return true;
			} else if (!visited[w]) {
				if (dfsCycleCheck(g, w, v, visited)) {
					return true;
				}
			}
		}
	}
	return false;
}
