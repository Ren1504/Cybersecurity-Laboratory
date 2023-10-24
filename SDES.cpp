#include <iostream>
using namespace std;
// Permutation tables
int initialPermutation[] = {1, 5, 2, 0, 3, 7, 4, 6};
int finalPermutation[] = {3, 0, 2, 4, 6, 1, 7, 5};
int sdesEncrypt(int plaintext, int key)
{
    // Initial permutation (IP)
    int ip = 0;
    for (int i = 0; i < 8; i++)
    {
        ip |= ((plaintext >> i) & 1) << initialPermutation[i];
    }
    // Key generation (simplified for this example)
    int roundKey = key;
    // Round 1
    int round1 = ip ^ roundKey;

    // Round 2 (same as Round 1)
    int round2 = round1 ^ roundKey;
    // Final permutation (FP)
    int ciphertext = 0;
    for (int i = 0; i < 8; i++)
    {
        ciphertext |= ((round2 >> i) & 1) << finalPermutation[i];
    }
    return ciphertext;
}
int sdesDecrypt(int ciphertext, int key)
{
    // Initial permutation (IP)
    int ip = 0;
    for (int i = 0; i < 8; i++)
    {
        ip |= ((ciphertext >> i) & 1) << initialPermutation[i];
    }
    // Key generation (simplified for this example)
    int roundKey = key;
    // Round 2 (in decryption, the order of round keys is reversed)
    int round2 = ip ^ roundKey;
    // Round 1 (in decryption, the order of round keys is reversed)
    int round1 = round2 ^ roundKey;
    // Final permutation (FP)
    int plaintext = 0;
    for (int i = 0; i < 8; i++)
    {
        plaintext |= ((round1 >> i) & 1) << finalPermutation[i];
    }
    return plaintext;
}
int main()
{
    // Example usage
    int plaintext = 214; // 8-bit plaintext (11010110 in decimal)
    int key = 322;       // 10-bit key (1010000010 in decimal)
    // Encrypt the plaintext
    int encrypted = sdesEncrypt(plaintext, key);
    // Decrypt the ciphertext
    int decrypted = sdesDecrypt(encrypted, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}