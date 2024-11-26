#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int no_of_students;
    cout << "Enter the number of students: ";
    cin >> no_of_students;
    cout<<"Enter Marks: "<<endl;

    vector<int> marks(no_of_students);
    for (int i = 0; i < no_of_students; i++) {
        cin >> marks[i];
    }

    // Use a max heap to find the maximum value
    priority_queue<int> max_heap(marks.begin(), marks.end());
    int max_value = max_heap.top();
    cout << "Largest value is " << max_value << endl;

    // Use a min heap to find the minimum value
    priority_queue<int, vector<int>, greater<int>> min_heap(marks.begin(), marks.end());
    int min_value = min_heap.top();
    cout << "Smallest value is " << min_value << endl;

    return 0;
}
