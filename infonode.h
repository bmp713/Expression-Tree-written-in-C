/*Brandon Piper
 *
 * infonode.h - header file for infonode functions
 *
 */

#ifndef __INFONODE_H__
#define __INFONODE_H__

typedef struct Node* InfoNode;

/* makes an infonode with an operand */
InfoNode makeOperandElt(int operand);

/* makes an infonode with an operator */
InfoNode makeOperatorElt(char operator);

/* makes an infonode with an operator */
int getOperandElt(InfoNode node);

/* returns an operator character */
char getOperatorElt(InfoNode node);

/* returns the type in infonode */
int getTypeElt(InfoNode node);

#endif

