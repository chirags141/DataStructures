#include <iostream>
using namespace std;

class Queue
{
    int arr[10];
    int front = -1, rear = -1;

public:
    void enqueue(int data);
    void dequeue();
    int isEmpty();
    int isFull();
    int front_element();
    void display();
};

int Queue ::isFull()
{
    if (rear == 9)
    {
        cout << "Queue is full" << endl;
        return 1;
    }
    return 0;
}

int Queue ::isEmpty()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
        return 1;
    }
    return 0;
}

void Queue ::enqueue(int data)
{
    if (isFull())
    {
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    arr[rear] = data;
}

void Queue ::dequeue()
{
    if (isEmpty())
    {
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = front + 1;
    }
}

void Queue ::display()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    Queue obj;
    int ch, val;
    cout << "1) Insert in Queue" << endl;
    cout << "2) Delete from Queue" << endl;
    cout << "3) Display Queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << endl;
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            if (obj.isFull())
            {
                break;
            }
            else
            {
                cout << "Enter value to be pushed:" << endl;
                cin >> val;
                obj.enqueue(val);
                break;
            }
        }
        case 2:
        {
            obj.dequeue();
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
