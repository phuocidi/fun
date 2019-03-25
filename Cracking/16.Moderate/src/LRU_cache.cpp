#include "LRU_cache.hpp"
#include <iostream>
#include <vector>

using namespace std;

LRU::LRU(int capacity): _capacity(capacity){}

void LRU::touch(HIPII::iterator it) {
  int key = it->first;
  LI::iterator removeKeyIndexIt = it->second.second;
  used.erase(removeKeyIndexIt);
  used.push_front(key);
  it->second.second = used.begin();
}

string LRU::get(int key) {
  auto it = cache.find(key);
  if(it == cache.end())
  {
    try 
    {
      throw "NO key found";
    } 
    catch (const char *msg) 
    {
      cerr << msg << endl;
    }
  }
    
  touch(it);
  cout << to_string_key() << endl;
  cout << to_string_cache() << endl;
  return it->second.first;
}

void LRU::set(int key, string value) {
  auto it = cache.find(key);
  if (it != cache.end())
  {
    touch(it);
  }
  else 
  {
    if (cache.size() == _capacity) 
    {
      cache.erase(used.back());
      used.pop_back();
    }
    used.push_front(key);
  }

  cache[key] = { value, used.begin()};
  cout << to_string_key() << endl;
  cout << to_string_cache() << endl;
}

const std::string LRU::to_string_key() {
  std::string str;
  str.append("| ");
  for(const auto &i : used) {
  str.append(std::to_string(i));
  str.append(" | ");
  }
  str.append("\n");
  return str;
}

const std::string LRU::to_string_cache() {
  std::string str;
  str.append("| ");
  for (const auto &p : cache) {
    string val = p.second.first;
    int key = *(p.second.second);
    str.append("{ ");
    str.append(std::to_string(key));
    str.append(": ");
    str.append(val);
    str.append(" }");
    str.append(" | ");
  }
  str.append("\n");
  return str;
}

void LRU::demo() {
  const int kCache_size = 3;
  LRU cache {kCache_size};
  vector<string> val {"a", "b", "c", "d", "e","f"};
  for (size_t i = 0; i < val.size(); ++i) {
    int index = (i % kCache_size) + 1; 
    cache.set( index, val[i]);
  }
  cout << endl;
  const string &astr = cache.get(1);
}

