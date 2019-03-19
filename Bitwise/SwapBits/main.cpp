#include <stdio.h>

using namespace std;

long swapBits (long x, int i, int j) {
// Check if two bits are the same, only swap if they are different

  if ( ( (x >> i) & 1 ) != ((x >> j) & 1)  ) {
    unsigned long bitmask = (1L << i) | (1L << j);
    x ^= bitmask;
  }
  return x;
}

int main() {
  long value = 73;
  long expect = 11;

  long actual = swapBits(value, 1, 6);
  printf("Expect: %ld \t get: %ld\n", expect, actual);
}