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
    vector<int> dp(w + 1, 0);
    vector<int> dem(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= w; j++) {
            if (dp[j] < dp[j - a[i]] + c[i]) {
                dp[j] = dp[j - a[i]] + c[i];
            }
        }
    }
    int v = w;
    while (v > 0) {
        for (int i = 1; i <= n; i++) {
            if (v >= a[i] && dp[v] == dp[v - a[i]] + c[i]) {
                ++dem[i];
                v -= a[i];
                break;
            }
        }
    }
    cout << "Tong gia tri cua cac mon hang bo vao ba lo: " << dp[w] << endl;
    for (int i = 1; i <= n; i++) {
        if (dem[i] > 0) {
            cout << "Chon " << dem[i] << " mon hang loai " << i << ", moi mon co khoi luong la " << a[i] << " va gia tri la " << c[i] << endl;
        }
    }
}
