#include <iostream>
using namespace std;
string caesar(string text, int shift, bool encrypt)
{
    string result = "";
    for (char c : text)
    {
        if (isalpha(c))
        {

            char base = (isupper(c) ? 'A' : 'a');
            int shiftAmount = (encrypt ? shift : 26 - shift);
            result += char((c - base + shiftAmount) % 26 + base);
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
    string input, output;
    char choice;
    int shift;
    cout << "Choose E for Encrypt, D for Decrypt, Q to Quit: ";
    cin >> choice;
    cin.ignore();
    cout << "Enter the text: ";
    getline(cin, input);
    cout << "Enter the shift value: ";
    cin >> shift;
    if (choice == 'E' || choice == 'e')
        output = caesar(input, shift, true);
    else if (choice == 'D' || choice == 'd')
        output = caesar(input, shift, false);
    cout << "Result: " << output << endl;
    return 0;
}