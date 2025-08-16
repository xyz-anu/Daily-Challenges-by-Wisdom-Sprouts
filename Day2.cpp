#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    int arr[n-1];
    int arrSum = 0;
    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
        arrSum += arr[i];
    }
    cout << (sum - arrSum) << endl;
    return 0;
}
