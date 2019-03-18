#include "get_subsets.hpp"
#include <stdio.h>

 
int main() {
  GetSubsets::Recursive::test_get_all_subsets();
  GetSubsets::Loop::test_get_all_subsets();
}