#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *get_node(int data)
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    new1->data = data;
    new1->next = 0;
    return new1;
}
class Queue
{
public:
    node *front = 0;
    node *rear = 0;

    void enqueue(int data);
    void dequeue();
    void display();
    void peek();
    int isEmpty();
};

int Queue ::isEmpty()
{
    if (front == 0 && rear == 0)
    {
        return 1;
    }
    return 0;
}

void Queue ::enqueue(int data)
{
    node *newnode = get_node(data);
    if (isEmpty())
    {

        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void Queue ::dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return;
    }
    else if (front == rear)
    {
        node *temp;
        temp = front;
        front = 0;
        rear = 0;
        free(temp);
    }
    else
    {
        node *temp;
        temp = front;

        front = front->next;
        free(temp);
    }
}

void Queue ::display()
{
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return;
    }
    node *temp;
    temp = front;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
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

            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            obj.enqueue(val);
            break;
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
