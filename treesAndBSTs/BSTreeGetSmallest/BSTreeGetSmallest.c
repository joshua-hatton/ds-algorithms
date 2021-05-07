// Written by Joshua Hatton (z5215045) on 7/5/21 

#include "BSTree.h"

#include <stdlib.h>

static BSTree doBSTreeGetSmallest(BSTree t, BSTree smallest);

// Returns a pointer to the node containing 
// the smallest value in the given BST.
BSTree BSTreeGetSmallest(BSTree t) {
	if (t == NULL) {
		return NULL;
	}

	BSTree smallest = t;
	smallest = doBSTreeGetSmallest(t->left, smallest);

	return smallest;
}

static BSTree doBSTreeGetSmallest(BSTree t, BSTree smallest) {
	if (t != NULL) {
		if (t->value < smallest->value) {
			smallest = t;
		}
		smallest = doBSTreeGetSmallest(t->left, smallest);
	}
	return smallest;
}
