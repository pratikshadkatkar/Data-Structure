#include <iostream>
#include <string>
using namespace std;
#define MAX 5

class ArrayStack {
    string stack[MAX];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(string page) {
        if (top == MAX - 1)
            cout << "Stack Overflow" << endl;
        else
            stack[++top] = page;
    }

    void pop() {
        if (top == -1)
            cout << "No previous page" << endl;
        else
            cout << "Back to: " << stack[top--] << endl;
    }
};
class LinkedStack {
    struct Node {
        string page;
        Node* next;
    };

    Node* top;

public:
    LinkedStack() {
        top = NULL;
    }

    void push(string page) {
        Node* newNode = new Node;
        newNode->page = page;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL)
            cout << "No previous page" << endl;
        else {
            cout << "Back to: " << top->page << endl;

            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {

    cout << "STACK USING ARRAY" << endl;

    ArrayStack a;

    a.push("Google");
    a.push("YouTube");
    a.push("Instagram");

    a.pop();
    a.pop();


    cout << "\nSTACK USING LINKED LIST" << endl;

    LinkedStack l;

    l.push("Google");
    l.push("YouTube");
    l.push("Instagram");

    l.pop();
    l.pop();

    return 0;
}

