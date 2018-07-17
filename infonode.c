/* Brandon Piper
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "infonode.h"
#include "boolean.h"
#include "binarytree.h"
#define OPERATOR 0;
#define OPERAND 1;

typedef struct Node{ 
  int Type; 
  char Operator; 
  int Operand; 
}Node;

/* makes an infonode with an operand */
InfoNode makeOperandElt(int operand){
  InfoNode new=malloc(sizeof(Node));
  new->Type=OPERAND;
  new->Operator=NULL;
  new->Operand=operand;
  return new;
}

/* makes an infonode with an operator */
InfoNode makeOperatorElt(char operator){
  InfoNode new=malloc(sizeof(Node));
  new->Type=OPERATOR;
  new->Operator=operator;
  new->Operand=NULL;
  return new;
}

/* makes an infonode with an operator */
int getOperandElt(InfoNode node){
  return node->Operand;
}

/* returns an operator character */
char getOperatorElt(InfoNode node){
  return node->Operator; 
}

/* returns the type in infonode */
int getTypeElt(InfoNode node){
  return node->Type;
}
