#include <iostream>
#include <string>
using namespace std;

// Simple polynomial rolling hash
long long computeHash(string text) {
    const int p = 31;        // base
    const int m = 1e9 + 9;   // large prime

    long long hash = 0;
    long long power = 1;

    for (char c : text) {
        hash = (hash + (c - 'a' + 1) * power) % m;
        power = (power * p) % m;
    }

    return hash;
}