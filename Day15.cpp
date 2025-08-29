#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> freq(256, 0); 
    int left = 0, maxLen = 0;

     for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Length of the longest substring without repeating characters = " << lengthOfLongestSubstring(s) << "\n";
    return 0;
}
