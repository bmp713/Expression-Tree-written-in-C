/*Brandon Piper
 *
 * EvalExpression - reads expression input from a file and 
 *         evaluates it by use of a stack and binary tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "infonode.h"
#include "binarytree.h"
#include "stack.h"

/* reverses the order of a stack */
Stack reverseStack(Stack stack);
/* pushes a tree node info node into a stack */
void pushTreeElt(BinTree tree, Stack stack);
/* traverses a tree and calls pushTreeElt at each node */
void postorderTraverse(BinTree tree, Stack stack);

int main( int argc, char **argv ){ 
  
  char ch;
  StackElt element;
  Stack stack1=makeEmptyStack();
/* scan the input file to get an expression */
  FILE *input=fopen(argv[1],"r");
  if(input==NULL){
    exit(1);
  }
  else{
/* scans all characters in input file and pushes them 
 * into a stack.  only pushes integers and valid operators.
 */
   
 while(fscanf(input,"%c",&ch)!=EOF){
      if(ch>47 && ch<58){
	int num=(int)ch-48;
	element=makeOperandElt(num);
	push(stack1, element);
      }
      if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
	element=makeOperatorElt(ch);
	push(stack1, element);
      }      
    }
  }

/* retrieve the types from each InfoNode */
  StackElt element1=top(stack1);
  int num1=getOperandElt((InfoNode)element1);
  pop(stack1);
  StackElt element2=top(stack1);
  char ch1=getOperatorElt((InfoNode)element2);
  pop(stack1);
  StackElt element3=top(stack1);
  int num2=getOperandElt((InfoNode)element3);
  pop(stack1);
  

  fclose(input);
  InfoNode operator=makeOperatorElt(ch1);
  InfoNode operand1=makeOperandElt(num1);
  InfoNode operand2=makeOperandElt(num2);

/* Construct the trees using consBinTree */  
  BinTree tree1=consBinTree((BinTreeElt)operand1, 
			    NULL, NULL);
  BinTree tree2=consBinTree((BinTreeElt)operand2, 
			    NULL, NULL);
  BinTree newtree=consBinTree((BinTreeElt)operator, 
			      tree1, tree2);
  Stack stack=makeEmptyStack();
  
/* Insert each InfoNode into a stack */
  postorderTraverse(newtree, stack);
  
  Stack rev=reverseStack(stack);
  
  int answer;
  
  StackElt temp1=top(rev);
  int num3=getOperandElt((InfoNode)temp1);
  pop(rev);
  StackElt temp2=top(rev);
  int num4=getOperandElt((InfoNode)temp2);
  pop(rev);
  StackElt temp3=top(rev);
  ch=getOperatorElt((InfoNode)temp3);
  
/* figure out which operation was popped */
  if(ch=='+')
    answer=num3+num4;
  if(ch=='-')
    answer=num3-num4;
  if(ch=='*')
    answer=num3*num4;
  if(ch=='/')
    answer=num3/num4;
  
  printf("%d%c%d=%d\n", num3, ch, num4, answer);
  return 0;
}

/*----------FUNCTION IMPLEMENTATIONS----------*/

Stack reverseStack(Stack stack){
  Stack rev=makeEmptyStack();
  StackElt temp=top(stack);
  while(!EmptyStack(stack)){
    push(rev, temp);
    pop(stack);
    temp=top(stack);
  }
  return rev;
}
void pushTreeElt(BinTree tree, Stack stack){
  BinTreeElt root=rootElt(tree);
  push(stack, (StackElt)root);
}

void postorderTraverse(BinTree tree, Stack stack){
  if(!emptyTree(tree) ){
    postorderTraverse(leftChild(tree), stack);
    postorderTraverse(rightChild(tree), stack);
    pushTreeElt(tree, stack);
  }
}
