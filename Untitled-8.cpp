#include <iostream>
using namespace std;

class test
{
    int x;          // data member

public:
    void input();   // member function declaration
    void display(); // member function declaration
};

// Definition of input() using SRO
void test::input()
{
    cout << "Enter value of x: ";
    cin >> x;
}

// Definition of display() using SRO
void test::display()
{
    cout << "Value of x = " << x;
}

int main()
{
    test t;     // object creation
    t.input();  // call input function
    t.display();// call display function

    return 0;
}
