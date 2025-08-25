#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> permuteUnique(string s) {
    sort(s.begin(), s.end());
    vector<string> result;
     do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return result;
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    vector<string> perms = permuteUnique(s);
    cout << "Output: [";
    for (int i = 0; i < perms.size(); ++i) {
        cout << "\"" << perms[i] << "\"";
        if (i != perms.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
