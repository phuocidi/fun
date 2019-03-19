#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* 
  Given a set of coins, there are some amounts of change that you may not be able to make with them. 
  e.g. you cannot create a change amount greater than the sum of the coins available
*/
int smallestNonconstructibleValue(vector<int> A) {
  sort(A.begin(), A.end());
  int max_constructible_value = 0;
  for (auto const& a : A) {
    if (a > max_constructible_value + 1) {
      break;
    }
    max_constructible_value += a;
  }
  return max_constructible_value + 1;
}

int main() {
  vector<int> changes = {1, 25, 1, 1, 5, 10, 1, 1};
  int smallestChange = smallestNonconstructibleValue(changes);
  printf("Expect 21\t Result: %d\n", smallestChange);

}