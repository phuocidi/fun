#include <stdio.h>
#include <string>
#include <stdlib.h> 
#include <iostream>
#include <utility> // std::pair


using namespace std;

string clean_string(string);
bool isPadlindromes(string);
void testPadlindromes();
void _testPadlindromes(pair<bool, string> tc);

int main() {
    testPadlindromes();
	return 0;
}

bool isPadlindromes(string s) 
{
    if (s.empty()) return false;
    std::string::size_type n = s.length();
    if (n == 1) return true;
    if (n == 2 ) return s.at(0) == s.at(1);
    
    std::string::size_type nSub = n - 2;
    string substr = s.substr(1, nSub);
    return s.at(0) == s.at(n-1) && isPadlindromes(substr);  
}

string clean_string(string s) 
{
    if (s.empty()) return s;
    
    string str = "";
    for (std::string::size_type i = 0; i < s.length(); ++i) 
    {
        char c = s[i];
        if ( isalnum(c)) {
            str += tolower(c);
        }
    }
    return str;
}

void testPadlindromes() {
    pair< bool, string > testcases []= {
        make_pair(true, string("I am :IronnorI Ma, i")),
        make_pair(true, string("A Santa dog lived as a devil God at NASA.")),
        make_pair(true, string("Oh no! Don Ho!")),
        make_pair(true, string("a")),
        make_pair(true, string("vv")),
        make_pair(false, string("ab")),
        make_pair(false, string("yees")),
        };

    for (auto tc : testcases) {
        _testPadlindromes(tc);
    }
} 

void _testPadlindromes(pair<bool, string> tc) {
        string str = clean_string(tc.second);
        bool isPadlin = isPadlindromes(str);
        assert(isPadlin == tc.first);
}    

