#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, maxLen = 1;
     for (int i = 0; i < n;) {
         if (n - i <= maxLen / 2) break;
          int j = i, k = i;
         while (k < n - 1 && s[k + 1] == s[k]) ++k;
          i = k + 1;
         while (j > 0 && k < n - 1 && s[j - 1] == s[k + 1]) { --j; ++k; }
          int len = k - j + 1;
         if (len > maxLen) { start = j; maxLen = len; }
    }
    return s.substr(start, maxLen);
}
int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
