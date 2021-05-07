// Written by Joshua Hatton (z5215045) on 7/5/21

#include <stdlib.h>

#include "tree.h"

// Returns height of the given tree.
int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    }

    int leftHeight = TreeHeight(t->left);
    int rightHeight = TreeHeight(t->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
