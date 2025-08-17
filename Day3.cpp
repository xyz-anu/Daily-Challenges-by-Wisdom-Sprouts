#include<iostream>
using namespace std;
int findDuplicate(int* arr, int n) {
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow; 
}
int main() {
    int n;
    cin >> n;              
    int* arr = new int[n+1];
    for (int i = 0; i < n+1; i++) {
        cin >> arr[i];     
    }
    cout << findDuplicate(arr, n) << endl;
    delete[] arr;
    return 0;
}
