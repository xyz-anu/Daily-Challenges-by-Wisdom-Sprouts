#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
     for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<long long, vector<int>> sum_indices;
    vector<pair<int, int>> result;
    long long prefix_sum = 0;
     for (int i = 0; i < n; ++i) {
        prefix_sum += arr[i];
        if (prefix_sum == 0) {
            result.push_back({0, i});
        }
        if (sum_indices.find(prefix_sum) != sum_indices.end()) {
            for (int idx : sum_indices[prefix_sum]) {
                result.push_back({idx + 1, i});
            }
        }
        sum_indices[prefix_sum].push_back(i);
    }
     for (auto pr : result) {
        cout << "(" << pr.first << ", " << pr.second << ") ";
    }
    cout << endl;
    return 0;
}
