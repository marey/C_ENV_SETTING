// Integer Stack ADO header file ... COMP9024 20T2
#include <stdbool.h>

#define MAXITEMS 10

typedef struct _stack *Stack;


Stack StackInit();     // set up empty stack
void StackPush(Stack stack, int);  // insert int on top of stack
int  StackPop(Stack stack);      // remove int from top of stack


bool  StackIsEmpty();  // check whether stack is empty

