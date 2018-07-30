#!/usr/bin/env python3

def binarySearch(arr, x):
  """
    Binary Search on sorted array
  """
  n = len(arr)
  if n == 0: 
    return
  if n == 1:
    return arr[0] if x==arr[0] else None
  mid = n//2
  if x == arr[mid]:
    return arr[mid]
  elif x < arr[mid]:
    left = arr[0:mid]
    return binarySearch(left, x)
  else:
    right = arr[mid:n]
    return binarySearch(right, x)
  
  

def findPairWithKBinary(arr, k):
  n = len(arr)
  if n == 0: return
  
  arr.sort()
  count = 0
  for i in range(0, n):
    nextK = arr[i]+k
    if binarySearch(arr, nextK):
      count += 1
  return count

def findPairWithKPointers(arr, k):
  n = len(arr)
  if n == 0: return
  
  arr.sort()
  count, l, r = 0, 0, 0
  while  r < n:
    diff = arr[r] - arr[l]
    if diff == k:
      count += 1
      l += 1
      r += 1
      continue
    if diff > k:
      l += 1
    elif diff < k:
      r += 1 
  return count
  
    
def testBinary():
  print("testBinary: START")
  xs = [8, 10, 5, 1, 0, 2]
  arr  = [x for x in range(0,10)]
  for x in xs:
    result = binarySearch(arr, x)
    print(result)
  print("testBinary: END\n")

def testFindPairWithKBinary():
  """
  Test findPairWithKBinary
  Expect 2
  """
  arr  = [1, 5, 3, 4, 2]
  k = 3
  result = findPairWithKBinary(arr, k)
  print(result)

def testFindPairWithKPointers():
  """
  Test findPairWithKPointers
  Expect 5
  """
  arr  = [8, 12, 16, 4, 0, 20]
  k = 4
  result = findPairWithKPointers(arr, k)
  print(result)

def main():
  testFindPairWithKPointers()
  testFindPairWithKBinary()
  
if __name__ == "__main__":
  main()
