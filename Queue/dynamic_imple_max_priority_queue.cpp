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
    PriorityQueue()
    {
        front = NULL;
    }
    void insert(int x)
    {
        Node* newNode = new Node();

        newNode->info = x;
        newNode->next = front;
        front = newNode;

        cout << x << " inserted successfully.\n";
    }
    void deleteMax()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;
        Node* maxNode = front;
        Node* prev = NULL;
        Node* maxPrev = NULL;
        while (temp != NULL)
        {
            if (temp->info > maxNode->info)
            {
                maxNode = temp;
                maxPrev = prev;
            }

            prev = temp;
            temp = temp->next;
        }
        if (maxNode == front)
        {
            front = front->next;
        }
        else
        {
            maxPrev->next = maxNode->next;
        }
        cout << "Deleted element: " << maxNode->info << endl;

        delete maxNode;
    }
    void peek()
    {
        if (front == NULL)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        Node* temp = front;
        Node* maxNode = front;

        while (temp != NULL)
        {
            if (temp->info > maxNode->info)
            {
                maxNode = temp;
            }

            temp = temp->next;
        }

        cout << "Peak element: " << maxNode->info << endl;
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

    cout << "\nDeleting maximum priority element:\n";
    pq.deleteMax();

    cout << "\nAfter deletion:\n";
    pq.display();

    cout << "\n";
    pq.peek();

    return 0;
}