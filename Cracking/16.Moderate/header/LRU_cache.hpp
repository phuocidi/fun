#ifndef MODERATE_LRU_CACHE_H
#define MODERATE_LRU_CACHE_H
#pragma once

#include <list>
#include <utility>
#include <unordered_map>
#include <string>

class LRU {
  private:
    typedef std::list<int> LI;
    typedef std::pair<std::string, LI::iterator> PII;
    typedef std::unordered_map<int, PII> HIPII;

    HIPII cache;
    LI used;
    int _capacity;

    void touch(HIPII::iterator it);

  public:
    LRU(int capacity);
    std::string get(int key);
    void set(int key, std::string value);
    static void demo();
    const std::string to_string_key();
    const std::string to_string_cache();
    
};

#endif