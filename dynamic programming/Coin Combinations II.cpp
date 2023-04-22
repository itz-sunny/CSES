#include <bits/stdc++.h>

using namespace std;

int main() {
    const int M = 1e9+7;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int& coin : coins)
        cin >> coin;
    int dp[x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int coin : coins) {
        for (int a = 1; a <= x; a++) {
            if (coin <= a) {
                dp[a] += dp[a - coin];
                dp[a] %= M;
            }
        }
    }
    cout << dp[x];
    return 0;
}