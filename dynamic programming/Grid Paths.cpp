#include <bits/stdc++.h>

using namespace std;
const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        if (grid[i][0] == '*')
            break;
        else
            dp[i][0] = 1;

    for (int j = 0; j < n; j++)
        if (grid[0][j] == '*')
            break;
        else
            dp[0][j] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}