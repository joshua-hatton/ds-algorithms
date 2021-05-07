// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdlib.h>

#include "BSTree.h"

// Returns the depth of the node containing
// the given key in the tree. If it does not
// exist, -1 is returned.
int BSTreeNodeDepth(BSTree t, int key) {
	if (t == NULL) {
		return -1;
	}

	if (key < t->value) {
		int depth = BSTreeNodeDepth(t->left, key);
		return (depth == -1 ? -1 : depth + 1);
	} else if (key > t->value) {
		int depth = BSTreeNodeDepth(t->right, key);
		return (depth == -1 ? -1 : depth + 1);
	}

	return 0;
}
