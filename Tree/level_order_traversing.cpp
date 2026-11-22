
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int info;
    Node *left, *right;

    Node(int value) {
        info = value;
        left = right = NULL;
    }
};

// Level Order Traversal
void levelOrder(Node *root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << temp->info << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    // Creating Binary Tree
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}
