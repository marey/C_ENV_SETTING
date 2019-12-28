//
// Created by Rui.Mu on 2019-05-22.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

// the definition of element linked list
typedef struct node {
    // the previous node
    struct node *previous;
    // the next node
    struct node *next;
    // the address keep the value
    int data;
} Node;

// the structure of list
typedef struct IteratorIntRep {
    // the middle of next and previous is the position
    Node *next;
    Node *previous;
    // header reset
    Node *header;
    // the current cursor value
    Node *cursor;

} IteratorIntRep;


/**
 * create a new iterator of int;
 * @return the collections
 */
IteratorInt IteratorIntNew() {

    // request memories
    IteratorInt it = malloc(sizeof(*it));
    if (it != NULL) {
        // set all the elements to null;
        it->cursor = NULL;
        it->next = NULL;
        it->previous = NULL;
        it->header = NULL;
    }

    return it;
}

/**
 * reset the iterator list
 * @param it list
 */
void reset(IteratorInt it) {

    // check collections is null
    if (it != NULL) {
        // reset all the value to default
        it->cursor = NULL;
        it->next = it->header;
        it->previous = NULL;
    }

}

/**
 * create aa new node
 * @param data data
 * @return return new node point
 */
Node *createNode(int data) {

    // define new node
    Node *newNode = malloc(sizeof(*newNode));

    // no memories
    if (newNode != NULL) {
        // request the address for the data
        newNode->data = data;
        // set all the value to default
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    // return new node
    return newNode;

}


/**
 * add a new element
 * @param it list
 * @param v value
 * @return 1:is true 0 is false
 */
int add(IteratorInt it, int v) {

    // result
    int result = (it != NULL);

    if (result) {
        // create new node
        Node *newNode = createNode(v);
        // check new node and it whether NULL
        result = (newNode != NULL);
        if (result) {
            // the first position
            if (it->previous == NULL) {
                // 如果当前的header不是空的，设置previous
                if (it->header != NULL) {
                    it->header->previous = newNode;
                }

                // move the next
                newNode->next = it->header;
                it->header = newNode;

                // move cursor
                it->cursor = it->header;
                it->previous = it->header;
                it->next = it->header->next;
            } else {
                // construct current node info
                newNode->next = it->next;
                newNode->previous = it->previous;
                it->previous->next = newNode;

                // move cursor
                it->previous = newNode;
                it->next = newNode->next;
            }

            // reset cursor
            it->cursor = NULL;
        }
    }

    // return value
    return result;
}

/**
 * check has the next value
 * @param it list
 * @return 1 has next 0 no next
 */
int hasNext(IteratorInt it) {
    int result = 0;
    if (it != NULL) {
        // set cursor null
        it->cursor = NULL;
        // next value
        result = (it->next != NULL);
    }
    // return directly
    return result;
}

/**
 * check has the previous value
 * @param it list
 * @return 1 has previous 0 no previous
 */
int hasPrevious(IteratorInt it) {

    int result = 0;
    if (it != NULL) {
        // set cursor null
        it->cursor = NULL;
        // result
        result = (it->previous != NULL);
    }
    // return directly
    return result;
}

/**
 * get next element
 * @param it
 * @return return the next data
 */
int *next(IteratorInt it) {
    // define result
    int *result = NULL;
    if (hasNext(it)) {
        result = &(it->next->data);
        // adjust the position and values
        it->previous = it->next;
        it->next = it->next->next;
        it->cursor = it->previous;
    }

    return result;
}

/**
 * Returns the pointer to the previous value in the given list iterator and moves the cursor position backwards.
 * This method may be called repeatedly to iterate through the list backwards,
 * or intermixed with calls to next to go back and forth.
 * (Note that alternating calls to next and previous will return the same element repeatedly.)
 * @param it list int
 * @return return pointer
 */
int *previous(IteratorInt it) {

    // define result
    int *result = NULL;
    // check previous
    if (hasPrevious(it)) {
        result = &(it->previous->data);
        // move the position and cursor
        it->next = it->previous;
        it->cursor = it->previous;
        it->previous = it->previous->previous;
    }
    return result;
}

/**
 * delete all the element
 * @param it list
 * @return 1 successful 0 fail
 */
int deleteElm(IteratorInt it) {

    int result = (it != NULL && it->cursor != NULL);
    // check the element
    if (result) {
        Node *temp = it->cursor;

        // check conditions
        if (temp == it->header) {
            it->header = it->header->next;
            if (it->header != NULL) {
                it->header->previous = NULL;
            }
            it->next = it->header;
            it->previous = NULL;

        } else {
            Node *current = it->cursor->previous;
            // next node
            current->next = temp->next;
            if (current->next != NULL) {
                current->next->previous = current;
            }

            // remove
            it->previous = current;
            it->next = current->next;
        }

        free(temp);
        it->cursor = NULL;
    }

    return result;

}

/**
 * set the current value
 * @param it list
 * @param v value
 * @return set the value
 */
int set(IteratorInt it, int v) {

    // set the value
    int result = (it != NULL && it->cursor != NULL);
    // check conditions
    if (result) {
        it->cursor->data = v;
        // set default value to cursor
        it->cursor = NULL;
    }
    // result
    return result;
}

/**
 * find the next value
 * @param it iterator
 * @param v find the target value
 * @return address of value of node
 */
int *findNext(IteratorInt it, int v) {

    int *result = NULL;
    // implement this function
    if (it != NULL) {
        // get the next
        Node *temp = it->next;
        while (temp != NULL) {
            // temp data is equal
            if (temp->data == v) {

                // deal with the cursor
                it->cursor = temp;
                it->previous = temp;
                it->next = temp->next;

                // check the value
                result = &(temp->data);
                break;
            }
            temp = temp->next;
        }

        // not found
        if (result == NULL) {
            it->cursor = NULL;
        }
    }

    return result;
}

/**
 * find previous
 * @param it  list
 * @param v value
 * @return the address
 */
int *findPrevious(IteratorInt it, int v) {

    // implement this function
    int *result = NULL;
    if (it != NULL) {
        // implement this function
        Node *temp = it->previous;
        while (temp != NULL) {
            // check the current value
            if (temp->data == v) {
                // deal with the cursor
                it->cursor = temp;
                it->previous = temp->previous;
                it->next = temp;
                // set return result
                result = &(temp->data);
                break;
            }
            // get the previous
            temp = temp->previous;
        }

        // not found
        if (result == NULL) {
            it->cursor = NULL;
        }
    }

    return result;
}

/**
 * free memories
 * @param it
 */
void freeIt(IteratorInt it) {
    //  check value
    if (it != NULL) {
        // define variables
        Node *temp = NULL, *n = it->header;
        // check and free
        while (n != NULL) {
            temp = n;
            n = n->next;
            free(temp);
        }

        // set all to NULL;
        it->header = NULL;
        it->previous = NULL;
        it->next = NULL;
        it->cursor = NULL;

        free(it);
    }
}

