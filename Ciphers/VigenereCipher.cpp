#include <iostream>
#include <cctype>
using namespace std;
string vigenere(string text, string key, bool encrypt)
{
    string result = "";
    int keyLength = key.length();
    for (int i = 0, j = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char keyChar = key[j % keyLength];
            int shift = keyChar - 'A'; // Assuming key is uppercase
            if (!encrypt)
            {
                shift = 26 - shift; // For decryption
            }
            char encryptedChar = (c - base + shift) % 26 + base;
            result += encryptedChar;
            j++;
        }
        else
        {
            result += c;
        }
    }
    return result;
}
int main()
{
    string input, output, key;
    char choice;
    cout << "Choose E for Encrypt, D for Decrypt, Q to Quit: ";
    cin >> choice;
    cin.ignore();
    cout << "Enter the text: ";
    getline(cin, input);
    cout << "Enter the key: ";
    cin >> key;
    if (choice == 'E' || choice == 'e')
    {
        output = vigenere(input, key, true);
        cout << "Encrypted Text: " << output << endl;
    }
    else if (choice == 'D' || choice == 'd')
    {
        output = vigenere(input, key, false);
        cout << "Decrypted Text: " << output << endl;
    }

    return 0;
}