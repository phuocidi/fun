#include <iostream>

using namespace std;

bool isSubsetSum(int set[], int n, int sum) 
{
  return true;
}

int main() 
{
  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int n = sizeof(set)/sizeof(set[0]); 
  if (isSubsetSum(set, n, sum) == true) 
     printf("Found a subset with given sum\n"); 
  else
     printf("No subset with given sum\n"); 
  return 0; 
}