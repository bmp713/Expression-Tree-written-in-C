/*Brandon Piper
 *
 *binarytree.h - header file for binarytree.c 
 *
 */

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "boolean.h"

typedef struct BinTreeNode * BinTree;
typedef struct InfoNode* BinTreeElt;

/* Returns a new empty tree
 * Postcondition: emptyTree(makeEmptyTree()) == TRUE
 * Any two calls to makeEmptyTree return the same value */
BinTree makeEmptyTree(void);

/* Attaches a new root to two existing subtrees 
 * and returns the new tree. 
 * Postconditions: 
 *   After t=consBinTree(newRoot,oldLTree,oldRTree): 
 *   emptyTree(t) == FALSE 
 *   rootElt(t) == newRoot
 *   rightChild(t)==oldRTree 
 *   leftChild(t)==oldLTree 
 * The value of t is different from that 
 * of any existing BinTree */
BinTree consBinTree(BinTreeElt newRoot
		    ,BinTree oldLTree,BinTree oldRTree);

/* Returns true if the tree is empty, else returns false. */
boolean emptyTree(BinTree t);

/* Returns the root of tree t
 * Precondition: emptyTree(t) == FALSE */
BinTreeElt rootElt(BinTree t);

/* Returns the leftchild of root t
 * Precondition: emptyTree(t) == FALSE */
BinTree leftChild(BinTree t);

/* Returns the rightchild of root t
 * Precondition: emptyTree(t) == FALSE */
BinTree rightChild(BinTree t);

/* Deletes a leaf in a tree
 * Preconditions: emptyTree(l)== FALSE, 
 *   emptyTree(leftChild(l))== TRUE, 
 *   emptyTree(rightChild(l))== TRUE, 
 *   Postcondition: emptyTree(l)== TRUE */
void deleteLeaf(BinTree l);

#endif
