#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Create Binary Tree
Node* createTree()
{
    int value;

    cout << "Enter data (-1 for no node): ";
    cin >> value;

    if(value == -1)
        return NULL;

    Node *p = new Node(value);

    cout << "Enter left child of " << value << endl;
    p->left = createTree();

    cout << "Enter right child of " << value << endl;
    p->right = createTree();

    return p;
}

// Total number of nodes
int totalcount(Node *p)
{
    if(p == NULL)
        return 0;

    return 1 + totalcount(p->left) + totalcount(p->right);
}

// Nodes having exactly one child
int onechild(Node *p)
{
    if(p == NULL)
        return 0;

    int count = 0;

    if((p->left != NULL && p->right == NULL) ||
       (p->left == NULL && p->right != NULL))
        count = 1;

    return count + onechild(p->left) + onechild(p->right);
}

// Nodes having exactly two children
int twochild(Node *p)
{
    if(p == NULL)
        return 0;

    int count = 0;

    if(p->left != NULL && p->right != NULL)
        count = 1;

    return count + twochild(p->left) + twochild(p->right);
}

int main()
{
    Node *root = createTree();

    cout << "\nTotal Nodes = " << totalcount(root) << endl;

    cout << "One Child Nodes = " << onechild(root) << endl;

    cout << "Two Child Nodes = " << twochild(root) << endl;

    return 0;
}