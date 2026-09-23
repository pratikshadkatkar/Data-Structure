#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Add request
    void enqueue(int request) {
        // Queue is full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full!\n";
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = request;

        cout << "Request " << request << " added.\n";
    }

    // Remove request
    int dequeue() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return -1;
        }

        int request = queue[front];

        // Only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }

        return request;
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Requests: ";

        int i = front;

        while (true) {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }

    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    CircularQueue normalQueue;
    CircularQueue priorityQueue;

    int choice, request;

    do {
        cout << "\n===== CALL CENTRE REQUEST HANDLING =====\n";
        cout << "1. Add Normal Customer Request\n";
        cout << "2. Add Priority Customer Request\n";
        cout << "3. Handle Next Request\n";
        cout << "4. Display Normal Requests\n";
        cout << "5. Display Priority Requests\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter request number: ";
            cin >> request;
            normalQueue.enqueue(request);
            break;

        case 2:
            cout << "Enter priority request number: ";
            cin >> request;
            priorityQueue.enqueue(request);
            break;

        case 3:
            // Priority customers are handled first
            if (!priorityQueue.isEmpty()) {
                request = priorityQueue.dequeue();
                cout << "Handling PRIORITY request: "
                     << request << endl;
            }
            else if (!normalQueue.isEmpty()) {
                request = normalQueue.dequeue();
                cout << "Handling NORMAL request: "
                     << request << endl;
            }
            else {
                cout << "No customer requests available.\n";
            }
            break;

        case 4:
            cout << "Normal Customer Queue:\n";
            normalQueue.display();
            break;

        case 5:
            cout << "Priority Customer Queue:\n";
            priorityQueue.display();
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

