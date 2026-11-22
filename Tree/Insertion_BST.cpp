
//  this program consists of the insertion and the search function in the binary search tree


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// BST Insertion
Node* insert(Node* root, int x)
{
    if (root == NULL)
    {
        Node* temp = new Node;

        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if (x < root->data)
        root->left = insert(root->left, x);

    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// BST Searching
bool search(Node* root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    else
        return search(root->right, x);
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nEnter element to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}
