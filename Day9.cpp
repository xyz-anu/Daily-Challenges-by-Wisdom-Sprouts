#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
     if (strs.empty()) return ""; 
    if (strs.size() == 1) return strs[0]; 
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            ++j;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }
    return prefix;
}

 int main() {
    vector<vector<string>> test_cases = {
        {"flower", "flow", "flight"},     
        {"dog", "racecar", "car"},        
        {"apple", "ape", "april"},        
        {""},                             
        {"alone"},                       
        {}                                
    };
     for (auto& strs : test_cases) {
        cout << "Input: ";
        for (auto& s : strs) cout << "\"" << s << "\" ";
          cout << "\nOutput: \"" << longestCommonPrefix(strs) << "\"\n\n";
    }

    return 0;
}
