#include <iostream>
#include <algorithm>
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
int height(Node *p)
{
    if(p == NULL)
        return -1;
    return 1 + max(height(p->left), height(p->right));
}
int main()
{
    Node *root = createTree();
    cout << "Height of Binary Tree = " << height(root);
    return 0;
}