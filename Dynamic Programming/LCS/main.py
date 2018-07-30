#! /usr/bin/env python3
from timeit import timeit

def LCSRecursive(X, Y, n, m):
  """
    Find the length of the longest common subsequence of two given string
    - Args:
      X (str): first string
      Y (str): second string
      n (int): last row index
      m (int): last column index
    - Returns:
      int: The length of the longest common subsequence.
  """
  if n==0 or m ==0:
    return 0
  elif X[n-1] == Y[m-1]:
    return 1 + LCSRecursive(X, Y, n-1, m-1)
  else:
    return max(LCSRecursive(X, Y, n-1, m), LCSRecursive(X,Y,n,m-1))

def LCSTabulation(X, Y):
  n = len(X)
  m = len(Y)

  L = [[None] * (m+1) for i in range(n+1)] # Initialize matrix m x n 
  for i in range(n+1):
    for j in range(m+1):
      if i == 0 or j == 0:
        L[i][j] = 0
      elif X[i-1] == Y[j-1]:
        L[i][j] = L[i-1][j-1] + 1
      else:
        L[i][j] = max(L[i-1][j], L[i][j-1])
  return L[n][m]

def LCSMemoization(X, Y, n, m):

  L = [[None]*(m+1) for i in range(n+1)]
  if n==0 or m==0:
    L[n][m] = 0
  elif L[n][m] != None and L[n][m]!=0:
    return L[n][m]
  elif X[n-1]== Y[m-1]:
    L[n][m] = 1 + LCSMemoization(X,Y, n-1, m-1)
  else:
    L[n][m] = max(LCSMemoization(X,Y,n-1,m),LCSMemoization(X,Y, n, m-1))
  return L[n][m]

def main():
  SETUPCODE = '''
from __main__ import LCSRecursive, LCSTabulation, LCSMemoization
X = "AGGTAB"
Y = "GXTXAYB"
  '''
  LCSRecursiveTestCode = '''
LCSRecursive(X , Y, len(X), len(Y))
  '''

  LCSTabulationTestCode = '''
LCSTabulation(X , Y)
  '''
  LCSMemoizationTestCode = '''
LCSMemoization(X , Y, len(X), len(Y))
'''

  # X = "AGGTAB"
  # Y = "GXTXAYB"
  # print ("Length of LCSRecursive is ", LCSRecursive(X , Y, len(X), len(Y)))
  # print ("Length of LCSTabulation is ", LCSTabulation(X , Y))
  #print ("Length of LCSTabulation is ", LCSMemoization(X , Y, len(X), len(Y)))
  print("LCSRecursive: ", timeit(setup=SETUPCODE, stmt=LCSRecursiveTestCode, number=1000))
  print("LCSTabulation: ", timeit(setup=SETUPCODE, stmt=LCSTabulationTestCode, number=1000))
  print("LCSMemoization: ", timeit(setup=SETUPCODE, stmt=LCSMemoizationTestCode, number=1000))

if __name__=="__main__":
  main()