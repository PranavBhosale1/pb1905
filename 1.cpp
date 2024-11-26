#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* top = nullptr;

void push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "Deleted " << temp->data << endl;
    delete temp;
}

bool isEmpty() {
    return top == nullptr;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
