#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
  if(!head){
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* nextNode = head-> next;
  if (head -> val <=pivot){
    head-> next = smaller;
    smaller = head;
  }
  else{
    head-> next = larger;
    larger = head;
  }

  head = nextNode;
  llpivot(head,smaller,larger,pivot);
}