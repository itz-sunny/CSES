#include <bits/stdc++.h>

using namespace std;
const int M = 1e7;
int solve(int n, vector<int>& dp) {
    if (n < 0)
        return M;
    if (n == 0)
        return 0;
    if (dp[n] != M)
        return dp[n];
    int t = n, result = M;
    while (t > 0) {
        int d = t % 10;
        if (d != 0)
            result = min(result, 1 + solve(n - d, dp));
        t /= 10;
    }
    return dp[n] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> dp(n + 1, M);
    cout << solve(n, dp);
    return 0;
}