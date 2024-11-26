#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void max_heapify(vector<int> &vec, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && vec[left] > vec[largest]) {
        largest = left;
    }
    if (right <= n && vec[right] > vec[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(vec[i], vec[largest]);
        max_heapify(vec, n, largest);
    }
}

void build_max_heap(vector<int> &vec, int n) {
    for (int i = n / 2; i >= 1; i--) {
        max_heapify(vec, n, i);
    }
}

void min_heapify(vector<int> &vec, int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && vec[left] < vec[smallest]) {
        smallest = left;
    }
    if (right <= n && vec[right] < vec[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(vec[i], vec[smallest]);
        min_heapify(vec, n, smallest);
    }
}

void build_min_heap(vector<int> &vec, int n) {
    for (int i = n / 2; i >= 1; i--) {
        min_heapify(vec, n, i);
    }
}

void display_heap(const vector<int> &vec, int n) {
    for (int i = 1; i <= n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int no_of_students;
    cout << "Enter the number of students: ";
    cin >> no_of_students;
    vector<int> vec(no_of_students + 1);
    for (int i = 1; i <= no_of_students; i++) {
        cin >> vec[i];
    }

    vector<int> max_vec = vec;
    vector<int> min_vec = vec;

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
                max_vec[0] = INT_MIN;
                build_max_heap(max_vec, no_of_students);
                cout << "Max Heap: ";
                display_heap(max_vec, no_of_students);
                break;
            case 2:
                min_vec[0] = INT_MAX;
                build_min_heap(min_vec, no_of_students);
                cout << "Min Heap: ";
                display_heap(min_vec, no_of_students);
                break;
            case 3:
                max_vec[0] = INT_MIN;
                build_max_heap(max_vec, no_of_students);
                cout << "Maximum value is " << max_vec[1] << endl;
                break;
            case 4:
                min_vec[0] = INT_MAX;
                build_min_heap(min_vec, no_of_students);
                cout << "Minimum value is " << min_vec[1] << endl;
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
