#include <iostream>
#include <cctype>
using namespace std;

string otp(string text, string key, bool encrypt) {
    string result = "";

    if (text.length() != key.length()) {
        cout << "Text and key must have the same length for OTP." << endl;
        return "";
    }

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        char k = key[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';

            int shift = (isupper(k) ? k - 'A' : k - 'a');

            if (!encrypt) {
                shift = -shift; // For decryption
            }

            char encryptedChar = (c - base + shift + 26) % 26 + base;
            result += encryptedChar;
        } else {
            result += c;
        }
    }
    return result;
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
        output = otp(input, key, true);
        cout << "Encrypted Text: " << output << endl;
    } else if (choice == 'D' || choice == 'd') {
        output = otp(input, key, false);
        cout << "Decrypted Text: " << output << endl;
    }

    return 0;
}