#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *top = NULL;

// Push Operation
void push(int x)
{
    Node *temp = new Node;
    temp->info = x;
    temp->next = top;
    top = temp;

    cout << x << " inserted into stack." << endl;
}

// Pop Operation
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }

    Node *temp = top;
    cout << temp->info << " deleted from stack." << endl;

    top = top->next;
    delete temp;
}

// Peek Operation
void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }

    cout << "Top Element: " << top->info << endl;
}

// Traverse Operation
void traverse()
{
    if (top == NULL)
    {
        cout << "Stack is Empty." << endl;
        return;
    }

    cout << "Stack Elements (Top to Bottom): ";

    Node *temp = top;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int ch, value;

    do
    {
        cout << "\n========== STACK USING LINKED LIST ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Traverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            traverse();
            break;

        case 5:
            cout << "Program Exited Successfully." << endl;
            break;

        default:
            cout << "Invalid Choice! Please enter a valid option." << endl;
        }

    } while (ch != 5);

    return 0;
}