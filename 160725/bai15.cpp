#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int s2 = s / 2;
    vector<vector<int>> dp(n + 1, vector<int>(s2 + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s2; j++) {
            if (j >= a[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> b1, b2;
    vector<bool> chon(n + 1, false);
    int v = s2;
    for (int i = n; i >= 1; i--) {
        if (v >= a[i] && dp[i][v] == dp[i - 1][v - a[i]] + a[i]) {
            b1.push_back(a[i]);
            chon[i] = true;
            v -= a[i];
        }
    }
    for (int i = n; i >= 1; i--) {
        if (!chon[i]) {
            b2.push_back(a[i]);
        }
    }
    int tong1 = accumulate(b1.begin(), b1.end(), 0);
    int tong2 = accumulate(b2.begin(), b2.end(), 0);
    cout << "So keo be 1 nhan duoc: ";
    for (int x : b1) cout << x << " ";
    cout << endl << "Tong so keo: " << tong1 << endl;
    cout << "So keo be 2 nhan duoc: ";
    for (int x : b2) cout << x << " ";
    cout << endl << "Tong so keo: " << tong2 << endl;
}
