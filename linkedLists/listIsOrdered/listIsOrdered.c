// Written by Joshua Hatton (z5215045) on 4/5/21

#include <assert.h>
#include "list.h"

bool isOrdered(Node curr, bool ascend);

// Determines whether a linked list is sorted in either
// ascending or descending order. 
// An empty list is considered sorted.
bool listIsOrdered(List l) {
	assert(l != NULL);
	Node curr = l->head;
	if (curr == NULL) return true; 		// empty
	if (isOrdered(curr, true) || isOrdered(curr, false)) return true;
	return false;
}

bool isOrdered(Node curr, bool ascend) {
	int prevValue = curr->value;
	curr = curr->next;
	while (curr != NULL) {
		if (ascend) {
			if (curr->value < prevValue) return false;
		} else {
			if (curr->value > prevValue) return false;
		}
		prevValue = curr->value;
		curr = curr->next;
	}
	return true;
}
