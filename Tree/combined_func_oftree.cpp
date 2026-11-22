#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *left;
    Node *right;
};

Node *create()
{
    int x;
    cout << "Enter -1 for no data: ";
    cin >> x;

    if (x == -1)
        return NULL;
    else
    {
        Node *p = new Node();
        p->info = x;

        cout << "Enter left child of " << x << endl;
        p->left = create();

        cout << "Enter right child of " << x << endl;
        p->right = create();

        return p;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->info << " ";
}

int leafnode_count(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return leafnode_count(root->left) + leafnode_count(root->right);
}

int internalnode_count(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1 + internalnode_count(root->left) + internalnode_count(root->right);
}

int totalcount(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return (1 + totalcount(p->left) + totalcount(p->right));
}

int countSingleChild(Node *p)
{
    if (p == NULL)
        return 0;

    int count = 0;

    if ((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL))
        count++;

    return count + countSingleChild(p->left) + countSingleChild(p->right);
}

int countTwoChild(Node *p)
{
    if (p == NULL)
        return 0;

    int count = 0;

    if (p->left != NULL && p->right != NULL)
        count++;

    return count + countTwoChild(p->left) + countTwoChild(p->right);
}

int height(Node* p)
{
    if(p==NULL)
        return 0;

    return 1+max(height(p->left),height(p->right));
}

int sumofnodes(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return p->info + sumofnodes(p->left) + sumofnodes(p->right);
}

int main()
{
    Node *root = create();
    cout<<endl;
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << leafnode_count(root) << endl;
    cout << internalnode_count(root) << endl;
    cout << totalcount(root) << endl;
    cout << countSingleChild(root) << endl;
    cout << countTwoChild(root) << endl;
    cout << height(root) << endl;
    cout << sumofnodes(root) << endl;

    return 0;
}