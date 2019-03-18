// Get all subset of a set.
// O(n2^n)

#ifndef GET_SUBSET_H // include guard
#define GET_SUBSET_H
#pragma once

#include <vector>
#include <iostream>

typedef std::vector<int> Set;
typedef std::vector<std::vector<int>> PowerSet;
namespace GetSubsets {
  namespace Recursive {
    PowerSet get_all_subsets( Set set, int index);
    void test_get_all_subsets();


    PowerSet get_all_subsets( Set set, int index) {
      PowerSet allSubsets;
      if (set.size() == index) {// Base case
        Set newSet= {0};
        allSubsets.push_back(newSet);
      } else {
        allSubsets = get_all_subsets(set, index + 1);
        int item = set.at(index);
        PowerSet moreSubsets;

        for (auto const &s : allSubsets) {
          Set newSubSet = Set(s);
          newSubSet.push_back(item);
          moreSubsets.push_back(newSubSet);
        }
        allSubsets.insert(allSubsets.end(), moreSubsets.begin(), moreSubsets.end());
      }
      return allSubsets;
    }

    void test_get_all_subsets() {
      using namespace std;
      Set set = {1,2,3};
      PowerSet p = get_all_subsets(set, 0);
      
      for (auto const &s : p) {
        for (auto const &item: s) {
          cout << item << " | ";
        }
        cout << endl;
      }
      cout << "Total: " << p.size() << endl;
    }
  };

  namespace Loop {
    PowerSet get_all_subsets(Set set);
    Set get_new_set_at(int nthElement, Set set);
    void test_get_all_subsets();


    PowerSet get_all_subsets(Set set) {
      PowerSet all_subsets;
      int max = 1 << set.size();
      for(int i = 0; i < max; ++i) {
        Set new_set = get_new_set_at(i, set);
        all_subsets.push_back(new_set);
      }

      return all_subsets;
    }

    Set get_new_set_at(int nthElement, Set set) {
      Set subset = {0};
      int index = 0;
      for( int mask = nthElement; mask > 0; mask >>= 1) {
        if ( (mask & 1) == 1) {
          subset.push_back(set.at(index));
        }
        index++;
      }
      return subset;
    }

    void test_get_all_subsets() {
      using namespace std;
        Set set = {1,2,3};
      PowerSet p = get_all_subsets(set);
      
      for (auto const &s : p) {
        for (auto const &item: s) {
          cout << item << " | ";
        }
        cout << endl;
      }
      cout << "Total: " << p.size() << endl;
    }

  } ;
}


#endif 