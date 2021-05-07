// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

static BSTree newNode(int val);

// Inserts a given value into a BST if it
// does not already exist, and returns root.
// Rebalancings are not performed.
BSTree BSTreeInsert(BSTree t, int val) {
	if (t == NULL) {
		return newNode(val);
	} else if (val < t->value) {
		t->left = BSTreeInsert(t->left, val);
	} else if (val > t->value) {
		t->right = BSTreeInsert(t->right, val);
	}
	return t;
}

// Creates a new node (leaf)
static BSTree newNode(int val) {
	BSTree newNode = malloc(sizeof(*newNode));
	if (newNode == NULL) {
		fprintf(stderr, "Could not allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	newNode->value = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
