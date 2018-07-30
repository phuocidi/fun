#! /usr/bin/env python3

""" 
Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
Then, L(i) can be recursively written as:
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.
To find the LIS for a given array, we need to return max(L(i)) where 0 < i < n.
Thus, we see the LIS problem satisfies the optimal substructure property as the main problem can be solved using solutions to subproblems.
 
 # Driver program to test the above function
arr = [10 , 22 , 9 , 33 , 21 , 50 , 41 , 60]
n = len(arr)
print "Length of lis is ", lis(arr)

>> Length of lis is 5
 """

global maximum #Declare to be use globally

def LISRecursive(arr):
  global maximum # declare to modify the global var outside the scope of this function
  
  n = len(arr)
  maximum = 1

  _LISRecursive(arr,n)
  return maximum

def _LISRecursive(arr, n):
  """
  Aux function to LISRecursive(arr)
  Recursively update max while maintaining incresing order 
  """
  global maximum
  if n == 1: 
    return 1

  maxRes = 1
  for i in range(1, n):
    res = _LISRecursive(arr, i)
    if arr[i-1] < arr[n-1] and res+1 > maxRes:
      maxRes = res + 1
  maximum = max(maximum, maxRes)

  return maxRes   

def LISTabulation(arr):
  """
  Find the Longest Increasing Subsequence using Tabulation method
  """
  n = len(arr)
  
  L = [1]*n
  for i in range(1, n):
    for j in range(0, i):
      if arr[j] < arr[i] and L[j]+1 > L[i]:
        L[i] = L[j] + 1
  
  maximum = 1
  for item in L:
    maximum = max(item, maximum)
  return maximum


def test():
  # arr = [10 , 22 , 9 , 33 , 21 , 50 , 41]
  # n = len(arr)
  # print("LISRecursive Expect: 4 - Actual  ", LISRecursive(arr)) #expect 4
  arr = [10, 22, 9, 33, 21, 50, 41, 60]
  print("LISTabulation Expect: 5 - Actual  ", LISTabulation(arr)) #expect 4

def main():
  test()

if __name__=="__main__":
  main()