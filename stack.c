/* Brandon Piper
 *
 * stack.c - implementation of stack ADT
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "boolean.h"

typedef struct StackNode* Node;

typedef struct StackStruct{
  Node top;
}StackStruct;

typedef struct StackNode{
  StackElt element;
  Node link;
}StackNode;

/* Returns an empty stack */
Stack makeEmptyStack(void){
  Stack new= malloc(sizeof(StackStruct));
  new->top=NULL;
  return new;
}

/* Returns true if stack is empty, 
 * else returns false */
boolean EmptyStack(Stack stack){
  if(stack->top==NULL)
    return true;
  else return false;
}

/* Returns the top element in a stack */
StackElt top(Stack stack){
  if(!EmptyStack(stack))
    return stack->top->element;
  else return NULL;
}

/* Pops the first element on the stack */
void pop(Stack stack){
  if(!EmptyStack(stack)){
    Node temp=stack->top->link;
    stack->top->link=NULL;
    free(stack->top);
    stack->top=temp;
  }
}

/* Push an element onto the stack */
void push(Stack stack, StackElt element){
  Node temp=stack->top;
  stack->top=malloc(sizeof(StackNode));
  stack->top->element=element;
  stack->top->link=temp;
}
