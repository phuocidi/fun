#! /urs/bin/env python3

#code

duration = 0.5
def maxTree(arr, time, duration):
  ntree = int((time/duration + 1)//2)
  n = len(arr)
  if n <= ntree: 
      return sum(arr)
  for i in range(0, ntree-1):
      arr.append(arr[i])

  maxSum = sum(arr[:ntree])
  
  for i in range(1, n):
    currSum = sum(arr[i:i+ntree])
    if currSum>maxSum:
      maxSum = currSum
  
  return maxSum

def test():
  arr = [5, 7, 8, 5, 7, 0, 4, 7, 0]
  print(maxTree(arr, 9, 0.5))
  arr2 = [5, 7, 8, 5, 7, 0, 4, 7, 0]
  print(maxTree(arr2, 9, 0.5))
  arr3 = [9, 0]
  print(maxTree(arr3, 7, 0.5))

def main():
  nTestCase = int(input())
  for case in range(0, nTestCase):
    (nodes, time) = (int(x) for x in input().split(" ") if x.isnumeric() )
    arr = [int(x) for x in input().split(" ") if x.isnumeric()]
    print(maxTree(arr, time, duration))
        


if __name__=="__main__":
  main()