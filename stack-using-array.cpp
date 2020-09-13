#include <iostream>
using namespace std;

class Stack
{
    int n = 100;
    int arr[100], top = -1;

public:
    void push(int item)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = item;
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            int item = arr[top];
            cout << "The popped element is " << arr[top] << endl;
            top--;
        }
    }

    int peek()
    {
        return arr[top];
    }

    void display()
    {
        if (top <= -1)
            cout << "Stack is empty" << endl;
        else
        {
            cout << "Stack is: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack obj;
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            obj.push(val);
            break;
        }
        case 2:
        {
            obj.pop();
            break;
        }
        case 3:
        {
            obj.display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}
