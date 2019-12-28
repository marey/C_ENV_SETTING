//
// Created by Rui.Mu on 2019-01-22.
//
// zid:5144248
// Written by Rui.Mu, 2019-01-29.

#include "Common.h"
#include "AVLTree.h"

#ifndef COMP9024_TRIETREE_H
#define COMP9024_TRIETREE_H


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *words[ALPHABET_SIZE];
    // keep urls to tree;
    Tree tree;
    // end of a word
    bool exist;
};

typedef struct TrieNode *TrieTree;

/**
 * create node
 * @return tree node
 */
TrieTree getTrieTreeNode(void);

/**
 * insert tree: current vertices and out degree vertices
 */
void insertTrieTree(TrieTree, const char *, const char *);

/**
 * get urls tree from tire tree
 * @return tree
 */
Tree getTrieTreeUrlsTree(TrieTree, const char *);

/**
 * free trie tree
 */
void freeTrieTree(TrieTree);

#endif //COMP9024_TRIETREE_H
