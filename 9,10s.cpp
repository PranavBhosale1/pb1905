#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater
using namespace std;

// Template function to display the heap
template <typename T>
void display_heap(T pq) {
    // Display the elements of the priority queue
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    int no_of_students;
    cout << "Enter the number of students: ";
    cin >> no_of_students;

    // Create a max-heap (default behavior of priority_queue)
    priority_queue<int> max_pq;
    // Create a min-heap by passing std::greater<int> to the priority_queue
    priority_queue<int, vector<int>, greater<int>> min_pq;

    cout << "Enter the scores of the students: ";
    for (int i = 0; i < no_of_students; i++) {
        int score;
        cin >> score;
        max_pq.push(score); // Insert into max heap
        min_pq.push(score); // Insert into min heap
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Build Max Heap and Display\n";
        cout << "2. Build Min Heap and Display\n";
        cout << "3. Display Maximum Value\n";
        cout << "4. Display Minimum Value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Max Heap: ";
                display_heap(max_pq);
                break;
            case 2:
                cout << "Min Heap: ";
                display_heap(min_pq);
                break;
            case 3:
                // Display the maximum value in the max-heap
                if (!max_pq.empty()) {
                    cout << "Maximum value is " << max_pq.top() << endl;
                } else {
                    cout << "Heap is empty.\n";
                }
                break;
            case 4:
                // Display the minimum value in the min-heap
                if (!min_pq.empty()) {
                    cout << "Minimum value is " << min_pq.top() << endl;
                } else {
                    cout << "Heap is empty.\n";
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
