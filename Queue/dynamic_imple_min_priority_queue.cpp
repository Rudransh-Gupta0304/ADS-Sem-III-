#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    struct Node
    {
        int info;
        Node* next;
    };

    Node* front;

public:
    // Constructor
    PriorityQueue()
    {
        front = NULL;
    }

    // Insert element
    void insert(int x)
    {
        Node* newNode = new Node();

        newNode->info = x;
        newNode->next = front;
        front = newNode;

        cout << x << " inserted successfully.\n";
    }

    // Delete minimum priority element
    void deleteMin()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;
        Node* minNode = front;
        Node* prev = NULL;
        Node* minPrev = NULL;

        // Find minimum element
        while (temp != NULL)
        {
            if (temp->info < minNode->info)
            {
                minNode = temp;
                minPrev = prev;
            }

            prev = temp;
            temp = temp->next;
        }
        if (minNode == front)
        {
            front = front->next;
        }
        else
        {
            minPrev->next = minNode->next;
        }

        cout << "Deleted element: " << minNode->info << endl;

        delete minNode;
    }
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;
        Node* minNode = front;
        while (temp != NULL)
        {
            if (temp->info < minNode->info)
            {
                minNode = temp;
            }

            temp = temp->next;
        }

        cout << "Peek element: " << minNode->info << endl;
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Priority Queue: ";

        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(15);
    pq.insert(5);
    pq.insert(50);
    pq.insert(20);

    cout << "\nAfter insertion:\n";
    pq.display();

    cout << "\n";
    pq.peek();

    cout << "\nDeleting minimum priority element:\n";
    pq.deleteMin();

    cout << "\nAfter deletion:\n";
    pq.display();

    cout << "\n";
    pq.peek();

    return 0;
}