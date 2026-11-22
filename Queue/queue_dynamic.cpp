#include <iostream>
using namespace std;

class Queue {
private:
    int *queue;
    int front, rear, size;

public:
    Queue(int n) {
        size = n;
        queue = new int[size];

        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << queue[front] << " deleted from queue." << endl;

        front++;

        // Reset queue when all elements are removed
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Peek
    void peek() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Front element: " << queue[front] << endl;
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Queue() {
        delete[] queue;
    }
};

int main() {
    int n;

    cout << "Enter size of queue: ";
    cin >> n;

    Queue q(n);

    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}