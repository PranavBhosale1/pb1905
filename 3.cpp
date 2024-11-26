#include <iostream>
#include <string>
using namespace std;

class Assigner {
private:
    int front, rear, size, count;
    string* orders; // dynamically allocated array to store orders

public:
    Assigner() {
        cout << "Enter the number of orders: ";
        cin >> size;
        orders = new string[size];
        front = rear = count = 0;
    }

    void enqueue() {
        if (count == size) {
            cout << "Cannot take more orders" << endl;
        } else {
            cout << "Enter Name of Order: ";
            string orderName;
            cin >> orderName;
            orders[rear] = orderName;
            rear = (rear + 1) % size;
            count++;
        }
    }

    void dequeue() {
        if (count == 0) {
            cout << "No order in queue" << endl;
        } else {
            cout << "Order for " << orders[front] << " is being served." << endl;
            front = (front + 1) % size;
            count--;
        }
    }

    void display() {
        if (count == 0) {
            cout << "No orders to display" << endl;
            return;
        }
        cout << "Pizza orders ready for the following people:" << endl;
        for (int i = 0; i < count; ++i) {
            int index = (front + i) % size;
            cout << "Order ready for " << orders[index] << endl;
        }
    }
};

int main() {
    Assigner c;
    int choice;
    do {
        cout << "Refer to the Menu:" << endl;
        cout << "Enter 1 to add order" << endl;
        cout << "Enter 2 to remove the order" << endl;
        cout << "Enter 3 to display the orders" << endl;
        cout << "Enter 4 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                c.enqueue();
                break;
            case 2:
                c.dequeue();
                break;
            case 3:
                c.display();
                break;
            case 4:
                cout << "Orders Processed. Exiting." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
