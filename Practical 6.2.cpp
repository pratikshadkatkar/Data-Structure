#include <iostream>
using namespace std;

class Node {
public:
    int ticket;
    Node* next;

    Node(int t) {
        ticket = t;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int ticket) {
        Node* newNode = new Node(ticket);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Ticket reservation request " << ticket
             << " added.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow! No requests available.\n";
            return;
        }

        Node* temp = front;

        cout << "Ticket reservation request " << front->ticket
             << " processed.\n";

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Pending ticket requests: ";

        while (temp != NULL) {
            cout << temp->ticket << " ";
            temp = temp->next;
        }

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

