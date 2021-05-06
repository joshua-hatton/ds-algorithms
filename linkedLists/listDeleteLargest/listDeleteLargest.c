// Written by Joshua Hatton (z5215045) on 6/5/21

#include "list.h"

// Deletes largest value in a linked list of positive
// integers, and returns this value. Only first instance
// of value is deleted.
int listDeleteLargest(List l) {
	Node curr = l->head;
	Node largest = l->head;
	int largestValue = curr->value;
	Node beforeLargest = NULL;

	while (curr != NULL && curr->next != NULL) {
		if (curr->next->value > largestValue) {
			largestValue = curr->next->value;
			largest = curr->next;
			beforeLargest = curr;
		}
		curr = curr->next;
	}

	if (beforeLargest != NULL) {
		beforeLargest->next = largest->next;
	} else {
		l->head = largest->next;
	}

	free(largest);
	return largestValue;
}
