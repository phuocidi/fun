#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> &v, int left, int right);
void quick_sort(vector<int> &v, int left, int right);
void swap(vector<int> &v, int left, int right);


void swap(vector<int> &v, int l, int r) {
  if (l == r) return;
  int temp = v[l];
  v[l] = v[r];
  v[r] = temp;
}



int partition(vector<int> &v, int l, int r) {
  int mid = (l + r ) /2;
  int pivot = v[mid];
  
  while ( l <= r) {
  // move part in the right that is greater than pivot to the left
    while ( v[l] < pivot) {
      l++;
    }

  // vice versa
    while (v[r] > pivot) {
      r--;
    }

    if (l <= r) {
      swap(v, l, r);
      l++;
      r--;
    }
  }

  return l;
}

void quick_sort(vector<int> &v, int l, int r) {
  int index = partition(v, l, r);

  if (l < index-1) {
    quick_sort(v, l, index - 1);
  }

  if (index < r) {
    quick_sort(v, index, r);
  }
  
}

void test_quick_sort() {
  vector<int> v { 9,7,8,1,5,6,0,2};
  int r = v.size() -1;
  quick_sort(v, 0, r); 
  
  for (auto const &item : v) {
    cout << item << " | ";
  }
  cout << endl;
}

int main() {
  test_quick_sort();
}