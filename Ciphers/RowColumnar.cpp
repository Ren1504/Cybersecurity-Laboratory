#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string rowColumnEncrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyLength = key.length();

    vector<pair<char, int>> sortedKey;
    for (int i = 0; i < keyLength; i++) {
        sortedKey.push_back({key[i], i});
    }
    sort(sortedKey.begin(), sortedKey.end());

    int numRows = (plaintext.length() + keyLength - 1) / keyLength;
    vector<vector<char>> matrix(numRows, vector<char>(keyLength, ' '));

    for (int i = 0; i < plaintext.length(); i++) {
        matrix[i / keyLength][i % keyLength] = plaintext[i];
    }

    for (const auto &pair : sortedKey) {
        int col = pair.second;
        for (int row = 0; row < numRows; row++) {
            ciphertext += matrix[row][col];
        }
    }
    
    return ciphertext;
}

string rowColumnDecrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyLength = key.length();

    vector<pair<char, int>> sortedKey;
    for (int i = 0; i < keyLength; i++) {
        sortedKey.push_back({key[i], i});
    }
    sort(sortedKey.begin(), sortedKey.end());

    int numRows = (ciphertext.length() + keyLength - 1) / keyLength;
    vector<vector<char>> matrix(numRows, vector<char>(keyLength, ' '));
    
    int index = 0;
    for (const auto &pair : sortedKey) {
        int col = pair.second;
        for (int row = 0; row < numRows; row++) {
            matrix[row][col] = ciphertext[index++];
        }
    }
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            plaintext += matrix[i][j];
        }
    }
    
    return plaintext;
}

int main() {
    string input, output, key;
    char choice;

    cout << "Choose E for Encrypt, D for Decrypt, Q to Quit: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter the text: ";
    getline(cin, input);

    cout << "Enter the key: ";
    getline(cin, key);

    if (choice == 'E' || choice == 'e') {
        output = rowColumnEncrypt(input, key);
        cout << "Encrypted Text: " << output << endl;
    } else if (choice == 'D' || choice == 'd') {
        output = rowColumnDecrypt(input, key);
        cout << "Decrypted Text: " << output << endl;
    }

return 0;
}