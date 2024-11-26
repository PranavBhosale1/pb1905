#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int no_of_students;
    cout << "Enter the number of students: ";
    cin >> no_of_students;
    cout<<"Enter Marks: ";
    
    priority_queue<int> maxHeap;  // Max heap
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap
    
    int mark;
    for (int i = 0; i < no_of_students; i++) {
        cin >> mark;
        maxHeap.push(mark);
        minHeap.push(mark);
    }

    cout << "Largest value is " << maxHeap.top() << endl;
    cout << "Smallest value is " << minHeap.top() << endl;

    return 0;
}
