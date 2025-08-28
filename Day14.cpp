#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countAtMostK(const string &s, int k) {
    int n = s.size();
    vector<int> freq(26, 0);
    int left = 0, distinct = 0, total = 0;
     for (int right = 0; right < n; right++) {
         if (freq[s[right] - 'a'] == 0) 
            distinct++;
        freq[s[right] - 'a']++;

        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0) 
                distinct--;
            left++;
        }
        total += (right - left + 1);
    }
     return total;
}
int countExactlyK(const string &s, int k) {
    if (k > s.size()) return 0;
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}
int main() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Number of substrings with exactly " << k 
         << " distinct characters = " << countExactlyK(s, k) << "\n";

    return 0;
}
