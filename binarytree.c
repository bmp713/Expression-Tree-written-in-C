/* Brandon Piper
 *
 * binarytree.c :
 *     implementation of a binary expression tree.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "infonode.h"
#include "boolean.h"

typedef struct BinTreeNode{ 
  BinTreeElt info; 
  BinTree leftCh; 
  BinTree rightCh; 
}BinTreeNode;

/* Returns a new empty tree */
BinTree makeEmptyTree(void){
  BinTree tree= malloc(sizeof(BinTreeNode));
  tree->info=NULL;
  tree->leftCh=NULL;
  tree->rightCh=NULL;
  return tree;
}

/* Attaches a new root to two existing subtrees 
 * and returns the new tree. */
BinTree consBinTree(BinTreeElt newRoot, BinTree oldLTree, BinTree oldRTree){
  BinTree new= makeEmptyTree();
  new->info= newRoot;
  new->leftCh= oldLTree;
  new->rightCh= oldRTree;
  return new;
}

/* Returns true if the tree is empty, else returns false. */
boolean emptyTree(BinTree t){
  if(t==NULL)
    return true;
  else return false;
}

/* Returns the root of tree t */
BinTreeElt rootElt(BinTree t){
  if(!emptyTree(t)){
    return t->info;
  }
  else return NULL;
}

/* Returns the leftchild of root t */
BinTree leftChild(BinTree t){
  if(!emptyTree(t)){
    return t->leftCh;
  }
  else return NULL;
}

/* Returns the rightchild of root t */
BinTree rightChild(BinTree t){
  if(!emptyTree(t)){
    return t->rightCh;
  }
  else return NULL;
}

/* Deletes a leaf in a tree */
void deleteLeaf(BinTree l){
  if(!emptyTree(l)&&!emptyTree(l->leftCh)
     &&!emptyTree(l->rightCh)){
    free(l->info);
    l->info=NULL;
    l->leftCh=NULL;
    l->rightCh=NULL;
    free(l);
  }
}
