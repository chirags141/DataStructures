#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node *insert1(node *root, int data);
bool search1(node *root, int data);
int rFindMin(node *root);
int FindMin(node *root);
int FindMax(node *root);

void preOrder(node *root);
void inOrder(node *root);
void postOrder(node *root);
void LevelOrder(node *root);

node *get_node(int data)
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    new1->data = data;
    new1->left = new1->right = NULL;
    return new1;
}

node *insert1(node *root, int data)
{
    if (root == NULL)
    {
        root = get_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert1(root->left, data);
    }
    else
    {
        root->right = insert1(root->right, data);
    }
    return root;
}

bool search1(node *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
    {
        return search1(root->left, data);
    }
    else
    {
        return search1(root->right, data);
    }
}

int FindMin(node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int rFindMin(node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return rFindMin(root->left);
}

int FindMax(node *root)
{
    if (root == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void LevelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> Q;
    Q.push(root);

    while (!Q.empty())
    {

        node *currentNode = Q.front();
        Q.pop();

        cout << currentNode->data << " ";

        if (currentNode->left != NULL)
            Q.push(currentNode->left);
        if (currentNode->right != NULL)
            Q.push(currentNode->right);
    }
}

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;
    int ch, n;
    char c;

    do
    {
        cout << "For TRAVERSE                   Press [1]" << endl;
        cout << "For INSERTION                  Press [2]" << endl;
        cout << "For SEARCHING                  Press [3]" << endl;
        cout << "For MINIMUM ELEMENT            Press [4]" << endl;
        cout << "For MAXIMUM ELEMENT            Press [5]" << endl;
        cout << "For EXIT                       Press [0]" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Preorder Traversal: ";
            preOrder(root);
            cout << endl;
            cout << "Inorder Traversal: ";
            inOrder(root);
            cout << endl;
            cout << "Postorder Traversal: ";
            postOrder(root);
            cout << endl;
            cout << "Level Order Traversal: ";
            LevelOrder(root);
            cout << endl;
            break;
        case 2:
            cout << "Enter the number to be inserted : ";
            cin >> n;
            root = insert1(root, n);
            break;
        case 3:
            cout << "Enter the number to be searched: ";
            cin >> n;
            if (search1(root, n) == true)
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 4:
        {
            int minimum = rFindMin(root);
            cout << "Minimum number in tree is: " << minimum << endl;
            break;
        }
        case 5:
        {
            int maximum = FindMax(root);
            cout << "maximum number in tree is: " << maximum;
            break;
        }

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
