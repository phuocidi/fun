#! /usr/bin/env python3
"""
Let arr[0..n-1] be the input array and MSDS[i] be the maximum sum of the MSDS ending at index i such that arr[i] is the last element of the MSDS.
Then, MSDS[i] can be written as:

MSDS[i] = a[i] + max( MSDS[j] ) where i > j > 0 and arr[j] > arr[i] or,
MSDS[i] = a[i], if no such j exists.
"""

def msds(arr, n):
  """
  Compute maximum sum decreasing subsequence
  - Args:
    arr (list(int)): array of sequence number
    n: lenght of the array 
  """
  # init the sol matmric
  sol = [x for x in arr] # copy the value

  for i in range(1, n):
    for j in range(0,i):
      if arr[i] > arr[j] and 

  for 

def main():
  pass

if __name__=="__main__":
  main()