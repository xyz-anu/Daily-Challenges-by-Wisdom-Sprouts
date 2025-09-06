#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < arr.size(); ++i) {

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}
int main() {
    int n, k;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the window size (k): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid window size. It should satisfy 1 <= k <= n.\n";
        return 1;
    }
    vector<int> result = slidingWindowMaximum(arr, k);

    cout << "Output:\n";
    for (int maxVal : result) {
        cout << maxVal << " ";
    }
    cout << endl;
    return 0;
}
