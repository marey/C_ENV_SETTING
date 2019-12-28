//
// Created by Rui.Mu on 2019-01-30.
//

#include "Tree.h"

// tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

/**
 * create new node
 * @return
 */
Tree newTree(void) {
    return NULL;
}

/**
 * create new node
 * @param val value
 * @return create new node
 */
Tree newNode(int val) {
    // apply memories
    Tree tree = malloc(sizeof(struct TreeNode));
    assert(tree != NULL);
    // copy data to tree
    data(tree) = val;
    // set left and right
    left(tree) = right(tree) = NULL;
    // return new tree
    return tree;
}

/**
 * insert value to tree
 * @param tree tree structure
 * @param val value
 * @return tree node
 */
Tree insertTree(Tree tree, int val) {
    // check tree is null
    if (tree == NULL) {
        // create new node
        tree = newNode(val);
    } else {
        // check result
        if (val < data(tree)) {
            // if val less than current data
            left(tree) = insertTree(left(tree), val);
        } else if (val > data(tree)) {
            // if val more than current data
            right(tree) = insertTree(right(tree), val);
        }
    }
    // return pointer of tree
    return tree;
}

/**
 * insert value to tree
 * @param tree tree structure
 * @param val value
 * @return tree node
 */
Tree insertAVLTree(Tree tree, int val) {
    // check tree is null
    if (tree == NULL) {
        // create new node
        tree = newNode(val);
    } else {
        // equal 0
        if (val != data(tree)) {
            // check result
            if (val < data(tree)) {
                // if val less than current data
                left(tree) = insertTree(left(tree), val);
            } else if (val > data(tree)) {
                // if val more than current data
                right(tree) = insertTree(right(tree), val);
            }

            // left height
            int leftHeight = heightTree(left(tree));
            int rightHeight = heightTree(right(tree));
            // check left height more than right height
            if (leftHeight - rightHeight > 1) {
                //          20
                //      15      25
                //   10
                //      insert 12
                // compare current node
                if (val > data(left(tree))) {
                    left(tree) = rotateLeft(left(tree));
                }

                // rotate right
                tree = rotateRight(tree);
            } else if (rightHeight - leftHeight > 1) {
                //          20
                //       15     25
                //             22
                //      insert 21
                // compare current and right
                if (val < data(right(tree))) {
                    right(tree) = rotateRight(right(tree));
                }
                // rotate right
                tree = rotateLeft(tree);
            }
        }
    }
    // return pointer of tree
    return tree;
}

/**
 * insert value to Splay tree
 * @return
 */
Tree insertSplayTree(Tree tree, int val) {
    // if tree is empty, then return new node containing item
    if (tree == NULL) {
        // create new node
        tree = newNode(val);
    } else if (val < data(tree)) {
        // get left tree
        Tree leftTree = left(tree);
        // check left node
        if (leftTree == NULL) {
            // create left node
            left(tree) = newNode(val);
        } else if (val < data(leftTree)) {
            // if left ,then rotate right
            left(leftTree) = insertSplayTree(left(leftTree), val);
            // rotate right
            tree = rotateRight(tree);
        } else if (val > data(leftTree)) {
            // if right ,then rotate left
            right(leftTree) = insertSplayTree(right(leftTree), val);
            // rotate left
            left(tree) = rotateLeft(left(tree));
        }

        // left ,then rotate right
        tree = rotateRight(tree);

    } else if (val > data(tree)) {
        // operate right
        Tree rightTree = right(tree);
        // check right
        if (rightTree == NULL) {
            // create new node
            right(tree) = newNode(val);
        } else if (val < data(rightTree)) {
            // left, then rotate right
            left(rightTree) = insertSplayTree(left(rightTree), val);
            // rotate right
            right(tree) = rotateRight(right(tree));
        } else if (val > data(rightTree)) {
            // right, then rotate left
            right(rightTree) = insertSplayTree(right(rightTree), val);
            // rotate left
            tree = rotateLeft(tree);
        }
        // rotate left
        tree = rotateLeft(tree);
    }
    // return tree
    return tree;
}

/**
 * insert val at root
 * @param tree tree
 * @param val value
 * @return new root
 */
Tree insertAtRoot(Tree tree, int val) {
    // new tree
    if (tree == NULL) {
        // return new node
        tree = newNode(val);
    } else if (val < data(tree)) {
        // return at root
        left(tree) = insertAtRoot(left(tree), val);
        // rotate right
        tree = rotateRight(tree);
    } else if (val > data(tree)) {
        // return at root
        right(tree) = insertAtRoot(right(tree), val);
        // rotate left
        tree = rotateLeft(tree);
    }
    // return tree
    return tree;
}

/**
 * delete val from tree
 * @return delete tree
 */
