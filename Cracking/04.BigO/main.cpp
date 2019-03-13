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

// Ex 12
void permutation(string s);
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

// Reverse words ?Auto Club? to ?Club Auto?
void reverseString( string& str, size_t start, size_t end);
void reverseWords( string& str);
void testReverseString();

void reverseString( string& str, size_t start, size_t end) {
  // swap/flip subsequence char
  size_t offset = start;
  size_t mid = (end + offset)/2;

  for (int i = start; i < mid; ++i) {
    size_t rightIndex = end - i - 1 + offset;
    char temp = str[rightIndex];
    str[rightIndex] = str[i];
    str[i] = temp;
  }
}

void reverseWords( string& str) {
  size_t n = str.size();
  size_t start, end = 0;
  while(end<n){
    end++;
    if (str[end] == ' ') {
      reverseString(str, start, end);
      start = end + 1;
    } else if (str[end] == *(str.end()) ) {
      reverseString(str, start, end);
    }
  }
  reverseString(str, 0, n);
}

void testReverseString() {
  string str = string("Auto Club");
  reverseWords(str);
  cout << str << endl;
}

// Ex VI.5 Compute iteger square root of a number

int sqrt_helper(int n, int min, int max);
int sqrtInt(int n);

int sqrtInt(int n) {
  return sqrt_helper(n, 1, n) ;
}

int sqrt_helper(int n, int min, int max) {

}

int main() {
  // testReverse();
  // testIsPrime();
  // permutation( string("abc"));
  testReverseString();

}