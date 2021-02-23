#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node* insert1(node* root, int data);
bool search1(node* root,int data);
int rFindMin(node *root);
int FindMin(node *root);
int FindMax(node *root);

node *get_node(int data)
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    new1->data = data;
    new1->left = new1->right = NULL;
    return new1;
}

node* insert1(node *root, int data)
{
    if(root == NULL){
        root = get_node(data);
    }
    else if(data <= root->data){
        root->left = insert1(root->left,data);
    }
    else{
        root->right = insert1(root ->right,data);
    }
    return root;
}

bool search1(node *root,int data)
{
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if (data <= root->data){
        return search1(root->left,data);
    }
    else{
        return search1(root->right,data);
    }
}

int FindMin(node *root)
{
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }
    while(root->left != NULL)
        root= root->left;
    return root->data;
}

int rFindMin(node *root)
{
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return rFindMin(root->left);
}

int FindMax(node *root)
{
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }
    while(root->right!= NULL)
        root= root->right;
    return root->data;
}

int main()
{
    root =insert1(root,15);
    root =insert1(root,0);
    root =insert1(root,10);
    root =insert1(root,20);
    root =insert1(root,25);
    root =insert1(root,8);
    root =insert1(root,12);
       root =insert1(root,1);
    // Ask user to enter a number.

	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"

	if(search1(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";

	
	// Minimum Element in a tree
    int minimum = rFindMin(root);
    cout<<"Minimum number in tree is: "<<minimum<<endl;
    int maximum = FindMax(root);
    cout<<"maximum number in tree is: "<<maximum;
}
