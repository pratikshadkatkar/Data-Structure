#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int ticket) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ticket;
    printf("Ticket request added: %d\n", ticket);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Ticket request processed: %d\n", queue[front++]);
    if (front > rear)
        front = rear = -1;
}
void display() {
    if (front == -1) {
        printf("No pending requests.\n");
        return;
    }
    printf("Pending requests: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    display();
    dequeue();
    display();
    return 0;
}