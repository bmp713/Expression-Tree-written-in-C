/*Brandon Piper
 *
 * infonodedriver.c - simple driver for infonode.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "infonode.h"

int main( int argc, char **argv ){
  InfoNode test1=makeOperandElt(3);
  InfoNode test2=makeOperatorElt('*');
  int elt=getOperandElt(test1);
  char elt2=getOperatorElt(test2);
  printf("%d\n", elt);
  printf("%c\n", elt2);
  free(test1);
  free(test2);
  return 0;
}
