#include <iostream>
using namespace std;

class ThreadedNode {
public:
    int key;
    bool leftThread = true;  // If true, left pointer is a thread
    bool rightThread = true; // If true, right pointer is a thread
    ThreadedNode *left = nullptr;
    ThreadedNode *right = nullptr;

    ThreadedNode(int value) {
        key = value;
    }
};

class ThreadedBinaryTree {
public:
    ThreadedNode *root = nullptr;

    void insert(int value) {
        ThreadedNode *newNode = new ThreadedNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        ThreadedNode *current = root;
        while (true) {
            if (value < current->key) {
                if (current->leftThread) {
                    newNode->left = current->left;
                    newNode->right = current;
                    current->leftThread = false;
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->rightThread) {
                    newNode->right = current->right;
                    newNode->left = current;
                    current->rightThread = false;
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    void printThreads(ThreadedNode* node) {
        if (node == nullptr) return;

        if (node->leftThread)
            cout << "Node " << node->key << " left thread points to: " << (node->left ? node->left->key : -1) << endl;
        else
            cout << "Node " << node->key << " left child is: " << (node->left ? node->left->key : -1) << endl;

        if (node->rightThread)
            cout << "Node " << node->key << " right thread points to: " << (node->right ? node->right->key : -1) << endl;
        else
            cout << "Node " << node->key << " right child is: " << (node->right ? node->right->key : -1) << endl;

        // Traverse both left and right children
        if (!node->leftThread)
            printThreads(node->left);
        if (!node->rightThread)
            printThreads(node->right);
    }

    void inorderTraversal() {
        if (root == nullptr) {
            cout << "The tree is empty." << endl;
            return;
        }

        ThreadedNode *current = root;
        while (!current->leftThread) {
            current = current->left;
        }

        while (current != nullptr) {
            cout << current->key << " ";
            if (current->rightThread)
                current = current->right;
            else {
                current = current->right;
                while (current != nullptr && !current->leftThread)
                    current = current->left;
            }
        }
        cout << endl;
    }

    void menu() {
        int choice, value;
        while (true) {
            cout << "\nThreaded Binary Tree Menu" << endl;
            cout << "1. Insert Node" << endl;
            cout << "2. Inorder Traversal" << endl;
            cout << "3. Print Thread Pointers" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    insert(value);
                    break;
                case 2:
                    cout << "Inorder Traversal: ";
                    inorderTraversal();
                    break;
                case 3:
                    cout << "Printing thread pointers:" << endl;
                    printThreads(root);
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    ThreadedBinaryTree tree;
    tree.menu();  // Launch the menu-driven system
    return 0;
}
