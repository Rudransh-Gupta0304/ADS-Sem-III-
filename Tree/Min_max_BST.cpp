
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Find Minimum
int findMin(Node* root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

// Find Maximum
int findMax(Node* root)
{
    if (root == NULL)
        return -1;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int main()
{
    Node* root = new Node{50, NULL, NULL};

    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    root->left->left = new Node{20, NULL, NULL};
    root->left->right = new Node{40, NULL, NULL};

    root->right->left = new Node{60, NULL, NULL};
    root->right->right = new Node{80, NULL, NULL};

    cout << "Minimum element: " << findMin(root);

    cout << "\nMaximum element: " << findMax(root);

    return 0;
}
