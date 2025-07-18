#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= m; k++) {
            cin >> a[i][k];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> trace(n + 1, vector<int>(m + 1, -1)); // truy vết
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                int newVal = dp[i - 1][j - k] + a[i][k];
                if (newVal > dp[i][j]) {
                    dp[i][j] = newVal;
                    trace[i][j] = k;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    int j = m;
    vector<int> res(n + 1);
    for (int i = n; i >= 1; i--) {
        int k = trace[i][j];
        res[i] = k;
        j -= k;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}
