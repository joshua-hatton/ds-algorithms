// Written by Joshua Hatton (z5215045) on 7/5/21
// Completed under time constraints

#include "list.h"

static Node listAppend(Node head, Node add);
static bool inList(List l, int value);

// Takes in two lists (representing sets) and returns
// a new list representing their union.
List listSetUnion(List s1, List s2) {
	List uni = newList();
	for (Node curr = s1->head; curr != NULL; curr = curr->next) {
		Node add = newNode(curr->value);
		uni->head = listAppend(uni->head, add);
	}
	for (Node curr = s2->head; curr != NULL; curr = curr->next) {
		if (!inList(uni, curr->value)) {
			Node add = newNode(curr->value);
			uni->head = listAppend(uni->head, add);
		}
	}
	
	return uni;
}

// Appends a node to a list using recursion.
static Node listAppend(Node head, Node add) {
	if (head == NULL) {
		return add;
	}
	head->next = listAppend(head->next, add);
	return head;
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
