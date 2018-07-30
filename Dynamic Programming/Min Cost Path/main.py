#! /usr/bin/env python3

import sys
from timeit import timeit 
def MCPRecursive(cost, m, n):
  """
  Calculate minimum sum cost path from [0,0] to [m,n]
  - Args:
    cost (list): A 2D square matrix
    m (int): last index of row
    n (int): last index of column
  - Returns:
    int: The minimum cost path from top left to bottom right of the matrix
  """
  if (m < 0 or n < 0):
    return sys.maxsize
  elif (m==0 and n==0):
    return cost[m][n]
  else:
    return cost[m][n] + min(MCPRecursive(cost, m-1, n-1),
    MCPRecursive(cost, m-1, n),
    MCPRecursive(cost, m, n-1))

def MCPTabulation(cost, r, c):
  """
  Calculate minimum sum cost path from [0,0] to [m,n]
  - Args:
    cost (list): a 2D square matrix 
    r (int): number  of rows
    c (int): number of columns
  - Returns:
  int: minimum sum cost path from top left to bottom right. 
  """
  # tc: for total cost table
  tc = [ [0]*r for i in range(c) ]
  tc[0][0] = cost[0][0]
  # Fill the first column:
  for i in range(1, c):
    tc[i][0] = tc[i-1][0] + cost[i][0]
  # Fill the first row:
  for j in range(1, r):
    tc[0][j] = tc[0][j-1] + cost[0][j]
  
  for i in range(1,c):
    for j in range(1,r):
      tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j]

  return tc[c-1][r-1]


def min(x,y,z):
  """
  Aux function to check minimum of 3 values 
  """
  if x < y:
    return x if x < z else z
  else:
    return y if y < z else z
  

def performance():
  SETUPCODE = '''
from __main__ import MCPRecursive, MCPTabulation

cost= [ [1, 2, 3],
      [4, 8, 2],
      [1, 5, 3] ]
m = 2
n = 2
r = 3
c = 3
  '''

  MCPRecursiveTestCode = '''
MCPRecursive(cost, m, n)
  '''

  MCPTabulationTestCode = '''
MCPTabulation(cost,r,c)
  '''
  print("MCPRecursive: ",timeit(setup=SETUPCODE, stmt=MCPRecursiveTestCode,number=1000))
  print("MCPTabulation: ",timeit(setup=SETUPCODE, stmt=MCPTabulationTestCode,number=1000))

  
def main():

  # cost= [ [1, 2, 3],
  #       [4, 8, 2],
  #       [1, 5, 3] ]
  # print(MCPRecursive(cost, 2, 2))
  # print(MCPTabulation(cost,3,3))
  performance()

if __name__=="__main__":
  main()