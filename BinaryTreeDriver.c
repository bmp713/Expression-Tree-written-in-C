/*Brandon Piper
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "stack.h"
#include "infonode.h"

/*-----------Recursive Prototypes-----------*/

int treeHeight(BinTree tree);
/*return the height of the tree*/

void preorderTraverse(BinTree tree);
/*print the contents in preorder*/

void inorderTraverse(BinTree tree);
/*print the contents in inorder*/

void postorderTraverse(BinTree tree);
/*print the list in postorder*/

void printTree(BinTree tree);
/*print the element in a length 1 tree*/

void deleteTree(BinTree tree);
/*delete all nodes in the tree*/


int main( int argc, char **argv ){

/* create some infonode to form a tree*/
  InfoNode operator=makeOperatorElt('/');
  InfoNode operand1=makeOperandElt(3);
  InfoNode operand2=makeOperandElt(5);

/* build the tree from the infonodes */
  BinTree tree1=consBinTree((BinTreeElt)operand1, 
			    NULL, NULL);
  BinTree tree2=consBinTree((BinTreeElt)operand2, 
			    NULL, NULL);
  BinTree newtree=consBinTree((BinTreeElt)operator, 
			      tree1, tree2);
  
  int height=treeHeight(newtree);
  printf("HEIGHT=%d\n", height);

/* print the tree with each type of traversal */ 
  printf("pre-order = ");
  preorderTraverse(newtree);
  printf("\nin-order  = ");
  inorderTraverse(newtree);
  printf("\npost-order= ");
  postorderTraverse(newtree);
  printf("\n");
  if(!emptyTree(newtree))
    printf("\ntree created\n");

/* test all possible calls to functions */  
  BinTreeElt root=rootElt(newtree);
  
  if(getTypeElt((InfoNode)root)==0){
    char ch=getOperatorElt((InfoNode)root);
    printf("%c\n", ch);
  }
  if(getTypeElt((InfoNode)root)==1){
    int num=getOperandElt((InfoNode)root);
    printf("%d\n", num);
  }

  BinTree temp=leftChild(newtree);
  BinTreeElt root2=rootElt(temp);
  
  if(getTypeElt((InfoNode)root2)==0){
    char ch=getOperatorElt((InfoNode)root2);
    printf("%c\n", ch);
  }
  if(getTypeElt((InfoNode)root2)==1){
    int num=getOperandElt((InfoNode)root2);
    printf("%d\n", num);
  }
  deleteLeaf(temp);

  temp=rightChild(newtree);
  root2=rootElt(temp);

  if(getTypeElt((InfoNode)root2)==0){
    char ch=getOperatorElt((InfoNode)root2);
    printf("%c\n", ch);
  }
  if(getTypeElt((InfoNode)root2)==1){
    int num=getOperandElt((InfoNode)root2);
    printf("%d\n", num);
  }
  
  deleteLeaf(temp);
  deleteLeaf(newtree);
 
  if(emptyTree(newtree))
    printf("Empty Tree\n");

  return 0;
}

/*--------------Implementations-------------*/

int treeHeight(BinTree tree){
  int height, max;
  if(emptyTree(tree))
    return 0;
  else{
    height=treeHeight(leftChild(tree));
    max=treeHeight(rightChild(tree));
    if(height>max)
      max=height;
    return (max+1);
  }
}

void preorderTraverse(BinTree tree){
  if(!emptyTree(tree) ){
    printTree(tree);
    postorderTraverse(leftChild(tree));
    postorderTraverse(rightChild(tree));
  }
}

void inorderTraverse(BinTree tree){
  if(!emptyTree(tree) ){
    postorderTraverse(leftChild(tree));
    printTree(tree);
    postorderTraverse(rightChild(tree));
  }
}

void postorderTraverse(BinTree tree){
  if(!emptyTree(tree) ){
    postorderTraverse(leftChild(tree));
    postorderTraverse(rightChild(tree));
    printTree(tree);
  }
}

void deleteTree(BinTree tree){
  if(!emptyTree(tree) ){
    deleteTree(leftChild(tree));
    deleteTree(rightChild(tree));
    deleteLeaf(tree);
  }
}

/* uses getType to get the type of infonode */
void printTree(BinTree tree){
  BinTreeElt temp=rootElt(tree);
  if(getTypeElt((InfoNode)temp)==0){
    char ch=getOperatorElt((InfoNode)temp);
    printf("%c ", ch);
  }
  if(getTypeElt((InfoNode)temp)==1){
    int num=getOperandElt((InfoNode)temp);
    printf("%d ", num);
  }
}
