#include <iostream>
#include <string>
using namespace std;

// Function to find modular inverse
int modInverse(int k) {
    for (int i = 1; i < 26; i++) {
        if ((k * i) % 26 == 1)
            return i;
    }
    return -1;
}

// Encryption
string encrypt(string text, int key) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int enc = (x * key) % 26;
            result += (enc + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Decryption
string decrypt(string text, int key) {
    int inv = modInverse(key);
    if (inv == -1) return "Invalid key!";

    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int dec = (x * inv) % 26;
            result += (dec + base);
        } else {
            result += c;
        }
    }
    return result;
}