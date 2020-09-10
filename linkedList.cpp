#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *start;
int length = 0;

void traverse();
void insert_begin(int item);
void insert_at_pos(int item, int pos);
void insert_end(int);
void delete_node(int);
// If start is declared as a global variable then there is no need to pass it as an argument in a function

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

void insert_begin(int item)
{
    node *new1 = get_node();
    new1->data = item;
    new1->next = start;
    start = new1;

    traverse();

    length++;
}
// Insert at a position
void insert_at_pos(int item, int pos)
{
    int i = 1;

    if (pos == 1)
    {
        insert_begin(item);
    }
    else if (pos > length)
    {
        cout << "Invalid Position or List is null" << endl;
    }
    else
    {
        node *temp = start;
        node *new1 = get_node();
        new1->data = item;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        new1->next = temp->next;
        temp->next = new1;
        traverse();
        length++;
    }
}

void insert_end(int item)
{
    node *temp = start;
    node *new1 = get_node();
    new1->data = item;
    new1->next = NULL;

    if (temp == NULL)
    {
        start = new1;
        traverse();
        length++;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new1;
    traverse();
    length++;
}
void delete_begin()
{
    node *temp = start;
    if (start == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    start = start->next;
    free_node(temp);
    length--;
    traverse();
}

void delete_end()
{

    if (start == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    else if (start->next == NULL)
    {
        node *temp = start;
        start = NULL;
        free_node(temp);
        length--;
        traverse();
    }
    else
    {
        node *temp = start;
        node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free_node(temp);
        length--;
    }

    traverse();
}
void delete_at_pos(int pos)
{
    if (start == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    int i = 1;
    if (pos > length)
    {
        cout << "Incorrect Position" << endl;
    }
    else if (pos == 1)
    {
        delete_begin();
    }
    else
    {
        node *temp = start;
        node *prev = NULL;

        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free_node(temp);
        length--;
        traverse();
    }
}

void traverse()
{
    node *temp = start;
    if (temp == NULL)
    {
        cout << "No element found" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    start = NULL;
    int ch, n, pos;
    char c;

    // insert_end(1);
    // insert_end(2);
    // insert_end(3);

    do
    {
        cout << "For TRAVERSE                   Press [1]" << endl;
        cout << "For INSERTION AT BEGINNING     Press [2]" << endl;
        cout << "For INSERTION AT END           Press [3]" << endl;
        cout << "For INSERTION AT A POSITION    Press [4]" << endl;
        cout << "For DELETION AT BEGINNING      Press [5]" << endl;
        cout << "For DELETION AT END            Press [6]" << endl;
        cout << "For DELETION AT A POSITION     Press [7]" << endl;
        cout << "For LENGTH                     Press [8]" << endl;
        cout << "For EXIT                       Press [0]" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            traverse();
            break;
        case 2:
            cout << "Enter the number to be inserted : ";
            cin >> n;
            insert_begin(n);

            break;
        case 3:
            cout << "Enter the number to insert : ";
            cin >> n;
            insert_end(n);
            break;
        case 4:
            cout << "Enter the number and position to insert : ";
            cin >> n >> pos;
            insert_at_pos(n, pos);
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            cout << "Enter the position to delete: ";
            cin >> pos;
            delete_at_pos(pos);
            break;
        case 8:
            cout << "Length of Linked List " << length << endl;
            break;
        case 0:
            cout << "Program Ended" << endl;
            break;
        default:
            cout << "Wrong choice entered!!" << endl;
            break;
        }
        cout << "\n\n";
    } while (ch != 0);
}
