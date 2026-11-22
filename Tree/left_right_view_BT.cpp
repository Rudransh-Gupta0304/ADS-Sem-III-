
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

// Left View
void leftView(Node *root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();

            if (i == 0)
                cout << temp->info << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// Right View
void rightView(Node *root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();

            if (i == n - 1)
                cout << temp->info << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main() {
    // Creating Binary Tree
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Left View: ";
    leftView(root);

    cout << endl;

    cout << "Right View: ";
    rightView(root);

    return 0;
}
