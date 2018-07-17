/* Brandon Piper
 * stackdriver.c - a driver to test the stack *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "boolean.h"

int main( int argc, char **argv ){
  int num;
  Stack stack=makeEmptyStack();
  for(num=0; num<4; num++){
    push(stack, (StackElt)num);
  }
  while(!EmptyStack(stack)){
    num=(int)top(stack);
    printf("%d\n", (int)top(stack));
    pop(stack);

  }
  push(stack, (StackElt)3);
  int num2=(int)top(stack);
  printf("%d\n", num2 );
  
  if(!EmptyStack(stack)){
    int num3=(int)top(stack);
    pop(stack);
    printf("%d\n", num3);
  }
  if(EmptyStack(stack))
    printf("Stack is Empty\n");

  free(stack);
  return 0;
}
