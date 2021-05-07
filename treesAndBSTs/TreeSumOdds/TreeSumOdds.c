// Written by Joshua Hatton (z5215045) on 7/5/21
// Completed under time constraints

#include <stdlib.h>

#include "tree.h"

static int doTreeSumOdd(Tree t, int sum);

// Returns sum of all odd values.
int TreeSumOdds(Tree t) {
	return doTreeSumOdd(t, 0);
}

static int doTreeSumOdd(Tree t, int sum) {
	if (t == NULL) {
		return sum;
	}
	if (abs(t->value) % 2 == 1) {
		sum += t->value;
	}
	sum = doTreeSumOdd(t->left, sum);
	sum = doTreeSumOdd(t->right, sum);
	return sum; 
}
