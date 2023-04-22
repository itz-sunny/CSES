#include <bits/stdc++.h>
 
using namespace std;

int dp[1000001][101];

int memoization(int coins[], int x, int index) {
    if (x < 0 || index < 0)
        return 1000001;
    if (x == 0)
        return 0;
    if (dp[x][index] != 0)
        return dp[x][index];
    int result = memoization(coins, x, index - 1);
    if (x >= coins[index])
        result = min(result, 1 + memoization(coins, x - coins[index], index));
    return dp[x][index] = result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int &coin : coins)
        cin >> coin;
    sort(coins, coins + n);
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int a = 1; a <= x; a++) {
        for (int coin : coins) {
            if (a - coin < 0)
                break;
            if (dp[a - coin] != INT_MAX)
                dp[a] = min(dp[a - coin] + 1, dp[a]);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
    return 0;
}