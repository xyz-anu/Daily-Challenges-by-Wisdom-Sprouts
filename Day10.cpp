#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
string makeKey(const string& word) {
    string key = word;
    sort(key.begin(), key.end());
    return key;
}
vector<vector<string>> getGroupedAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> groups;
    for (const auto& word : words) {
        string key = makeKey(word);
        groups[key].push_back(word);
    }
    vector<vector<string>> result;
    result.reserve(groups.size()); 
    for (auto& g : groups) {
        result.push_back(move(g.second));  
    }
    return result;
}
void printGroups(const vector<vector<string>>& grouped) {
    for (const auto& group : grouped) {
        cout << "[ ";
        for (size_t i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i + 1 < group.size()) cout << ", "; 
        }
        cout << " ]\n";
    }
    cout << endl;
}
int main() {
    vector<string> test1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> test2 = {""};
    vector<string> test3 = {"a"};
    vector<string> test4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<string> test5 = {"abc", "def", "ghi"};
    printGroups(getGroupedAnagrams(test1));
    printGroups(getGroupedAnagrams(test2));
    printGroups(getGroupedAnagrams(test3));
    printGroups(getGroupedAnagrams(test4));
    printGroups(getGroupedAnagrams(test5));
    return 0;
}
