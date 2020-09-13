#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *get_node()
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    return new1;
}

void free_node(node *new1)
{
    free(new1);
}

class Stack
{
    node *start = NULL;

public:
    void push(int item)
    {
        node *new1 = get_node();
        new1->data = item;
        new1->next = start;
        start = new1;
    }

    void pop()
    {
        if (start == NULL)
            cout << "Stack Underflow" << endl;
        else
        {
            node *temp;
            temp = start;
            cout << "The element popped out is: " << temp->data << endl;
            start = start->next;
            free_node(temp);
        }
    }

    void display()
    {
        if (start == NULL)
            cout << "Stack is empty" << endl;
        else
        {
            node *temp = start;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
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
