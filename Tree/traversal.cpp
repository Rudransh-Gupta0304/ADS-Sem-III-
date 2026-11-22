#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* createTree(int &index, int arr[]) {
    int val = arr[index++];
    if (val == -1)
        return NULL;
    Node* root = new Node(val);
    root->left = createTree(index, arr);
    root->right = createTree(index, arr);
    return root;
}
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int arr[2 * n + 1];
    cout << "Enter preorder values (-1 for NULL): ";
    for (int i = 0; i < 2 * n + 1; i++) {
        cin >> arr[i];
    }
    int index = 0;
    Node* root = createTree(index, arr);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\nLevel Order Traversal: ";
    levelOrder(root);
    return 0;
}
