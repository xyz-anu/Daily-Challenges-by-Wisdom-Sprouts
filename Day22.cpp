#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n, k;
    cout << "Enter array size (n): ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<int> arr(n);
    unordered_map<int, int> freq;
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 0; i < n; ++i) {
        if(freq[arr[i]] == k) {
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
