#include <iostream>
#include <stdio.h>

using namespace std;
/**
Let isSubSetSum(int set[], int n, int sum) be the function to find whether there is a subset of set[] with sum equal to sum. n is the number of elements in set[].

The isSubsetSum problem can be divided into two subproblems
…a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
…b) Exclude the last element, recur for n = n-1.
If any of the above the above subproblems return true, then return true.
**/



template <typename T, size_t size> 

void pprint1D(const T(&set)[size], bool index = false) 
{
  if (index == true ) 
  {
    for (size_t i = 0; i < size; ++i)
    {
      printf("%4d", (int)i);
    }
      
    printf("\n");
    for (size_t i = 0; i < size; ++i)
    {
      printf("----");
    }
    printf("\n");
  }
  for (size_t i = 0; i < size; ++i) 
    {
      printf ("%4d", set[i] ) ;
    }
    printf("\n");
}

template<typename T>
void pprint2D(T mat, std::size_t N, std::size_t M) {
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M; ++j)
            cout<< *(*(mat+i)+j)<<" ";
        cout<<endl;
    }
    cout<<endl;
}


bool isSubsetSum(int set [], int n, int sum) 
{
  if (sum == 0) return true;
  if (sum > 0 && n == 0) return false;
  // Exclude last element greater than sum
  if (set[n-1] > sum) 
    return isSubsetSum(set, n-1, sum);
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum -  set[n-1]);
}

bool isSubsetSumBottomUp( int set[], const int n, const int sum) 
{ 
    // The value of subset[i][j] will be true if there is a  
    // subset of set[0..j-1] with sum equal to i 
    bool subset[n+1][sum+1]; 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
          subset[i][j] = subset[i-1][j]; 
         else 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
   
     // uncomment this code to print table 
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }
   
     return subset[n][sum]; 
} 

int main() 
{
  int set[] = { 3, 34, 4, 12, 5, 2 }; 
  int sum = 9; 
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSumBottomUp(set, n, sum) == true) 
      printf("Found a subset with given sum\n"); 
  else
      printf("No subset with given sum\n"); 
  return 0; 
}