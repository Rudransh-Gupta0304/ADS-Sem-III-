#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 5

int q[MAXSIZE];
int front = -1, rear = -1;

bool overflow(){
    return rear == MAXSIZE - 1 ;
}
bool underflow(){
    return front == -1 ;
}
void enqueue(int value)
{
    if(overflow())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
        q[rear] = value;
    }
    else
    {
        rear++;
        q[rear] = value;
    }
}

void peek()
{
    if(underflow())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Front element is: " << q[front] << endl;
}

void display()
{
    if(underflow())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements are: ";

    for(int i = front; i <= rear; i++)
    {
        cout << q[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice, value;

    while(true)
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Peek";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                peek();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}