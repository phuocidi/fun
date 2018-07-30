#!/usr/bin/env python3
from functools import reduce 

def lookSay(n):
  """
  Find the n-th sequence given n
  n = 1 => 1
  n = 2 => 11
  n = 3 => 21
  n = 4 => 1211
  n = 5 => 111221
  """


  if n==1 or n==0: return 1
  if n==2: return 11
  
  s =  str(11)
  arr = list(s)
  
  #generate the n-th str
  for i in range(2, n):
    #check from the previous term
    arr.append('-1') #dummy term to loop through
    k = len(arr)
    tmpArr = []
    
    count = 1
    for j in range(1, k):
      curr = arr[j]
      prev = arr[j-1]
      if curr != prev:
        tmpArr.append(str(count))
        tmpArr.append(prev)
        count = 1 # reset count
      else:
        count += 1
      
    arr = tmpArr
  return reduce(lambda a,b: a+b, arr)
       
def main():
  n = 7
  result = lookSay(n)
  print(result)

if __name__ == "__main__":
  main()