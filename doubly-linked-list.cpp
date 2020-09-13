
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *start;
int length = 0;

void create_dll();
void traverse();
void insert_begin(int item);
void insert_end(int item);
void insert_at_pos(int item, int pos);
void delete_begin();
void delete_end();
void delete_at_pos(int pos);

// If start is declared as a global variable then there is no need to pass it as an argument in a function

node *get_node()
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    new1->next = NULL;
    new1->prev = NULL;
    return new1;
}

void free_node(node *new1)
{
    free(new1);
}

void create_dll()
{
    int x;
    node *new1 = get_node();
    cout << "Enter data: ";
    cin >> x;
    new1->data = x;
    new1->prev = NULL;
    new1->next = NULL;
    if (start == NULL)
    {
        start = new1;
        length++;
        traverse();

        return;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new1;
        new1->prev = temp;
        length++;
        traverse();
    }
}

void insert_begin(int item)
{
    node *new1 = get_node();
    new1->data = item;
    if (start == NULL)
    {
        start = new1;
        length++;
        traverse();
        return;
    }

    new1->next = start;
    start->prev = new1;
    start = new1;
    length++;
    traverse();
}

void insert_end(int item)
{
    node *temp, *new1 = get_node();

    new1->data = item;
    temp = start;
    if (temp == NULL)
    {
        start = new1;
        traverse();
        length++;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new1;
        new1->prev = temp;
        traverse();
        length++;
    }
}

void insert_at_pos(int item, int pos)
{
    if (pos < 1 || pos > length)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    else if (pos == 1)
    {
        insert_begin(item);
    }
    else
    {
        node *temp, *new1 = get_node();
        new1->data = item;
        int i = 1;
        temp = start;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        new1->next = temp->next;
        (temp->next)->prev = new1;
        temp->next = new1;
        new1->prev = temp;

        new1->prev = temp;
        length++;
        traverse();
    }
}

void delete_begin()
{
    node *temp = start;

    if (start == NULL)
    {
        cout << "List is empty" << endl;
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
        start = start->next;
        start->prev = NULL;
        free_node(temp);
        length--;
        traverse();
    }
}

void delete_end()
{

    if (start == NULL)
    {
        cout << "List is empty" << endl;
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
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free_node(temp);
        length--;
        traverse();
    }
}
void delete_at_pos(int pos)
{
    if (start == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    if (pos > length)
    {
        cout << "Wrong Position" << endl;
        return;
    }
    else if (pos == 1)
    {
        delete_begin();
    }
    else if (pos == length)
    {
        delete_end();
    }
    else
    {
        node *temp = start;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
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

    do
    {
        cout << "For TRAVERSE                   Press [1]" << endl;
        cout << "For INSERTION AT BEGINNING     Press [2]" << endl;
        cout << "For INSERTION AT END           Press [3]" << endl;
        cout << "For INSERTION AT A POSITION    Press [4]" << endl;
        cout << "For DELETION AT BEGINNING      Press [5]" << endl;
        cout << "For DELETION AT END            Press [6]" << endl;
        cout << "For DELETION AT A POSITION     Press [7]" << endl;
        cout << "For REVERSING                  Press [9]" << endl;
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
        case 9:
            //  reverse_list();
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
