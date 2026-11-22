#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

// Check if queue is empty
bool underflow()
{
    return s1.empty() && s2.empty();
}

// Enqueue
void enqueue(int value)
{
    s1.push(value);
    cout << value << " inserted into queue." << endl;
}

// Dequeue
void dequeue()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    cout << "Deleted element: " << s2.top() << endl;
    s2.pop();
}

// Peek
void peek()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    cout << "Front element: " << s2.top() << endl;
}

// Display
void display()
{
    if(underflow())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    stack<int> temp1 = s1;
    stack<int> temp2 = s2;

    cout << "Queue elements: ";

    // Print elements from s2 (front to rear)
    while(!temp2.empty())
    {
        cout << temp2.top() << " ";
        temp2.pop();
    }

    // Reverse s1 to print in correct order
    stack<int> rev;
    while(!temp1.empty())
    {
        rev.push(temp1.top());
        temp1.pop();
    }

    while(!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }

    cout << endl;
}

// Traverse
void traverse()
{
    display();
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "\n===== Queue Using Two Stacks =====";
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
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}