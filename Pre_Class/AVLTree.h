// AVLTree.h - Interface to AVLTree ADT
// zid:5144248
// Written by Rui.Mu, 2019-01-29.

#ifndef COMP9024_AVLTREE_H
#define COMP9024_AVLTREE_H

// data
#define data(tree)  ((tree)->data)
// left node
#define left(tree)  ((tree)->left)
// right node
#define right(tree) ((tree)->right)
// index of node
#define indexTree(tree) ((tree)->index)
// degrees of node
#define degrees(tree) ((tree)->outDegrees)

#include "Common.h"

/**
 * structure of true node
 */
typedef struct Node {
    // data
    char data[20];
    // index map to data
    int index;
    // number of out degrees
    int numberOfOutDegrees;
    // value of page rank
    double valueOfPageRank;
    // left right out degrees
    struct Node *left, *right, *outDegrees;
} Node;

/**
 * item item is just a key
 */
typedef char *Item;

/**
 * point of tree node
 */
typedef struct Node *Tree;

/**
 * create new node
 * @return new node
 */
Tree newTree();

/**
 * free the whole tree
 */
void freeTree(Tree);

/**
 * show the whole tree
 */
void showTree(Tree);

/**
 * search index of node
 * @return node index
 */
int searchTreeIndex(Tree, Item);

/**
 * check whether an item is in a Tree
 * @return tree node
 */
Tree searchTree(Tree, Item);

/**
 * search url node by index
 * @return
 */
char *searchTreeValueByIndex(Tree,int);

/**
 * get height of the tree
 * @return tree height
 */
int  heightTree(Tree);

/**
 * count number of tree nodes
 * @return number of tree nodes
 */
int  numTreeNodes(Tree);

/**
 * insert a new item into a Tree with index
 * @return
 */
Tree insertTree(Tree, Item, int);

/**
 * rotate right
 * @return result
 */
Tree rotateRight(Tree);

/**
 * roate left
 * @return result
 */
Tree rotateLeft(Tree);

/**
 * add index
 */
void addTreeIndex(Tree, Item);

/**
 * set number of out degrees
 */
void setTreeNumberOfOutDegrees(Tree, Item, int);

/**
 * get number of degree
 * @return number of degrees
 */
int getTreeNumberOfOutDegrees(Tree, Item);

/**
 * set page rank value for node
 */
void setTreeValueOfPageRank(Tree, Item, double);

/**
 * set page rank value for node
 */
void setTreeValueOfPageRankByIndex(Tree, int, double);

/**
 * get value of page rank from node
 * @return page rank value
 */
double getTreeValueOfPageRank(Tree , Item);

#endif //COMP9024_AVLTREE_H
