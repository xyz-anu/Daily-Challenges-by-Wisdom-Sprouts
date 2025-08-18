#include <iostream>
#include <vector>
#include <cmath>
 using namespace std;
   void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = (m + n + 1) / 2;
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < m + n) {
            int a, b;
            if (i < m)
                a = arr1[i];
             else
                a = arr2[i - m];
            if (j < m)
                b = arr1[j];
            else
                b = arr2[j - m];    
             if (a > b) {
                if (i < m && j < m)
                    swap(arr1[i], arr1[j]);
                else if (i < m && j >= m)
                    swap(arr1[i], arr2[j - m]);
                else
                    swap(arr2[i - m], arr2[j - m]);
            }
            i++, j++;
        }
        if (gap == 1) break;
        gap = (gap + 1) / 2;
    }
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
    merge(arr1, arr2, m, n);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
    cout << endl;
    return 0;
}
