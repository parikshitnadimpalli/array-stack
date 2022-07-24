#include <iostream>
#include <new>
#include <string>
#include <limits>
#include <cstdlib>

class Stack
{
    int *arr, size , top;

    public:
    Stack(int);

    void push(int);
    int pop();
    void display();

    inline int count() { return top + 1; }
};

void clearScreen();
int integerInput();