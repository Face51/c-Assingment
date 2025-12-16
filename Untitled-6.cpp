#include <iostream>
#include <cctype>   // for tolower()
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    // Convert character to lowercase
    ch = tolower(ch);

    // Check for vowels
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        cout << "The character is a Vowel.";
    } else {
        cout << "The character is a Consonant.";
    }

    return 0;
}
