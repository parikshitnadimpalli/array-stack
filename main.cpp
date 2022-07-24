#include "stack.h"

using namespace std;

int main()
{
    cout << "--------------------Implementing Stack DS using array--------------------" << endl << endl;
    cout << "Enter the size of the array (default size is 10): ";
    Stack *s = new (nothrow) Stack(integerInput());
    if (s == nullptr)
    {
        cout << endl << "Unable to allocate memory for the Stack. Please restart the application!";
        return 0;
    }
    cout << endl << endl;

    int op, val;
    string msg;

    while(1)
    {
        cout << endl << "---------------Options---------------" << endl;
        cout << "NOTE: 0 value is not accepted as valid data" << endl;
        cout << "1. Push a value into the stack" << endl;
        cout << "2. Pop a value out of the stack" << endl;
        cout << "3. Display the values in the stack" << endl;
        cout << "4. Count the number of values in the stack" << endl;
        cout << "5. Clear the screen" << endl;
        cout << "6. Exit" << endl;
        cout << endl << "Enter your choice: ";

        op = integerInput();
        switch(op)
        {
            case 1:
                cout << endl << "Enter the value to be pushed: ";
                s->push(integerInput());
                break;
            case 2:
                val = s->pop();
                msg = val == 0 ? " " : "The popped value is: ";
                cout << endl << msg << val << endl;
                break;
            case 3:
                s->display();
                break;
            case 4:
                cout << endl << "The Stack has " << s->count() << " values." << endl;
                break;
            case 5:
                clearScreen();
                break;
            case 6:
                return 0;
                break;
            default:
                cout << endl << "Wrong option! Please try again!";
                break;
        }
    }
}