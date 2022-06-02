#ifndef ALIST_H
#define ALIST_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "list.h"
#include "utilities.h"

template <typename E> // Array-based list implementation
class AList : public List<E> {
private:
  int maxSize; // Maximum size of list
  int listSize; // Number of list items now
  int curr; // Position of current element
  E* listArray; // Array holding list elements
public:
  AList(int size = 20) { // Constructor. Replace defaultSize (now 20) with the default you want otherwise leave empty
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize]; // Fized size array inside.
  }
  ~AList() { delete [] listArray; } // Destructor
  void clear() { // Reinitialize the list
    delete [] listArray; // Remove the array
    listSize = curr = 0; // Reset the size
    listArray = new E[maxSize]; // Recreate array
  }
  // Insert "it" at current position
  void insert(const E& it) {
    Assert(listSize < maxSize, "List capacity exceeded");
    for(int i=listSize; i>curr; i--) // Shift elements up
      listArray[i] = listArray[i-1]; // to make room
    listArray[curr] = it;
    listSize++; // Increment list size
  }
  void append(const E& it) { // Append "it"
    Assert(listSize < maxSize, "List capacity exceeded");
    listArray[listSize++] = it;
  }
  // Remove and return the current element.
  E remove() {
    Assert((curr>=0) && (curr < listSize), "No element");
    E it = listArray[curr]; // Copy the element
    for(int i=curr; i<listSize-1; i++) // Shift them down
      listArray[i] = listArray[i+1];
    listSize--; // Decrement size
    return it;
  }
  void moveToStart() {
    curr = 0;
  } // Reset position
  void moveToEnd() {
    curr = listSize; // Set at end
  }
  void prev() {
    if (curr != 0) curr--; // Back up
  }
  void next() {
    if (curr < listSize) curr++; // Next
  }
  // Return list size
  int length() const {
    return listSize;
  }
  // Return current position
  int currPos() const {
    return curr;
  }
  // Set current list position to "pos"
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
    curr = pos;
  }
  const E& getValue() const { // Return current element
    Assert((curr>=0)&&(curr<listSize),"No current element");
    return listArray[curr];
  }
  bool isAtEnd() { return curr == listSize; }

  bool ssearch(const E& it)
  {
    for (auto an_element : listArray)
      {
        if (an_element == it)
          return true;
      }
    return false;
  }
  // Iteraive binary search
  bool ibsearch(const E& search_this)
  {
    int right = listSize - 1;
    int left = 0;
    while (left <= right) // Left and right can't cross
      {
        int mid = left + (right - left)/2;

        if (listArray[mid] == search_this)
          return true; // Found it
        if (listArray[mid] > search_this)
          {
            right = mid - 1; // Search key is in frirst half. So leave the right half by moving right to mid - 1
          }
        else
          {
            left = mid + 1; // Search key is in second half. So leave the left half by moving left to mid + 1
          }
      }
    return false;
  }
// recusive binary search
  bool rbsearch(const E& search_this, int left, int right)
  {
    int mid = left + (right - left)/2;

    if (listArray[mid] == search_this)
      return true; // Found it
    if (listArray[mid] > search_this)
      {
        right =mid - 1; // Search key is in frirst half. So leave the right half by moving right to mid - 1
      }
    else
      {
        left = mid + 1; // Search key is in second half. So leave the left half by moving left to mid + 1
      }
    return rbsearch(search_this, left, right);
  }


};
#endif // ALIST_H
