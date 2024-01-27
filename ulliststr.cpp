#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const std::string& val){
  if (empty()){
    head_ = new Item();
    tail_ = head_;
    tail_->first = 0;
    tail_->last = 0;
    size_ = 0;
    //std::cout << "Fresh Size is "<< size_ << std::endl;
  }
  if (tail_->last == 10){
    Item* newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = tail_->next;
  }
  tail_->val[tail_->last] = val;  
  tail_->last += 1;
  size_++;  
  //std::cout << "added to the back is " << tail_->val[tail_->last-1] << " at " << tail_->last  << std::endl;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back(){
  //std::cout << "BEG Size is "<< size_ << std::endl;
  tail_->last -= 1;
  tail_->val[tail_->last] = "";
  //std::cout << "Working till before if "<< std::endl;
  if (tail_->last == 0){
    if (tail_->prev == nullptr){
      clear();
      return;
    }
    else{
      Item* temp = tail_->prev;
      delete tail_;
      tail_ = temp;
      tail_->next = nullptr;      
    }
  }
  //std::cout << "Working till after if "<< std::endl;
  //std::cout << "MID Size is "<< size_ << std::endl;
  size_ = size_-1;
  //std::cout << "Size is "<< size_ << std::endl;

}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val){
  if (empty()){
    head_ = new Item();
    tail_ = head_;
    head_->first = 0;
    head_->last = 1;
    size_ = 0;
    head_->val[head_->first] = val;
    //std::cout << "added to the beg front is " << head_->val[head_->first] << " at " << head_->first << std::endl;
    size_++;
    return;
  }
  else if (head_->first == 0){
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = head_->prev;
    head_->first = head_->last = 10;
  }
  head_->first--;
  head_->val[head_->first] = val;
  //std::cout << "added to the front is " << head_->val[head_->first] << " at " << head_->first << std::endl;
  size_++;
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front(){
  head_->val[head_->first] = "";
  head_->first++;
  size_--;
  if (size_ == 0){
    clear();
    return;
  }
  if (head_->first == 10){
    if (size_ == 0){
      clear();
      return;
    }
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
    head_->prev = nullptr;
  }
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (empty()) return NULL;
  Item* curr = head_;
  int count = 0;
  while(curr != NULL){
    count++;
    //std::cout << "LOC is : " << loc << std::endl;

    int len = curr->last - curr->first;
    //std::cout << "LEN is : " << len << std::endl;

    if (loc >= len){
      loc -= len;
      curr = curr->next;
      //std::cout << "Working till curr next" << std::endl;
    }
    else{
      //std::cout << "Value is got at : " << curr->val[curr->first+loc] << " Location at " << curr->first+loc << std::endl;
      return &(curr->val[curr->first+loc]);
    }
  }
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  //std::cout << "CLEAR?" << std::endl;
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
