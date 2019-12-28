//
// Created by YUJiehu on 2019-05-29.
//

#include "tree.h"



struct Node {
    struct Node *left;
    struct Node *right;
    int data;
};


TreeNode createTreeNode(int data) {
    TreeNode newTreeNode = malloc(sizeof(struct Node));
    if (newTreeNode != NULL) {
        newTreeNode->right = NULL;
        newTreeNode->left = NULL;
        newTreeNode->data = data;
    }

    return newTreeNode;
}


bool searchTree(TreeNode treeNode, int data) {

    if(treeNode == NULL) {
        return false;
    } else {

        bool result = false;

        if(data > treeNode->data) {
            result = searchTree(treeNode->right,data);
        }else if (data < treeNode->data) {
            result = searchTree(treeNode->left,data);
        }else {
            result = true;
        }

        return result;
    }
}




TreeNode insertTreeNode(TreeNode treeNode, int data) {

    if (treeNode == NULL) {
        treeNode = createTreeNode(data);
    } else {
        if (data > treeNode->data) {

            treeNode->right = insertTreeNode(treeNode->right, data);

        } else if (data < treeNode->data) {

            treeNode->left = insertTreeNode(treeNode->left, data);

        } else {

            return treeNode;
        }
    }
    return treeNode;
}

//
void printPreTreeNode(TreeNode treeNode) {

    if(treeNode!=NULL) {
        printf("%d \n",treeNode->data);
        printPreTreeNode(treeNode->left);
        printPreTreeNode(treeNode->right);
    }
}

//          2
//      1           3
//  null, null null    null
void printMidTreeNode(TreeNode treeNode) {

    // treeNode 1
    if(treeNode!=NULL) {
        printMidTreeNode(treeNode->left);
        printf("%d \n",treeNode->data);
        printMidTreeNode(treeNode->right);
    }
}

void printPostTreeNode(TreeNode treeNode) {

    if(treeNode!=NULL) {
        printPostTreeNode(treeNode->left);
        printPostTreeNode(treeNode->right);
        printf("%d \n",treeNode->data);
    }
}


int heightTreeNode(TreeNode treeNode) {

    if (treeNode == NULL) {
        return 0;
    }else {

        int leftHeight = heightTreeNode(treeNode->left);
        int rightHeight = heightTreeNode(treeNode->right);
        if (leftHeight >= rightHeight) {
            return leftHeight + 1;
        }else {
            return rightHeight + 1;
        }
    }
}


TreeNode mostLeftTreeNode(TreeNode treeNode) {
    if (treeNode == NULL) {
        return treeNode;
    } else {
        if (treeNode->left!=NULL) {
            return mostLeftTreeNode(treeNode->left);
        } else {
            return treeNode;
        }
    }
}

int treeData(TreeNode treeNode) {
    if (treeNode!=NULL) {
        return treeNode->data;
    } else {
        return 0;
    }
}

