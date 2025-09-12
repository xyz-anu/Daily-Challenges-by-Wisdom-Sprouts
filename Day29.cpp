#include <iostream>
#include <vector>
using namespace std;
long double fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<long double> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n;
    cout << "Enter n (0 <= n <= 1000): ";
    cin >> n;
    if (n < 0 || n > 1000) {
        cout << "Invalid input. n must be between 0 and 1000." << endl;
        return 1;
    }
    long double result = fibonacci(n);
    cout.precision(15);
    cout << "F(" << n << ") = " << result << endl;
    return 0;
}
