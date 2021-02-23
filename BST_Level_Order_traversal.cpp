#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;


void LevelOrder(node *root);
node* insert1(node* root,int data);
node *get_node(int data);

void LevelOrder(node *root)
{
    if(root == NULL) return;

    queue<node*> Q;
    Q.push(root);

    while(!Q.empty()){

    node *currentNode = Q.front();
    Q.pop();

    cout<<currentNode->data<<" ";

    if(currentNode->left != NULL) Q.push(currentNode->left);
    if(currentNode->right != NULL) Q.push(currentNode->right);
    }


}

node *get_node(int data)
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    new1->data = data;
    new1->left = new1->right = NULL;
    return new1;
}


node* insert1(node* root,int data)
{
    if(root == NULL){
        root = get_node(data);
        return root;
    }
    else if(data <= root->data){
        root->left=insert1(root->left,data);
    }
    else{
        root->right = insert1(root->right,data);
    }
    return root;
}


int main()
{
    root =insert1(root,15);
    root =insert1(root,10);
    root =insert1(root,20);
    root =insert1(root,25);
    root =insert1(root,8);
    root =insert1(root,12);
    root =insert1(root,1);

    LevelOrder(root);
}