//
//
// use tree structure to map vertices and url
// graph structure could be alternated by tree structure
//
// AVLTree.c - implementation to AVLTree ADT
// zid:5144248
// Written by Rui.Mu, 2019-01-29.

#include "AVLTree.h"


/**
 * create new node by item and index
 * @param it item
 * @param index index
 * @return new tree node
 */
Tree newNode(Item it, int index) {
    Tree new = malloc(sizeof(struct Node));
    assert(new != NULL);
    // copy string to data
    strcpy(data(new), it);
    // set index
    indexTree(new) = index;
    // set value of page rank
    new->valueOfPageRank = 0.0;
    // set number of out degrees
    new->numberOfOutDegrees = 0;
    left(new) = degrees(new) = right(new) = NULL;
    return new;
}

/**
 * create new tree
 * @return null
 */
Tree newTree() {
    return NULL;
}

/**
 * free memory associated with Tree
 * @param t tree
 */
void freeTree(Tree t) {
    if (t != NULL) {
        // free left
        freeTree(left(t));
        // free right
        freeTree(right(t));
        // free degrees
        freeTree(degrees(t));
        // free current node
        free(t);
    }
}

/**
 * show tree
 * @param t tree
 * @param depth depth
 */
void showTreeR(Tree t, int depth) {
    // check null
    if (t != NULL) {
        showTreeR(right(t), depth + 1);
        // print tab
        for (int i = 0; i < depth; i++)
            putchar('\t');            // TAB character
        printf("%s\n", data(t));
        // print left
        showTreeR(left(t), depth + 1);
    }
}

/**
 * print the tree
 * @param t tree
 */
void showTree(Tree t) {
    // from start to print
    showTreeR(t, 0);
}

/**
 * get height of tree
 * @param t tree
 * @return height
 */
