#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    int number;
    
    Contact() {
        name = "";
        number = 0;
    }

    Contact(string n, int num) {
        name = n;
        number = num;
    }
};

class Node {
public:
    Contact contact;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(string name, int num) {
        contact.name = name;
        contact.number = num;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    // Insert contact directly in the tree
    void insert(string name, int number) {
        Node* newNode = new Node(name, number);
        if (!root) {
            root = newNode;
            return;
        }
        Node* current = root;
        while (true) {
            if (name < current->contact.name) {
                if (!current->left) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }

    // Search for contact by name directly in the tree
    void search(string name) {
        Node* current = root;
        while (current) {
            if (name == current->contact.name) {
                cout << "Contact found: " << current->contact.name << " - " << current->contact.number << endl;
                return;
            } else if (name < current->contact.name) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Contact not found." << endl;
    }

    // Delete a contact by name directly in the tree
    void deleteNode(string name) {
        Node* current = root;
        Node* parent = nullptr;

        // Find node and parent
        while (current && current->contact.name != name) {
            parent = current;
            if (name < current->contact.name) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (!current) {
            cout << "Contact not found for deletion." << endl;
            return;
        }

        // Case 1: Node has no children
        if (!current->left && !current->right) {
            if (current == root) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete current;
        }
        // Case 2: Node has one child
        else if (!current->left || !current->right) {
            Node* child = current->left ? current->left : current->right;
            if (current == root) {
                root = child;
            } else if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            delete current;
        }
        // Case 3: Node has two children
        else {
            Node* successorParent = current;
            Node* successor = current->right;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }
            current->contact = successor->contact;
            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
            delete successor;
        }
    }

    // Modify contact directly in the tree
    void modify(string oldName, string newName, int newNumber) {
        Node* current = root;
        while (current) {
            if (oldName == current->contact.name) {
                current->contact.name = newName;
                current->contact.number = newNumber;
                return;
            } else if (oldName < current->contact.name) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Contact not found for modification." << endl;
    }

    // Display all contacts in sorted order directly
    void display() {
        displayRec(root);
    }

    void displayRec(Node* node) {
        if (node) {
            displayRec(node->left);
            cout << node->contact.name << " - " << node->contact.number << endl;
            displayRec(node->right);
        }
    }
};

int main() {
    Tree t;
    int exit = -1;
    int option, number;
    string name, newName;

    while (exit != 0) {
        cout << "0. Exit" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Modify" << endl;
        cout << "5. Display" << endl;
        cout << "Enter an operation: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the name for insertion: ";
                cin >> name;
                cout << "Enter the number for insertion: ";
                cin >> number;
                t.insert(name, number);
                break;
            case 2:
                cout << "Enter the name to search: ";
                cin >> name;
                t.search(name);
                break;
            case 3:
                cout << "Enter the name to delete: ";
                cin >> name;
                t.deleteNode(name);
                break;
            case 4:
                cout << "Enter the name to modify: ";
                cin >> name;
                cout << "Enter the new name: ";
                cin >> newName;
                cout << "Enter the new number: ";
                cin >> number;
                t.modify(name, newName, number);
                break;
            case 5:
                cout << "Displaying all contacts:" << endl;
                t.display();
                break;
            case 0:
                exit = 0;
                cout << "Program exited" << endl;
                break;
            default:
                cout << "Enter a valid operation" << endl;
                break;
        }
    }
    return 0;
}
