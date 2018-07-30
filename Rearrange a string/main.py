#! /usr/bin/env python3
from functools import reduce

def mergeSort(s, l, r):
  if l < r:
    m = (l+r)//2
    mergeSort(s, l, m)
    mergeSort(s, m+1, r)
    merge(s, l, m, r)


def merge(s, l, m, r):
  n1 = m - l + 1
  n2 = r - m

  L = [0] * n1
  R = [0] * n2

  #copy left and right array
  for i in range(0, n1):
    L[i] = s[l + i]
  for j in range(0, n2):
    R[j] = s[m + 1 + j]

  i = 0 # start index for left array
  j = 0 # start index for right array
  k = l # copy start index of main array

  while i < n1 and j < n2:
    if L[i] < R[j]:
      s[k] = L[i]
      i += 1
    else:
      s[k] = R[j]
      j += 1
    k += 1
  
  while i < n1:
    s[k] = L[i]
    k += 1
    i += 1

  while j < n2:
    s[k] = R[j]
    k += 1
    j += 1
   
def rearrange(arr):
  n = len(arr)
  if n < 1:
    return arr
  
  i = 0
  while i < n:
    if not arr[i].isnumeric():
      break
    i += 1
  
  total = reduce(lambda x, y: int(x) + int(y), arr[:i])
  print(arr[i:n])
  arr = arr[i:n].append(str(total))
  

  
    
def test():
  testcases = {
    1: 'AC2BEW3',
    2: 'ACCBA10D2EW30'
  }
  for case, s in testcases.items():
    arr = list(s)
    mergeSort(arr, 0, len(arr)-1)
    rearrange(arr)
    newS = reduce(lambda a, b: a+b, arr)
    print("Case {case}: input: {s}".format(case=case, s=newS))


def main():
  test()
  

if __name__=="__main__":
  main()