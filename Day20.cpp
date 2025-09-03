#include <stack>
#include <iostream>
using namespace std;

void insertSorted(stack<int> &st, int val) {
    if (st.empty() || val >= st.top()) {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, val);
    st.push(temp);
}
void sortStack(stack<int> &st) {
     if (st.empty() || st.size() == 1)
        return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
}
void printStack(stack<int> st) {
    if (st.empty())
        return;
    int temp = st.top();
    st.pop();
    printStack(st);
    cout << temp << " ";
}
int main() {
    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;
    stack<int> st;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.push(x);
    }
    sortStack(st);
    cout << "Sorted stack (top to bottom): ";
    printStack(st);
    cout << endl;
    return 0;
}
