
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left, *right;

    Node(int value) {
        info = value;
        left = right = NULL;
    }
};

// Function to calculate sum of nodes
int sumofnodes(Node *p) {
    if (p == NULL)
        return 0;
    else
        return p->info + sumofnodes(p->left) + sumofnodes(p->right);
}

int main() {
    // Creating the binary tree
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // Calculating sum
    int sum = sumofnodes(root);

    cout << "Sum of all nodes = " << sum << endl;

    return 0;
}