Tree deleteTree(Tree tree, int val) {
    // check null
    if (tree != NULL) {
        // delete val in left sub tree
        if (val < data(tree)) {
            // delete left tree
            left(tree) = deleteTree(left(tree), val);
        } else if (val > data(tree)) {
            // delete val in right sub tree
            right(tree) = deleteTree(right(tree), val);
        } else {
            Tree new = NULL;
            // left right
            if (left(tree) != NULL && right(tree) != NULL) {
                // 2 sub tree
                new = joinTrees(left(tree), right(tree));
            } else {
                // check left then right
                new = left(tree) != NULL ? left(tree) : right(tree);
            }
            // free
            free(tree);
            // free
            tree = new;
        }
    }
    // return tree
    return tree;
}

/**
 * get height of tree
 * @param tree tree
 * @return height of tree
 */
int heightTree(Tree tree) {
    // check tree node is null
    int result = (tree != NULL);
    // check result
    if (result) {
        // left and right height
        // left height
        int leftHeight = heightTree(left(tree));
        // right height
        int rightHeight = heightTree(right(tree));
        // check left and right height
        result += leftHeight > rightHeight ? leftHeight : rightHeight;
    }
    // return result;
    return result;
}

/**
 * get left width tree
 * @return width
 */
int widthLeftTree(Tree tree) {
    // check null
    int result = (tree != NULL);
    // not null
    if (result) {
        // continue check left
        result += widthLeftTree(left(tree));
    }
    // return result
    return result;
}

/**
 * get left width tree
 * @return width
 */
int widthRightTree(Tree tree) {
    // check null
    int result = (tree != NULL);
    // not null
    if (result) {
        // continue check left
        result += widthLeftTree(right(tree));
    }
    // return result
    return result;
}

/**
 * get width tree
 * @return width
 */
int widthTree(Tree tree) {
    // check null
    int result = (tree != NULL);
    // not null
    if (result) {
        // left and right
        result += widthLeftTree(tree) + widthRightTree(tree);
    }
    // return result
    return result;
}

/**
 * get number of tree nodes
 * @param tree tree
 * @return number of tree nodes
 */
int countNodes(Tree tree) {
    // check tree node is null
    int result = (tree != NULL);
    // check result
    if (result) {
        // left and right height
        result += countNodes(left(tree))
                  + countNodes(right(tree));
    }
    // return result;
    return result;
}

/**
 * get number of tree leaves
 * @param t
 * @return
 */
int countLeaf(Tree tree) {
    // if null
    int result = (tree != NULL);
    // check not null
    if (result) {
        // check is leaf
        result = (left(tree) == NULL && right(tree) == NULL);
        // not leaf
        if (result == 0) {
            // count left and count right
            result = countLeaf(left(tree)) + countLeaf(right(tree));
        }
    }
    // return result
    return result;
}

/**
 * get number of tree odd nodes
 * @return
 */
int countOdds(Tree tree) {
    // check null
    int result = (tree != NULL);
    if (result) {
        // check current node
        result = (data(tree) % 2 == 1);
        // plus left and right
        result += countOdds(left(tree)) + countOdds(right(tree));
    }
    // return result
    return result;
}

/**
 * count odder level nodes
 * @return count
 */
int countOdderLevelNodesByLevel(Tree tree, int level) {
    // check null
    int result = 0;
    if (tree != NULL) {
        result = level % 2
                 + countOdderLevelNodesByLevel(left(tree), level - 1)
                 + countOdderLevelNodesByLevel(right(tree), level - 1);
        if (level % 2 == 1) {
            printf("height:%d, tree node :%d,\n", level, data(tree));
        }
    }

    return result;
}

int countOdderLevelNodes(Tree tree) {
    // check null
    return countOdderLevelNodesByLevel(tree, heightTree(tree));
}

/**
 * search val in tree
 * @param val value
 * @return return target tree
 */
Tree searchTree(Tree tree, int val) {
    // check tree null
    if (tree != NULL) {
        // if val less the current tree data
        if (val < data(tree)) {
            tree = searchTree(left(tree), val);
        } else if (val > data(tree)) {
            // if val more than current tree data
            tree = searchTree(right(tree), val);
        }
    }
    // return tree
    return tree;
}

/**
 * print by pre order
 * @param tree tree node
 */
void printPreOrderTree(Tree tree) {
    // check tree null
    if (tree != NULL) {
        // print
        printf(" %d ", data(tree));
        // go left
        printPreOrderTree(left(tree));
        // go right
        printPreOrderTree(right(tree));
    }
}

/**
 * print by pre order
 * @param tree tree node
 */
int printPreOrderTreeIndexNumber(Tree tree, int index) {
    // check tree null
    if (tree != NULL) {
        // go left
        index = printPreOrderTreeIndexNumber(left(tree), index);
        index++;
        // print
        printf(" node value: %d,index is %d \n ", data(tree), index);
        // go right
        index = printPreOrderTreeIndexNumber(right(tree), index);
    }

    // return index
    return index;
}

/**
 * print by pre order
 * @param tree tree node
 */
void printPreOrderTreeIndex(Tree tree) {

    // print pre order index
    printPreOrderTreeIndexNumber(tree, 0);
}

/**
 * print by in order
 * @param tree tree node
 */
