#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

// Check if stack is empty
bool underflow()
{
    return q1.empty();
}

// Push
void push(int value)
{
    // Insert new element into q2
    q2.push(value);

    // Move all elements of q1 to q2
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    // Swap q1 and q2
    swap(q1, q2);

    cout << value << " pushed into stack." << endl;
}

// Pop
void pop()
{
    if(underflow())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Deleted element: " << q1.front() << endl;
    q1.pop();
}

// Peek
void peek()
{
    if(underflow())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element: " << q1.front() << endl;
}

// Display
void display()
{
    if(underflow())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    queue<int> temp = q1;

    cout << "Stack elements (Top to Bottom): ";

    while(!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
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
        cout << "\n===== Stack Using Two Queues =====";
        cout << "\n1. Push";
        cout << "\n2. Pop";
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
                push(value);
                break;

            case 2:
                pop();
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