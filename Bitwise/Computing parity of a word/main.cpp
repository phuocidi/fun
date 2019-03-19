#include <stdio.h>
#include <bitset>
#include <random>
#include <iostream>

using namespace std;
const size_t kSize = 64;

short ParityNaive( unsigned long x) {
  short result = 0;
  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }

  return result;
}

/// Drop the right most bit each iteration

short ParityDropBit(unsigned long x) {
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x-1);
  }

  return result;
}

short ParityCache(unsigned long x) {
  
  bitset<kSize> precomputed_parity;
  const unsigned short kWordSize = 16;
  const unsigned short kBitMask = 0xFFFF;

  // initialize cache with 16bits of 0s, 1s, 1s, 0s;
  for (size_t i; i < precomputed_parity.size(); ++i) {
    int counter = 0;
    if (i % 16 == 0) {
      counter += 1;
    }

    if ( counter > 0 && counter%2 == 0) {
      precomputed_parity[i] = 1;
    } else {
      precomputed_parity[i] = 0;
    }
  }

  return precomputed_parity[ x >> (3 * kWordSize) ] ^
         precomputed_parity[ x >> (2 * kWordSize) & kBitMask] ^
         precomputed_parity[ x >> kWordSize & kBitMask] ^
         precomputed_parity[ x & kBitMask];
}

short Parity(unsigned long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}


int main() {
  random_device rd; // set seed
  default_random_engine generator(rd());//Random number generator
  uniform_int_distribution<unsigned long> distribution(0,0xFFFFFFFFFFFFFFFF);
  unsigned long input = distribution(generator);

  cout << "Randdom number: " << input << endl;
  cout << "In bits: " << bitset<kSize>(input) << endl;

  cout << "Parity: Naive: " << ParityNaive(input) << "\n\t ParityDropBit: " << ParityDropBit(input) << "\n\t ParityCache: " << ParityCache(input) << "\n\t Parity: " << Parity(input) << endl;
  return(0);
}