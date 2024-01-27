/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  Node* curr = in;
  if (in == nullptr){
    if (odds != nullptr){
      odds->next = nullptr;
    }
    if (evens != nullptr){
      evens->next = nullptr;
    }
    return;
  }
  else{
    if (curr->value % 2 == 1){
      if (odds == nullptr){
        odds = in;
        in = nullptr;
        Node* oddsTemp = odds;
        //cout << "odds" << odds->value << endl;
        split(curr->next, oddsTemp, evens);
      }
      else{
        odds->next = curr;
        odds = odds->next;
        //cout << "odds" << odds->value << endl;
        split(curr->next, odds, evens);
      }
    }
    else if (curr->value % 2 == 0){
      if (evens == nullptr){
        evens = in;
        in = nullptr;
        Node* evensTemp = evens;
       // cout << "evens" << evens->value << endl;
        split(curr->next, odds, evensTemp);
      }
      else{
        evens->next = curr;
        evens = evens->next;
       // cout << "evens" << evens->value << endl;
        split(curr->next, odds, evens);
      }
    }
  }
  return;
}
