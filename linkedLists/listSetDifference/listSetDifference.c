// Written by Joshua Hatton (z5215045) on 6/5/21

#include "list.h"

static bool inList(List l, int value);
static Node listAppend(Node head, Node add);

// Takes two lists (representing sets) and returns 
// a new list representing the set difference l1 - l2. 
List listSetDifference(List l1, List l2) {
	List diff = newList();
	Node curr = l1->head;
	while (curr != NULL) {
		if (!inList(l2, curr->value)) {
			Node add = newNode(curr->value);
			diff->head = listAppend(diff->head, add);
		}
		curr = curr->next;
	}

	return diff;
}

// Checks if a value is in a list.
static bool inList(List l, int value) {
	Node curr = l->head;
	while (curr != NULL) {
		if (curr->value == value) {
			return true;
		}
		curr = curr->next;
	}

	return false;
}

// Appends a node to a list using recursion.
static Node listAppend(Node head, Node add) {
	if (head == NULL) {
		return add;
	}
	head->next = listAppend(head->next, add);
	return head;
}
