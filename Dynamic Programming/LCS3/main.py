#! /user/bin/env python3
import sys
sys.setrecursionlimit(2000)

"""
Input : str1 = "geeks"  
        str2 = "geeksfor"  
        str3 = "geeksforgeeks"
Output : 5
Longest common subsequence is "geeks"
i.e., length = 5

Input : str1 = "abcd1e2"  
        str2 = "bc12ea"  
        str3 = "bd1ea"
Output : 3
Longest common subsequence is "b1e" 
i.e. length = 3.

X = 'AGGT12'
Y = '12TXAYB'
Z = '12XBA'
expect LCS is 2
"""

def LCSRecursive(X,Y,Z, m, n, o):
  """
  Recursively find the Longest common subsequence length of 3 given strings
  - Args:
    X (str): First string
    Y (str): Second string
    Z (str): Third string
    m (int): length of first string
    n (int): length of second string
    o (int): length of third string
  - Returns:
    int: The length of the longest common subsequence string
  """
  if m==0 or n==0 or o==0:
    return 0
  if X[m-1]==Y[n-1]==Z[o-1]:
    return 1 + LCSRecursive(X, Y, Z, m-1, n-1, o-1)
  else:
    return max(LCSRecursive(X, Y, Z, m-1, n, o), 
                max(LCSRecursive(X,Y,Z,m, n-1,o), LCSRecursive(X,Y,Z,m,n,o-1)))

def LCSMemoization(X,Y,Z,m,n,o):
  L=[[[0]*(o+1)]*(n+1)]* (m+1)
  if m==0 or n==0 or o==0:
    L[m][n][o] = 0
  elif L[m][n][o] != 0:
    return L[m][n][o]
  elif X[m-1] == Y[n-1] == Z[o-1]:
    L[m][n][o] = 1 + LCSMemoization(X,Y,Z, m-1, n-1, o-1)
  else:
    L[m][n][o] = max(LCSMemoization(X,Y,Z, m-1, n, o), 
                    max(LCSMemoization(X,Y,Z, m, n-1, o), LCSMemoization(X,Y,Z, m, n, o-1)))
  return L[m][n][o]

def LCSTabulation(X,Y,Z):
  m = len(X)
  n = len(Y)
  o = len(Z)

  L = [[[0 for i in range(o+1)] for j in range(n+1)]
        for k in range(m+1)]

  ''' Following steps build L[m+1][n+1][o+1] in
  bottom up fashion. Note that L[i][j][k]
  contains length of LCS of X[0..i-1] and
  Y[0..j-1] and Z[0.....k-1] '''
  for i in range(m+1):
      for j in range(n+1):
          for k in range(o+1):
              if (i == 0 or j == 0 or k == 0):
                  L[i][j][k] = 0
              elif (X[i-1] == Y[j-1]  == Z[k-1]):
                  L[i][j][k] = L[i-1][j-1][k-1] + 1

              else:
                  L[i][j][k] = max(max(L[i-1][j][k],
                  L[i][j-1][k]),
                                  L[i][j][k-1])

  # L[m][n][o] contains length of LCS for
  # X[0..n-1] and Y[0..m-1] and Z[0..o-1]
  return L[m][n][o]

def test():
  X = 'geeks'
  Y = 'geeksfor'
  Z = 'geeksforgeeks'
  m = len(X)
  n = len(Y)
  o = len(Z)
  # print("LCSRecursive is: ",LCSMemoization(X,Y,Z,m,n,o))
  # print("LCSMemoization is: ",LCSMemoization(X,Y,Z,m,n,o))
  print("LCSTabulation is: ",LCSTabulation(X,Y,Z))

def main():
  test()

if __name__=="__main__":
  main()