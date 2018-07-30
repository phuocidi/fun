#!/usr/bin/env python3

N=4

def rotateClockwise(mat):
  for x in range(0, N//2):
    for y in range(x, N-x-1):
      tmp = mat[x][y] #copy the top left cell

      #move the top right to the top left
      mat[x][y] = mat[y][N-x-1]

      #move the right bottom to the top right
      mat[y][N-x-1] = mat[N-x-1][N-y-1]

      # move the left bottom to the right bottom
      mat[N-x-1][N-y-1] = mat[N-y-1][x]

      # move the top left to the bottom left
      mat[N-y-1][x] = tmp

def printMat(mat):
  print("\n")
  for i in range(0, N):
    for j in range(0, N):
      print (mat[i][j], end = ' ')
    print("")

def main():
  mat = [
          [1,2,3,4],
          [5,6,7,8],
          [9,10,11,12],
          [13,14,15,16],        
        ]
  '''
  # Test case 2
  mat = [ [1, 2, 3 ],
          [4, 5, 6 ],
          [7, 8, 9 ] ]
  
  # Test case 3
  mat = [ [1, 2 ],
          [4, 5 ] ]
          
  '''
  printMat(mat)
  rotateClockwise(mat)
  printMat(mat)

if __name__ == "__main__": main()
