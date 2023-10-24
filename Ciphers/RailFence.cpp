#include <iostream>
#include <string>
using namespace std;

string railFenceEncrypt(string plaintext, int rails) {
    int len = plaintext.length();
    string ciphertext = "";
    
    for (int i = 0; i < rails; i++) {
        for (int j = i; j < len; j += rails) {
            ciphertext += plaintext[j];
            if (i > 0 && i < rails - 1) {
                int k = j + 2 * (rails - i - 1);
                if (k < len)
                    ciphertext += plaintext[k];
            }
        }
    }
    return ciphertext;
}

string railFenceDecrypt(string ciphertext, int rails) {
    int len = ciphertext.length();
    string plaintext(len, ' ');
    int cycle = 2 * (rails - 1);
    
    int k = 0;
    for (int i = 0; i < rails; i++) {
        int j = i;
        while (j < len) {
            plaintext[j] = ciphertext[k++];
            int next = j + cycle - 2 * i;
            if (i > 0 && i < rails - 1 && next < len)
                plaintext[next] = ciphertext[k++];
            j += cycle;
        }
    }
    return plaintext;
}

int main() {
    string input, output;
    char choice;
    int rails;

    cout << "Choose E for Encrypt, D for Decrypt, Q to Quit: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter the text: ";
    getline(cin, input);

    cout << "Enter the number of rails: ";
    cin >> rails;

    if (choice == 'E' || choice == 'e') {
        output = railFenceEncrypt(input, rails);
        cout << "Encrypted Text: " << output << endl;
    } else if (choice == 'D' || choice == 'd') {
        output = railFenceDecrypt(input, rails);
        cout << "Decrypted Text: " << output << endl;
    }

    return 0;
}