// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdio.h>

#include "BSTree.h"

// Prints out values of a BST in postfix order.
void BSTreePostfix(BSTree t) {
	if (t == NULL) {
		return;
	} 
	BSTreePostfix(t->left);
	BSTreePostfix(t->right);
	printf("%d ", t->value);
}
