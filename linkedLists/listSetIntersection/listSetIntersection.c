// Written by Joshua Hatton (z5215045) on 6/5/21

#include "list.h"

static bool inList(List l, int value);
static Node listAppend(Node head, Node add);

// Takes two lists (representing sets) and returns
// a new list that represents the intersection.
// Order is not taken into consideration.
List listSetIntersection(List s1, List s2) {
	List intersection = newList();
	Node curr = s1->head;
	while (curr != NULL) {
		if (inList(s2, curr->value)) {
			Node add = newNode(curr->value);
			intersection->head = listAppend(intersection->head, add);
		}
		curr = curr->next;
	}

	return intersection;
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
