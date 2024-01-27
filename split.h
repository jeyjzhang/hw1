#ifndef SPLIT_H
#define SPLIT_H
#include <iostream>
using namespace std;


struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);

#endif
