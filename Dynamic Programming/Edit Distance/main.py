#! /usr/bin/env python3

"""

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a


The idea is process all characters one by one staring from either from left or right sides of both strings.
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

m: Length of str1 (first string)
n: Length of str2 (second string)

If last characters of two strings are same, nothing much to do. 
  Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else 
  (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
  Insert: Recur for m and n-1
  Remove: Recur for m-1 and n
  Replace: Recur for m-1 and n-1
"""

def min(x,y,z):
  """
  Aux function to calculate minimum of 3 variable
  - Args
    x (int): first value
    y (int): second value
    z (int): third value
  - Returns
    int: The minimum value
  """
  if x <= y:
    return x if x < z else z
  if y <= x:
    return y if y < z else z

def editDistanceRecursive(str1, str2, m, n):
  """
  Find the minimum cost to edit str1 to become str2
  - Args
    str1 (str): string 1
    str2 (str): string 2
    m (int): (last) index of str1 
    n (int): (last) index of str2
  - Returns
    int: minimum cost to edit str1 to become str2
  """
  if m == 0: # str1 is empty, only need to add to str1 all characters of str2
    return n
  
  if n == 0: # str2 is empty, only need to remove all characters of str1
    return m
  
  if str1[m-1] == str2[n-1]:
    return editDistanceRecursive(str1, str2, m-1, n-1)
  else:
    return 1 + min(editDistanceRecursive(str1, str2, m-1, n), # remove
                    editDistanceRecursive(str1, str2, m-1, n-1), # replace
                    editDistanceRecursive(str1, str2, m, n-1)) # insert


def editDistanceTabulation(str1, str2,m, n):
  sol = [[0 for _ in range(n+1)] for _ in range(m+1)]
  sol[0][0]= 1
  for i in range(m+1):
    for j in range(n+1):
      if i == 0: # fisrt string is empty
        sol[i][j] = j # given max cost is j
      if j == 0: # second string is empty
        sol[i][j] = i # given max cost is i
      if str1[i-1] == str2[j-1]:
        sol[i][j] = sol[i-1][j-1]
      else:
        sol[i][j] = 1 + min(sol[i-1][j],
                            sol[i-1][j-1],
                            sol[i][j-1])
  printMat(sol)
  return sol[m][n] 

def printMat(mat):
  for i in mat:
    row = '|'
    for j in i:
      c = str(j)
      row += ' ' + c if len(c)==2 else '  ' + c
    row += " |"
    print(row)
  print() 


def test():
  str1 = "sunday"
  str2 = "saturday"
  m = len(str1)
  n = len(str2)
  print(editDistanceTabulation(str1,str2,m,n))

def main():
  test()

if __name__=="__main__":
  main()