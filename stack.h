/* Brandon Piper
 *
 * stack.h - header file for stack ADT
 *
 */

#ifndef __STACK_H__
#define __STACK_H__
#include "boolean.h"

typedef void* StackElt;
typedef struct StackStruct * Stack;

/* Returns an empty stack */
Stack makeEmptyStack(void);

/* Returns true if stack is empty, 
 * else returns false */
boolean EmptyStack(Stack stack);

/* Returns the top element in a stack */
StackElt top(Stack stack);

/* Pops the first element on the stack */
void pop(Stack stack);

/* Push an element onto the stack */
void push(Stack stack, StackElt element);

#endif
