#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
const int M = 1e9+7;

int recursion(int n) {
    if (n < 0)
        return 0;
    
    if (n == 0)
        return 1;

    if (dp[n] > 0)
        return dp[n];

    int result = 0;

    for (int i = 1; i < 7; i++) {
        result += recursion(n - i);
        result %= M;
    }

    return result;
}

int solve(int n) {
    dp[0] = dp[1] = 1;

    if (n < 7)
        return 1 << (n - 1);

    for (int i = 2; i < 7; i++)
        dp[i] = dp[i - 1] << 1;
    
    for (int i = 7; i <= n; i++) {
        for (int j = 1; j < 7; j++) {
            dp[i] += dp[i - j];
            dp[i] %= M;
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}