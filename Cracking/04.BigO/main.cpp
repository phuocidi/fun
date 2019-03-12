#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
/// Chapter 6. Big O

// Ex 6 Reverses an array
template  <typename T>
void printArray( T array[], int n) {
  for (int i= 0; i < n; ++i) {
    cout << array[i] << " | ";
  }
  cout << endl;
}

void reverse( int array[], int n) {
  for (int i = 0; i < n/2; ++i) {
    int other = n-i-1;
    int temp = array[i];
    array[i] = array[other];
    array[other] = temp;
  }
}

void testReverse() {
  const int n = 6;
  int array [n] = {1,2,3,4,5,6};
  printArray(array, n);
  reverse(array, n);
  printArray(array, n);
}


/// Ex 10 isPrime
bool isPrime(int n) {
  for (int  x = 2; x*x <= sqrt(n); ++x ) {
    if (n % x == 0) {
      return false;
    }
  }
  return true;
}

void testIsPrime() {
  const int n = 4;
  int val [n] = {1, 7, 33, 37};
  bool expect [n] = { true, true, false, true};
  for (int i = 0; i < n; ++i) {
    bool result = isPrime(val[i]) && expect[i];
    cout << result << " | ";
  }
  cout<<endl; 
}

void permutation(string str, string prefix);
void permutation(string s) {
  permutation(s, string(""));
}

void permutation(string str, string prefix) {
  size_t n = str.size();

  if (n == 0) {
    cout << prefix << " ";
  } else {
    for (size_t i = 0;i < n; ++i) {
      string rem = str.substr(0, i) + str.substr(i+1, n-i-1);
      permutation(rem, prefix + str.at(i));
    }
  }
}


int main() {
  // testReverse();
  // testIsPrime();
  permutation( string("abc"));
}