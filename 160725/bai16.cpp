#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n >> w;
    int a[n + 1], c[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j >= a[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << "Tong gia tri cua cac mon hang bo vao ba lo: " << dp[n][w] << endl;
    vector<tuple<int, int, int>> ans; // lưu cả chỉ số, trọng lượng, giá trị
    int k = n, v = w;
    while (k > 0) {
        if (dp[k][v] != dp[k - 1][v]) {
            ans.push_back({k, a[k], c[k]}); // lưu chỉ số k
            v -= a[k];
        }
        --k;
    }
    reverse(ans.begin(), ans.end());
    cout << "Cac mon duoc chon: ";
    for (auto it : ans) {
        cout << get<0>(it) << "(" << get<1>(it) << ", " << get<2>(it) << ") ";
    }
    cout << endl;
}
