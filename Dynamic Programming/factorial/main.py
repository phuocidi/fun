#! /usr/bin/env python3

def factorialTabulation(n):
  """
  Bottom-up approach to solve factorial
  """
  if n < 0:
    return None
  if n == 1 or n == 0: 
    return 1

  tab = [0]* (n+1)
  tab[0]= 1
  tab[1]= 1

  for i in range(1, n+1):
    tab[i] = tab[i-1] * i  
  return tab[n]

def factorialRecursive(n):
  if n < 0:
    return None
  if n == 0 or n == 1: 
    return 1

  return factorialRecursive(n-1) * n

def factorialMemoization(n):
  """
  Top down approach to solve factorial
  """
  if n < 0: 
    return None
  
  if n == 0:
    return 1

  tab = [0]* (n+1)
  if tab[n] != 0:
    return tab[n]

  tab[n] = factorialMemoization(n-1) * n
  return tab[n]

def main():
  n = int(input("\nFactorial of n: \t"))
  # print(factorialRecursive(n))
  # print(factorialTabulation(n))
  print(factorialMemoization(n))

if __name__=="__main__":
  main()