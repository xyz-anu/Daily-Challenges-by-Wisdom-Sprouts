#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}
int main() {
    int n, amount;
    cout << "Enter the number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << "Enter the amount: ";
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Minimum number of coins required: " << result << endl;
    return 0;
}
