#include <iostream>
#include <stack>
using namespace std;

// Function to print the stack
void printStack(stack<char> st) {
    // Temporary stack to display elements in order
    stack<char> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    cout << "Stack: ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

// Function to convert infix to postfix
void post(string s) {
    stack<char> st;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        cout << "Processing: " << s[i] << endl;
        if (isalnum(s[i])) {
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the '('
        } else {
            while (!st.empty() && st.top() != '(' && 
                   ((s[i] == '+' || s[i] == '-') && (st.top() == '*' || st.top() == '/')) ||
                   ((s[i] == '+' || s[i] == '-') && (st.top() == '+' || st.top() == '-')) ||
                   ((s[i] == '*' || s[i] == '/') && (st.top() == '*' || st.top() == '/'))) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        cout << "Current output: " << ans << endl;
        printStack(st);
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "Final output: " << ans << endl;
}

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;
    post(s);
    return 0;
}