void printInOrderTree(Tree tree) {
    // check tree null
    if (tree != NULL) {

        // go left
        printInOrderTree(left(tree));
        // print
        printf(" %d ", data(tree));
        // go right
        printInOrderTree(right(tree));
    }
}

/**
 * print by post order
 * @param tree tree node
 */
void printPostOrderTree(Tree tree) {
    // check tree null
    if (tree != NULL) {
        // go left
        printPostOrderTree(left(tree));
        // go right
        printPostOrderTree(right(tree));
        // print
        printf(" %d ", data(tree));
    }
}

/* Print nodes at a given level */
void printGivenLevel(Tree tree, int level) {
    // check not null
    if (tree != NULL) {
        // print level
        if (level == 1)
            printf("%d ", data(tree));
        else if (level > 1) {
            // left and right
            printGivenLevel(left(tree), level - 1);
            printGivenLevel(right(tree), level - 1);
        }
    }
}

/**
 * print level order of tree
 * @param tree
 */
void printLevelOrderTree(Tree tree) {
    // check height of tree
    int h = heightTree(tree);
    // print every level
    for (int i = 1; i <= h; i++) {
        printf("\n");
        // print given level
        printGivenLevel(tree, i);
    }
}

/**
 * print height add node values
 */
void printHeightAddNodeValues(Tree tree) {
    // check not null
    if (tree != NULL) {
        data(tree) = data(tree) + heightTree(tree);
        // go left
        printHeightAddNodeValues(left(tree));
        // go right
        printHeightAddNodeValues(right(tree));
    }
}

/**
 * rotate right
 * @param tree tree
 * @return new tree
 */
Tree rotateRight(Tree n1) {
    // check two node
    if (n1 && left(n1)) {
        // get n2
        Tree n2 = left(n1);
        // set n1 left
        left(n1) = right(n2);
        // set n2 right
        right(n2) = n1;
        // new root
        n1 = n2;
    }
    // return n2
    return n1;
}

/**
 * rotate left
 * @param tree tree
 * @return new tree
 */
Tree rotateLeft(Tree n2) {
    // check two node
    if (n2 && right(n2)) {
        // get n2
        Tree n1 = right(n2);
        // set n1 left
        right(n2) = left(n1);
        // set   n2 right
        left(n1) = n2;
        // new root
        n2 = n1;
    }
    // return n2
    return n2;
}

/**
 * join two tree
 * max(key(t1)) < min(key(k2))
 *
 * @return
 */
Tree joinTrees(Tree t1, Tree t2) {
    // check t1 null
    if (t1 == NULL) {
        // return t2
        return t2;
    } else if (t2 == NULL) {
        // check t2 null
        // return t1
        return t1;
    } else {
        // current / parent
        Tree curr = t2, parent = NULL;
        // check current left
        while (left(curr) != NULL) {
            parent = curr;
            curr = left(curr);
        }

        // check parent value
        if (parent != NULL) {
            //   10
            // 5
            //   6
            // covert to
            //   10
            // 6
            left(parent) = right(curr);
            //    5
            //       10
            right(curr) = t2;
        }
        //      5
        //   t1   t2(10)
        left(curr) = t1;

        //  return current
        return curr;
    }
}

/**
 * check number of nodes in a tree is balanced
 * @param tree
 * @return
 */
bool isBalancedByNumberOfNodes(Tree tree) {
    // if tree is null, then true
    bool result = (tree == NULL);
    if (!result) {
        // check left and right and current node
        result = isBalancedByNumberOfNodes(left(tree))
                 && isBalancedByNumberOfNodes(right(tree))
                 && abs(countNodes(left(tree)) - countNodes(right(tree))) < 2;

        printf("tree node is: %d, check result is: %d\n", data(tree), result);
    }
    // return result
    return result;
}

Tree partition(Tree t, int i) {
    if (t != NULL) {
        assert(0 <= i && i < countNodes(t));
        int m = countNodes(left(t));
        if (i < m) {
            left(t) = partition(left(t), i);
            t = rotateRight(t);
        } else if (i > m) {
            right(t) = partition(right(t), i - m - 1);
            t = rotateLeft(t);
        }
    }
    return t;
}

/**
 * re balance
 * @param tree tree
 * @return
 */
Tree reBalance(Tree tree) {
    int n = countNodes(tree);
    if (n >= 3) {
        tree = partition(tree, n / 2);           // put node with median key at root
        left(tree) = reBalance(left(tree));    // then rebalance each subtree
        right(tree) = reBalance(right(tree));
    }
    return tree;
}

/**
 * show tree right
 * @param t tree
 * @param depth depth
 */
void showTreeR(Tree t, int depth) {
    if (t != NULL) {
        // show tree R
        showTreeR(right(t), depth + 1);
        for (int i = 0; i < depth; i++)
            putchar('\t');            // TAB character
        printf("%d\n", data(t));
        showTreeR(left(t), depth + 1);
    }
}

/**
 * show tree
 * @param t tree
 */
void showTree(Tree t) {
    showTreeR(t, 0);
}


