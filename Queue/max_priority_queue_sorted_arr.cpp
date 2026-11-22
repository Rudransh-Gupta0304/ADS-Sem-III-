#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

class MaxPriorityQueue {
private:
    int arr[MAXSIZE];
    int size;

public:
    MaxPriorityQueue() {
        size = 0;
    }

    // Insert element in sorted order
    void insert(int x) {
        if (size == MAXSIZE) {
            cout << "Priority Queue is full" << endl;
            return;
        }

        int i = size - 1;

        // Shift larger elements one position to the right
        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }

        // Insert element at correct position
        arr[i + 1] = x;
        size++;
    }

    // Delete maximum element
    void deleteMax() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        cout << "Deleted element: " << arr[size - 1] << endl;
        size--;
    }

    // Display maximum element
    void peek() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        cout << "Peak element: " << arr[size - 1] << endl;
    }

    // Display queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        cout << "Priority Queue: ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    pq.display();

    pq.peek();

    pq.deleteMax();
    pq.display();

    pq.peek();

    return 0;
}