#include "stack.h"

using namespace std;

Stack::Stack(int s = 10)
{   
    if (s <= 0)
    {
        cout << endl << "Array cannot have 0 or negative size! Please enter again: ";
        *this = Stack(integerInput());
    }
    else
    {
        size = s;
        arr = new (nothrow) int[size];
        if (arr == nullptr)
        {
            cout << endl << "Unable to allocate memory for the array. Please restart the application";
            abort;
        }
        top = -1;

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
}

void Stack::push(int elem)
{
    if (elem == 0)
    {
        cout << endl << "0 is not a valid data value! Please enter again: ";
        push(integerInput());
    }
    
    if (size - 1 == top)
    {
        cout << endl << "Stack overflow! No more elements can be inserted!" << endl;
    }
    else
    {
        arr[top + 1] = elem;
        top++;
        cout << endl << "Value successfully pushed!" << endl;
    }
}

int Stack::pop()
{
    int temp;

    if (top == -1)
    {
        cout << endl << "Stack underflow! No more elements can be removed!" << endl;
        return 0;
    }
    else
    {
        temp = arr[top];
        arr[top] = 0;
        top--;
        return temp;
    }
}

void Stack::display()
{
    if (top == -1)
    {
        cout << endl << "The Stack is empty!" << endl;
        return;
    }
    
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }

    cout << endl;
}

void clearScreen()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

int integerInput()
{
    int n;

    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        cout << endl << "Invalid integer input! Please try again with correct input: ";
    }

    return n;
}