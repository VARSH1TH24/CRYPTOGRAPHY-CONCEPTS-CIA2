Multiplicative Cipher with Polynomial Rolling Hash

Description
This project implements the Multiplicative Cipher along with a custom Polynomial Rolling Hash function.

Multiplicative Cipher

Encryption Formula:
       C = (P × k) mod 26

Decryption Formula:
       P = (C × k⁻¹) mod 26

Where:
* P = Plaintext
* C = Ciphertext
* k = Key (coprime with 26)
* k⁻¹ = Modular inverse of k

Hash Function (Polynomial Rolling Hash)
Hash(s) = (Σ (s[i] × p^i)) mod m
Where:
* p = 31
* m = 10⁹ + 9

How to Run
1. Compile:
   g++ main.cpp cipher.cpp hash.cpp -o program
2. Run:
   ./program
   
Example 1
Plaintext: hello
Key: 5
Encrypted: jgnnq
Hash: (generated value)
Decrypted: hello

Example 2
Plaintext: world
Key: 7
Encrypted: ??? (depends on key)
Hash: (generated value)
Decrypted: world

Workflow
Plaintext → Encryption → Hash → Decryption → Verification

---

 Notes
* Key must be coprime with 26
* No external crypto libraries used
* Hash function implemented from scratch