int heightTree(Tree t) {

    // not yet implemented
    if (t == NULL)
        return 0;
    else {
        int leftHeight = 1 + heightTree(left(t));
        int rightHeight = 1 + heightTree(right(t));
        // return max left right
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
}

/**
 * count number of tree nodes
 * @param t tree
 * @return number of tree nodes
 */
int numTreeNodes(Tree t) {
    if (t == NULL)
        return 0;
    else
        return 1 + numTreeNodes(left(t)) + numTreeNodes(right(t));
}

/**
 * search index of tree node
 * @param t tree
 * @param it item
 * @return data
 */
int searchTreeIndex(Tree t, Item it) {
    if (t == NULL)
        return -1;

    int result = strcmp(it, data(t));
    if (result < 0)
        return searchTreeIndex(left(t), it);
    else if (result > 0)
        return searchTreeIndex(right(t), it);
    else                                 // it == data(t)
        return t->index;
}

/**
 * search tree node by index
 * @param t tree
 * @param it item
 * @return data
 */
Tree searchTree(Tree t, Item it) {
    if (t == NULL)
        return NULL;
    int result = strcmp(it, data(t));
    if (result < 0)
        return searchTree(left(t), it);
    else if (result > 0)
        return searchTree(right(t), it);
    else
        return t;
}

/**
 * search tree node by index
 * @param t tree
 * @param index index
 * @return data
 */
Tree searchTreeByIndex(Tree t, int index) {
    // if t is null, return null
    if (t == NULL)
        return NULL;
    // if less than, move to left
    if (index < t->index)
        return searchTreeByIndex(left(t), index);
    else if (index > t->index)
        // if more than move to right
        return searchTreeByIndex(right(t), index);
    else
        return t;
}

/**
 * search data by index
 * @param t tree
 * @param index index
 * @return data
 */
char *searchTreeValueByIndex(Tree t, int index) {
    // if t is null, return null
    if (t == NULL)
        return NULL;
    // if less than, move to left
    if (index < t->index)
        return searchTreeValueByIndex(left(t), index);
    else if (index < t->index)
        // if more than move to right
        return searchTreeValueByIndex(right(t), index);
    else
        return t->data;
}

/**
 * set number of out degrees
 * @param t tree
 * @param it item
 * @param numberOfOutDegrees number of out degrees
 */
void setTreeNumberOfOutDegrees(Tree t, Item it, int numberOfOutDegrees) {

    Tree tree = searchTree(t, it);
    // check null
    if (tree != NULL) {
        // set number of out degree
        tree->numberOfOutDegrees = numberOfOutDegrees;
    }
}

/**
 * get number of out degree of node
 * @param t tree
 * @param it item
 * @return number of out degrees
 */
int getTreeNumberOfOutDegrees(Tree t, Item it) {
    int result = 0;
    // tree node
    Tree tree = searchTree(t, it);
    if (tree != NULL) {
        result = tree->numberOfOutDegrees;
    }
    return result;
}

/**
 * set page rank value for node
 * @param t tree
 * @param index index
 * @param valueOfPageRank page rank value
 */
void setTreeValueOfPageRank(Tree t, Item it, double valueOfPageRank) {

    Tree tree = searchTree(t, it);
    if (tree != NULL) {
        tree->valueOfPageRank = valueOfPageRank;
    }
}

/**
 * set page rank value for node
 * @param t tree
 * @param index index
 * @param valueOfPageRank page rank value
 */
void setTreeValueOfPageRankByIndex(Tree t, int index, double valueOfPageRank) {
    // search node
    Tree tree = searchTreeByIndex(t, index);
    // check null
    if (tree != NULL) {
        tree->valueOfPageRank = valueOfPageRank;
    }
}

/**
 * get page rank value of tree node
 * @param t tree
 * @param it item
 * @return value of page rank
 */
double getTreeValueOfPageRank(Tree t, Item it) {
    double result = 0.0;
    Tree tree = searchTree(t, it);
    if (tree != NULL) {
        result = tree->valueOfPageRank;
    }
    return result;
}

/**
 * insert data with index
 * @param t tree
 * @param it data
 * @param index index
 * @return
 */
Tree insertTree(Tree t, Item it, int index) {
    // if t is null create new node
    if (t == NULL)
        // create new node
        t = newNode(it, index);
    else {
        // check it and data
        int result = strcmp(it, data(t));
        // if equal, return and parent to check balance
        if (result == 0) {
            return t;
        }
        // if less than node ,left
        if (result < 0) {
            left(t) = insertTree(left(t), it, index);
            // if more than node, right
        } else if (result > 0) {
            right(t) = insertTree(right(t), it, index);
        }
        // check height of left and right
        // if left height more than right height
        int leftHeight = heightTree(left(t));
        int rightHeight = heightTree(right(t));
        if (leftHeight - rightHeight > 1) {
            // check value
            //              15
            //        10         16
            //      9    12
            // insert 13
            // left(t) rotate left and then rotate right
            if (strcmp(it, data(left(t))) > 0) {
                left(t) = rotateLeft(left(t));
            }
            t = rotateRight(t);
        } else if (rightHeight - leftHeight > 1) {
            if (strcmp(it, data(right(t))) < 0) {
                right(t) = rotateRight(right(t));
            }
            t = rotateLeft(t);
        }
    }

    // return node
    return t;
}

/**
 * add index
 * @param t
 * @param item
 */
void addTreeIndex(Tree t, Item item) {
    Tree tree = searchTree(t, item);
    // add index
    if (tree != NULL) {
        tree->index++;
    }
}

/**
 * rotate to right
 * @param n1 n1 current node
 * @return result of rotate
 */
Tree rotateRight(Tree n1) {
    if (n1 == NULL || left(n1) == NULL)
        return n1;
    // left node
    Tree n2 = left(n1);
    // change left of n1
    left(n1) = right(n2);
    // change right of n2
    right(n2) = n1;
    // return n2
    return n2;
}

/**
 * rotate right
 * @param n2 n2 node
 * @return result
 */
Tree rotateLeft(Tree n2) {
    // check null
    if (n2 == NULL || right(n2) == NULL)
        return n2;
    // n1 node
    Tree n1 = right(n2);
    // n2 node
    right(n2) = left(n1);
    // left of n1
    left(n1) = n2;
    // return n1
    return n1;
}