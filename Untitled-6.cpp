#include <iostream>
#include <cctype>   // for tolower() and isalpha()
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    if (isalpha(ch)) {           // Check if it's a letter
        ch = tolower(ch);        // Convert to lowercase
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            cout << "The character is a Vowel.";
        } else {
            cout << "The character is a Consonant.";
        }
    } else {
        cout << "The character is not an alphabet letter.";
    }

    return 0;
}
