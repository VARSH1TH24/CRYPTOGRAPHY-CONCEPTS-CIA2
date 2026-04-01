#include <iostream>
#include <string>
#include <cctype>
using namespace std;

long long computeHash(string text) {
    const long long p = 31;
    const long long m = 1000000009LL;  
    long long hash = 0;

    for (char c : text) {
        if (isalpha(c)) {
            long long value = (long long)(tolower(c) - 'a' + 1);
            hash = (hash * p + value) % m;

            if (hash < 0) hash += m;   
        }
    }

    return hash;
}
