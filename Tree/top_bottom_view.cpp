
#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int info;
    Node *left, *right;

    Node(int value) {
        info = value;
        left = right = NULL;
    }
};

// Top View
void topView(Node *root) {
    if (root == NULL)
        return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node *temp = p.first;
        int hd = p.second;

        // Store only the first node at each HD
        if (mp.find(hd) == mp.end())
            mp[hd] = temp->info;

        if (temp->left != NULL)
            q.push({temp->left, hd - 1});

        if (temp->right != NULL)
            q.push({temp->right, hd + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
}

// Bottom View
void bottomView(Node *root) {
    if (root == NULL)
        return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node *temp = p.first;
        int hd = p.second;

        // Update node at each HD
        mp[hd] = temp->info;

        if (temp->left != NULL)
            q.push({temp->left, hd - 1});

        if (temp->right != NULL)
            q.push({temp->right, hd + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
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

    cout << "Top View: ";
    topView(root);

    cout << endl;

    cout << "Bottom View: ";
    bottomView(root);

    return 0;
}
