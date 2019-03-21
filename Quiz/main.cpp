#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int find_second_largest(const vector<int> &arr) 
{
  if (arr.size() < 2) 
  {
    try 
    {
      throw "ERROR: input length has to be greater than 2";
    }
    catch (const char *msg) 
    {
      cerr << msg << endl;
    }
  }

  int largest(INT_MIN), second(INT_MIN);
  for (auto &current : arr) 
  {
    if( current > largest) 
    {
      second = largest;
      largest = current;
    } 
    else if (current != largest && current > second)
    {
      second = current;
    }
  }

  if (second == INT_MIN) {
    second = largest;
  }
  return second;
}

void test_find_second_largest() {
  vector<int> arr1{1,2,3,4,5};
  vector<int> arr2{5,5,4,3,1};
  vector<int> arr3{0,0,0,0,0};
  vector<int> arr4{0};

  int re1 = find_second_largest(arr1);
  int re2 = find_second_largest(arr2);
  int re3 = find_second_largest(arr3);
  int re4 = find_second_largest(arr4);

  cout << "given {1,2,3,4,5} expect: 4, actual: " << re1 << endl;
  cout << "given {5,5,4,3,1} expect: 4, actual: " << re2 << endl;
  cout << "given {0,0,0,0,0} expect: 0, actual: " << re3 << endl;
}

inline int pop_heap_int(vector<int> & heap) {
  int l = heap.front();
  pop_heap(heap.begin(), heap.end());
  heap.pop_back();
  return l;
}

int find_k_largest(const vector<int> &arr, int k) {
  vector<int> heap = vector<int>{arr};
  make_heap(heap.begin(), heap.end());
  int largest = pop_heap_int(heap);
  int i{k}, second{INT_MIN};

  while (i > 0 && i < heap.size()) 
  {
    second = largest;
    largest = pop_heap_int(heap);
    if (second != largest) 
    {
      --i;
    }
  }

  return second;
}

void test_find_k_largest() {
  vector<int> arr1{1,2,3,4,5};
  vector<int> arr2{5,5,4,3,1};
  vector<int> arr3{0,0,0,0,0};
  vector<int> arr4{0};

  int re1 = find_k_largest(arr1,2);
  int re2 = find_k_largest(arr2,2);
  int re3 = find_k_largest(arr3,2);
  // int re4 = find_k_largest(arr4,2);

  cout << "given {1,2,3,4,5} expect: 4, actual: " << re1 << endl;
  cout << "given {5,5,4,3,1} expect: 4, actual: " << re2 << endl;
  cout << "given {0,0,0,0,0} expect: 0, actual: " << re3 << endl;
}

int main(int argc, char *argv []) 
{
  // test_find_second_largest();
  test_find_k_largest();
  return 0;
}