// Written by Joshua Hatton (z5215045) on 5/5/21

#include "list.h"

// Returns the number of duplicate elements
// in an ordered linked list.
int numDupesInOrderedList(List l) {
	int dupes = 0;
	Node curr = l->head;
	while (curr != NULL && curr->next != NULL) {
		if (curr->value == curr->next->value) {
			dupes++;
		}
		curr = curr->next;
	}

	return dupes;
}

