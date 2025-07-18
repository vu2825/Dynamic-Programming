#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(s + 1, 1e9);
    vector<int> trace(s + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= s; i++) {
        for (int x : a) {
            if (i >= x) {
                dp[i] = min(dp[i], dp[i - x] + 1);
                trace[i] = x;
            }
        }
    }
    if (dp[s] == 1e9) {
        cout << "KHONG DOI DUOC\n";
        return 0;
    }
    cout << "Tong so to phai tra: " << dp[s] << endl;
    map<int, int> mp;
    int v = s;
    while (v > 0) {
        int x = trace[v];
        mp[x]++;
        v -= x;
    }
    for (int i = 1; i <= n; i++) {
        cout << "Menh gia " << a[i] << ": " << mp[a[i]] << " to" << endl;
    }
}
