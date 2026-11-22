#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;
bool underflow()
{
    return front == NULL;
}


void enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted into queue." << endl;
}


void dequeue()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}


void peek()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Front element: " << front->data << endl;
}


void display()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;

    cout << "Queue elements: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void traverse()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;

    cout << "Traversing Queue: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "\n===== Dynamic Queue Menu =====";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Traverse";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                traverse();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}