// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdlib.h>

#include "tree.h"

static int treeSize(Tree t);

// Determines if a tree is perfectly balanced.
bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) {
		return true;
	}
	if (abs(treeSize(t->left) - treeSize(t->right)) > 1) {
		return false;
	}
	return TreeIsPerfectlyBalanced(t->left) && 
		   TreeIsPerfectlyBalanced(t->right);
}

// Returns size of a tree.
static int treeSize(Tree t) {
	if (t == NULL) {
		return 0;
	}
	return 1 + treeSize(t->left) + treeSize(t->right);
}
