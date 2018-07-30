#!/usr/bin/env python3

def merge(arr, l, m, r):
  n1 = m - l + 1
  n2 = r - m

  L = [0] * (n1)
  R = [0] * (n2)

  # Copy tmp left array
  for i in range(0, n1):
    L[i] = arr[l + i]
  #Copy tmp right array
  for j in range(0, n2):
    R[j] = arr[m + 1 + j]
  
  i = 0 # start index for left arr
  j = 0 # start index for right arr
  k = l # start index of main arr

  # move left and right in sorted order
  while i < n1 and j < n2:
    if L[i] < R[j]:
      arr[k] = L[i]
      i += 1
    else:
      arr[k] = R[j]
      j += 1
    k += 1

  #copy the remaining in left array, if any:
  while i < n1:
    arr[k] = L[i]
    i += 1
    k += 1
  
  # copy the remaining in the right array, if any:
  while j < n2:
    arr[k] = R[j]
    j += 1
    k += 1
  


def mergeSort(arr, l, r):
  if l < r:
    m = (l + r)//2
    mergeSort(arr,l, m)
    mergeSort(arr, m+1, r)
    merge(arr, l, m, r)
  

def main():
  arr = [12, 11, 13, 5, 6, 7]
  n = len(arr)
  mergeSort(arr, 0, n-1)
  print(arr)

if __name__ == "__main__":
  main()