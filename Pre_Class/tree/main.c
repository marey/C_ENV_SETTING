//
// Created by YUJiehu on 2019-05-29.
//
#include "tree.h"

int main() {


    TreeNode root = NULL;

    root = insertTreeNode(root,10);

    root = insertTreeNode(root,2);

    root = insertTreeNode(root,15);
    root = insertTreeNode(root,40);

    int height = heightTreeNode(root);

    printMidTreeNode(root);

    printf(" tree height is : %d",height);


    if( searchTree(root,40)) {
        printf("found \n");
    }else {
        printf("not found \n");
    }

    //     10
    //   2    15
    //            40


    TreeNode leftTreeNoe = mostLeftTreeNode(root);

    printf("most left tree node is : %d", treeData(leftTreeNoe));
}