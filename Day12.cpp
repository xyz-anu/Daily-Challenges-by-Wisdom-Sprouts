#include <iostream>
#include <stack>
#include <string>
using namespace std;
 bool isValid(string s) {
    stack<char> stk;
     for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
int main() {
    cout << boolalpha;
    cout << isValid("()") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("[{()}]") << endl;
    cout << isValid("") << endl;
    cout << isValid("{[}") << endl;
    return 0;
}
