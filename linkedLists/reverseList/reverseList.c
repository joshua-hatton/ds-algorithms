// Written by Joshua Hatton (z5215045) on 5/5/21

#include <assert.h>
#include "list.h"

// Reverses a given singly linked list.
void listReverse(List l) {
	assert(l != NULL);
	Node prev = NULL;
	Node curr = l->head;
	Node next;
	while (curr != NULL) {
		if (curr->next == NULL) {
			l->head = curr;
		}
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}
