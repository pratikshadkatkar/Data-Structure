#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int queue[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int ticket) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! No more requests can be added.\n";
            return;
        }

        if (front == -1)
            front = 0;

        queue[++rear] = ticket;
        cout << "Ticket reservation request " << ticket
             << " added.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No requests available.\n";
            return;
        }

        cout << "Ticket reservation request " << queue[front]
             << " processed.\n";

        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Pending ticket requests: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, ticket;

    do {
        cout << "\n--- Ticket Reservation Queue ---\n";
        cout << "1. Add Reservation Request\n";
        cout << "2. Process Reservation Request\n";
        cout << "3. Display Pending Requests\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ticket/request number: ";
            cin >> ticket;
            q.enqueue(ticket);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

