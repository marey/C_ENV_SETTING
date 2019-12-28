// C implementation of search and insert operations
// on Trie
// zid:5144248
// Written by Rui.Mu, 2019-01-29.

#include "TrieTree.h"

// Returns new trie node (initialized to NULLs)
TrieTree getTrieTreeNode(void) {
    // create new node
    TrieTree newNode = malloc(sizeof(struct TrieNode));
    // check new node
    if (newNode != NULL) {
        // false
        newNode->exist = false;
        // check size
        for (int i = 0; i < ALPHABET_SIZE; i++)
            newNode->words[i] = NULL;
        // init new tree
        newNode->tree = NULL;
    }
    // return new node
    return newNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insertTrieTree(TrieTree root, const char *key, const char *word) {
    // get length of key
    size_t length = strlen(key);

    int index;
    // temp node
    TrieTree tempNode = root;
    // level
    for (int level = 0; level < length; level++) {
        // get index
        index = CHAR_TO_INDEX(key[level]);
        // check exist
        if (!tempNode->words[index])
            tempNode->words[index] = getTrieTreeNode();
        // new temp node
        tempNode = tempNode->words[index];
    }

    // mark last node as leaf
    tempNode->exist = true;
    // insert value to tree
    tempNode->tree = insertTree(tempNode->tree, (Item) word, 0);
}

/**
 * get url trees
 * @param root
 * @param key
 */
Tree getTrieTreeUrlsTree(TrieTree root, const char *key) {
    // apple
    // get length of key ( 5)
    size_t length = strlen(key);

    int index,level = 0;
    // temp node
    TrieTree tempNode = root;
    // while
    while (tempNode!=NULL && level < length) {
        // get index
        index = CHAR_TO_INDEX(key[level]);
        // new temp node
        tempNode = tempNode->words[index];
        // level ++
        level++;
    }
    // check NULL
    if (tempNode!=NULL && tempNode->exist) {
        // return NULL
        return tempNode->tree;
    }
    // NULL
    return NULL;
}

/**
 * free trie tree
 */
void freeTrieTree(TrieTree root) {

    if (root != NULL) {
        // check size
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->words[i] != NULL) {
                freeTrieTree(root->words[i]);
            }
        }
        // free tree
        freeTree(root->tree);
        // free root
        free(root);
    }
}

