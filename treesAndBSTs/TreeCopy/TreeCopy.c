// Written by Joshua Hatton (z5215045) on 7/5/21

#include "tree.h"

static Tree newNode(int value);

// Copies a tree up to a given depth.
// A negative depth results in an empty tree.
// A depth bigger than height of tree results in
// the entire tree.
Tree TreeCopy(Tree t, int depth) {
	if (t == NULL || depth < 0) {
		return NULL;
	}
	Tree copy = newNode(t->value);
	copy->left = TreeCopy(t->left, depth - 1);
	copy->right = TreeCopy(t->right, depth - 1);

	return copy;
}

static Tree newNode(int value) {
	Tree new = malloc(sizeof(*new));
	if (new == NULL) {
		fprintf(stderr, "Couldn't allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}
