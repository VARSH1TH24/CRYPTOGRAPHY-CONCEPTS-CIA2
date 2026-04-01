#include <iostream>
#include <string>
using namespace std;

// Function declarations
string encrypt(string, int);
string decrypt(string, int);
long long computeHash(string);

int main() {
    string text;
    int key;

    cout << "Enter plaintext: ";
    cin >> text;

    cout << "Enter key (coprime with 26): ";
    cin >> key;

    string cipher = encrypt(text, key);
    long long hashValue = computeHash(cipher);
    string decrypted = decrypt(cipher, key);

    cout << "\nEncrypted: " << cipher;
    cout << "\nHash: " << hashValue;
    cout << "\nDecrypted: " << decrypted << endl;

    return 0;
}