//
// Created by Rui.Mu on 2019-01-30.
// TODO
// 1.re balance
// 2.check balance nodes
// 3.check balance level
// 4.Problem Set 5  week5a No.5
// 5.Problem Set 5  week5a No.6
//

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#ifndef COMP9024_TEST_TREE_H
#define COMP9024_TEST_TREE_H

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

// tree node
typedef struct TreeNode *Tree;

/**
 * create new tree
 * @return new tree
 */
Tree newTree(void);

/**
 * insert val to tree
 * @return new tree
 */
Tree insertTree(Tree, int);

/**
 * insert val at root
 * @return
 */
Tree insertAtRoot(Tree,int);

/**
 * insert value to AVL tree
 * @return tree node
 */
Tree insertAVLTree(Tree, int);

/**
 * insert value to Splay tree
 * @return
 */
Tree insertSplayTree(Tree, int);

/**
 * delete val from tree
 * @return delete tree
 */
Tree deleteTree(Tree,int);

/**
 * get height of tree
 * @return height
 */
int heightTree(Tree);

/**
 * get width tree
 * @return width
 */
int widthTree(Tree);

/**
 * get number of tree nodes
 * @return number of tree nodes
 */
int countNodes(Tree);

/**
 * get number of tree leaves
 * @return
 */
int countLeaf(Tree);


/**
 * get number of tree odd nodes
 * @return
 */
int countOdds(Tree);

/**
 * count odder level nodes
 * @return count
 */
int countOdderLevelNodes(Tree);

/**
 * search val in tree
 * @return return target tree
 */
Tree searchTree(Tree, int);

/**
 * rotate right
 * @return new tree
 */
Tree rotateRight(Tree);

/**
 * rotate left
 * @return new tree
 */
Tree rotateLeft(Tree);

/**
 * print by pre order
 * @param tree tree node
 */
void printPreOrderTree(Tree);

/**
 * print by pre order
 * @param tree tree node
 */
void printPreOrderTreeIndex(Tree);

/**
 * print by in order
 * @param tree tree node
 */
void printInOrderTree(Tree);

/**
 * print by post order
 * @param tree tree node
 */
void printPostOrderTree(Tree);

/**
 * print level order tree
 */
void printLevelOrderTree(Tree);

/**
 * print height add node values
 */
void printHeightAddNodeValues(Tree);

/**
 * join two tree
 * max(key(t1)) < min(key(k2))
 *
 * @return
 */
Tree joinTrees(Tree,Tree);

/**
 * check number of nodes in a tree is balanced
 * @return
 */
bool isBalancedByNumberOfNodes(Tree);

/**
 * re balance
 * @param tree tree
 * @return
 */
Tree reBalance(Tree);

/**
 * show tree
 * @param t display
 */
void showTree(Tree t);

#endif //COMP9024_TEST_TREE_H
