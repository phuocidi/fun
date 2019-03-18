#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r);
void merge_sort(vector<int> &arr, int l, int r);

void merge(vector<int> &arr, int l, int m, int r) {
  int n1 = (m - l + 1);
  int n2 = r - m;

  vector<int> L, R;

  for (int i = 0; i < n1; ++i) {
    L.push_back(arr[l + i]);
  }

  for (int i = 0; i < n2; ++i) {
    R.push_back(arr[m + i + 1]);
  }

  int i = 0;
  int j = 0;
  int k = l;

  // move element in ascending order;
  while (i < n1 && j < n2) {
    if(L[i] < R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  // copy whatever left in L, and R;
  while(i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  // while(j < n2) {
  //   arr[k] = R[j];
  //   ++j;
  //   ++k;
  // }
}

void merge_sort(vector<int> &arr, int l, int r) {
  if (l < r) {
    int m = (l + r)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

void test_merge_sort() {
  vector<int> v { 9,7,8,1,5,6,0,2};
  int r = v.size()-1;
  merge_sort(v, 0, r); 
  
  for (auto const &item : v) {
    cout << item << " | ";
  }
  cout << endl;
}

int main() {
  test_merge_sort();
}