MULTIPLICATIVE CIPHER WITH POLYNOMIAL ROLLING HASH

Description:
This project implements the Multiplicative Cipher along with a custom Polynomial Rolling Hash function.

POLYNOMIAL ROLLING HASH FUNCTION:

A Polynomial Rolling Hash is a string hashing technique that converts a sequence of characters into a single numerical value. It is widely used in applications like string matching, data integrity verification, and cryptographic preprocessing.
The main idea is to treat the string as a polynomial where each character contributes to the hash value based on its position.

Mathematical Representation:

The hash of a string is computed as

H(s) = (s₀ × p⁰ + s₁ × p¹ + s₂ × p² + ... + sₙ × pⁿ) mod m

Where:
* `s[i]` = numerical value of the i-th character
* `p` = base (a small prime number, e.g., 31)
* `m` = a large prime modulus (e.g., 10⁹ + 9)

Character Mapping:

Each character is converted into a number

* a → 1
* b → 2
* ...
* z → 26

Uppercase letters are converted to lowercase before hashing to maintain consistency.

Rolling Property

The term *rolling* comes from the fact that the hash can be updated efficiently when characters are added or removed. Instead of recomputing the entire hash, the previous hash value is reused.

In this implementation, we use an iterative form:
H = (H × p + value) mod m

This form is efficient and avoids recomputing powers separately.

Why Use Modulo?

The modulo operation ensures that:
* The hash value stays within a fixed range
* Integer overflow is avoided
* The hash remains manageable for computation
A large prime number is chosen for `m` to reduce collisions.

Collision Handling:

Different strings may produce the same hash value (called a collision). However, by choosing
* a good base `p`
* a large prime modulus `m`
the probability of collisions becomes very low.

Advantages

* Efficient computation (O(n) time complexity)
* Suitable for large strings
* Easy to implement
* Works well with pattern matching algorithms

Limitations

* Not cryptographically secure (collisions are possible)
* Not suitable for secure encryption purposes
* Only used for hashing and verification


MULTIPLICATIVE CIPHER-

Encryption Formula:
       C = (P × k) mod 26

Decryption Formula:
       P = (C × k⁻¹) mod 26

Where:
* P = Plaintext
* C = Ciphertext
* k = Key (coprime with 26)
* k⁻¹ = Modular inverse of k

Hash Function (Polynomial Rolling Hash):
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
Encrypted: judds
Hash: 17670568
Decrypted: hello

Example 2
Plaintext: world
Key: 7
Encrypted: yupzv
Hash: 21108080
Decrypted: world

Workflow
Plaintext → Encryption → Hash → Decryption → Verification

---

 Notes
* Key must be coprime with 26
* No external crypto libraries used
* Hash function implemented from scratch
