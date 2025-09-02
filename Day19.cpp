#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
int evaluatePostfix(string expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    while (ss>> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = 0;
            if (token  == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token =="*") res= a * b;
            else if (token == "/") res = a / b; 
            st.push(res);
        } 
        else {
            st.push(stoi(token));
        }
    }
    return st.top();
}
int main() {
    string expr;
    getline(cin, expr);
    cout << evaluatePostfix(expr) << endl;
    return 0;
}
