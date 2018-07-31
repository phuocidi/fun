#! /usr/bin/env python3 

from random import seed, randrange

"""
Some definitions:

A position Q is accessible from a position P if P can move to Q by a single Knight’s move, and Q has not yet been visited.
The accessibility of a position P is the number of positions accessible from P.

Algorithm:

Set P to be a random initial position on the board
Mark the board at P with the move number “1”
Do following for each move number from 2 to the number of squares on the board:
let S be the set of positions accessible from P.
Set P to be the position in S with minimum accessibility
Mark the board at P with the current move number
Return the marked board — each square will be marked with the move number on which it is visited.
"""

NxN = 8
moveX = [ 2, 1, -1, -2, -2, -1,  1,  2]
moveY = [ 1, 2,  2,  1, -1, -2, -2, -1]

def printMat(mat):
  for i in mat:
    row = '|'
    for j in i:
      c = str(j)
      row += ' ' + c if len(c)==2 else '  ' + c
    row += " |"
    print(row)
  print()

def isSafe(x,y,sol, N=NxN):
  """
  Check if the current index is valid
  - Args
    x (int): row index
    y (int): column index
    sol (list[list]): A 2D matrix
    N (int): the matrix dimension
  - Returns
    bool: indicate the index is valid for a given solution matrix
  """
  return x<N and x>=0 and y<N and y>=0 and sol[x][y]==-1

def isClosedTour(x,y,moveX,moveY,x0,y0):
  """
  Check if the next move of the last move will reach the initial sol(x0,y0)
  - Args
    x (int): row index
    y (int): column index
    moveX (list): surrounding posible next x move
    moveY (list): surrounding posible next y move
    x0 (int): initial move x
    y0 (int): initial move y
  
  - Returns
    Boolean indicate whethe the current move is the end of the close tour or not.
  """
  for i in range(NxN):
    nextX = x + moveX[i]
    nextY = y + moveY[i]
    return True if (nextX==x0 and nextY==y0) else False

def getDegree(x,y,moveX,moveY,sol, N=NxN):
  """
  Get the number of adjacent degrees that sastisfy Knight movement rules
  - Args
    x (int): row index
    y (int): column index
    moveX (list): next moves x
    moveY (list): next move y
    sol: (list[list]): chess board 2D matrix
    N: the dimension of the chess board
  - Returns
    Number of adjacents degree of a give move(x,y)
  """
  count = 0
  for i in range(N):
    nextX = x + moveX[i]
    nextY = y + moveY[i]
    if isSafe(nextX,nextY,sol,N):
      count += 1
  return count

def lastMove(x,y,moveX,moveY,sol, N=NxN):
  """
  Find the last move coordinate
  - Args
    x (int): row index
    y (int): column index
    moveX (list): next move x
    moveY (list): next move y
    sol: (list[list]): chess board 2D matrix
    N (int): square matrix dimension
  - Returns
    tuple of next move if possible, otherwise returns (-1,-1)
  """
  n = len(moveX)
  start = randrange(n)

  minDegreeXY = (-1, -1)
  minTmp = N+1 #Degree cannot greater than possible moves

  for offset in range(n):
    i = (start + offset) % n # overflow index are set I={i, i < start}
    nextX = moveX[i] + x
    nextY = moveY[i] + y

    if isSafe(nextX, nextY, sol,N):
      degrees = getDegree(nextX, nextY, moveX, moveY, sol, N)
      if degrees < minTmp:
        minTmp = degrees
        minDegreeXY = (nextX, nextY)
  # update sol matrix with +1 move
  sol[minDegreeXY[0]][minDegreeXY[1]] = sol[x][y] + 1
    
  if minDegreeXY == (-1,-1):
    return (-1,-1) # Cannot find any more move

  
  # Returns next (x,y)
  return minDegreeXY


def Warnsdoffs(N=NxN):
  """
  Warnsdorff’s Rule:

  1 - We can start from any initial position of the knight on the board.
  2 - We always move to an adjacent, unvisited square with minimal degree (minimum number of unvisited adjacent).
  """
  
  sol = [[-1 for _ in range(N)] for _ in range(N)] # fill the solution matrix

  startX = randrange(N)
  startY = randrange(N)

  sol[startX][startY] = 0 # mark the first move
  
  lastXY = lastMove(startX,startY,moveX,moveY,sol,N)
  for i in range(N*N - 1):
    if lastXY == (-1,-1):
      print("Cannot find any solution")
      return sol
    
    lastXY = lastMove(lastXY[0], lastXY[1], moveX, moveY, sol)
  
  return sol

    
  

def main():
  seed(a=None)
  sol = Warnsdoffs()
  if sol is None:
    print("Cannot find any solution")
  else:
    printMat(sol)
  

if __name__=="__main__":
  main()