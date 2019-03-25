#! /usr/bin/env python3

NxN = 8

def printMat(mat):
  for i in mat:
    row = '|'
    for j in i:
      c = str(j)
      row += ' ' + c if len(c)==2 else '  ' + c
    row += " |"
    print(row)
  print()

def isSafe(x, y, sol, N=NxN):
  """
  Check if the move at (x,y) of sol[N][N] is valid
  """
  return (x >= 0 and x < N and y >= 0 and y < N and sol[x][y] == -1)

def solveKTRecursive(x,y,movei, sol, moveX, moveY):
  n = len(sol)

  if movei == NxN * NxN:
    return True

  for k in range(n):
    nextX = x + moveX[k]
    nextY = y + moveY[k]
    if isSafe(nextX, nextY, sol,NxN ):
      sol[nextX][nextY] = movei
      #printMat(sol)
      isAbleToCompleted = solveKTRecursive(nextX, nextY, movei + 1, sol, moveX, moveY)
      if isAbleToCompleted:
        return True
      else:
        sol[nextX][nextY] = -1
  return False

def solveKT(N=NxN):
  sol = [[-1 for _ in range(N)] for _ in range(N)]
  # assign all directional next-move coordinates
  moveX = [ 2, 1, -1, -2, -2, -1,  1,  2]
  moveY = [ 1, 2,  2,  1, -1, -2, -2, -1]
  sol[0][0] = 0 #start at [0][0]

  isFound = solveKTRecursive(0,0,1, sol, moveX, moveY)
  if isFound:
    printMat(sol)
    return False
  else: 
    print("Cannot Found the solution")
  return True

def main():
  solveKT()

if __name__=="__main__":
  main()