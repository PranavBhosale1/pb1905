#include <iostream>
#include <stack>
#include <cctype> // for isalnum
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

// Function to define the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void post(string s) {
    stack<char> st;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        // Insert '*' for implicit multiplication
        if (i > 0 && (isalnum(s[i]) && (isalnum(s[i - 1]) || s[i - 1] == ')'))) {
            st.push('*');
            cout << "Inserted implicit '*'\n";
        } else if (i > 0 && s[i] == '(' && (isalnum(s[i - 1]) || s[i - 1] == ')')) {
            st.push('*');
            cout << "Inserted implicit '*'\n";
        }

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
        } else { // Operator
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
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
