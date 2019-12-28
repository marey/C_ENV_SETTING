//
// Created by YUJiehu on 2019-05-29.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef COMP9024_19T2_TREE_H
#define COMP9024_19T2_TREE_H

#endif //COMP9024_19T2_TREE_H

typedef struct Node *TreeNode;

TreeNode insertTreeNode(TreeNode treeNode, int data);

void printPreTreeNode(TreeNode treeNode);

void printMidTreeNode(TreeNode treeNode) ;

void printPostTreeNode(TreeNode treeNode);

int heightTreeNode(TreeNode treeNode);

bool searchTree(TreeNode treeNode, int data);

TreeNode mostLeftTreeNode(TreeNode treeNode);


int treeData(TreeNode treeNode);
