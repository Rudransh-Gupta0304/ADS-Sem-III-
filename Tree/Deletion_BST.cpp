
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Insert Node
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

// Delete Node
Node* deleteNode(Node* root, int x)
{
    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else
        {
            Node* temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
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

    cout << "Enter nodes: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nBefore Deletion: ";
    inorder(root);

    cout << "\nEnter node to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}
