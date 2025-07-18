#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, W;
    cin >> n >> W;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> F(n + 1, vector<int>(W + 1, 0));
    for (int k = 1; k <= n; k++) {
        for (int v = 0; v <= W; v++) {
            if (v >= a[k]) {
                F[k][v] = max(F[k - 1][v], F[k - 1][v - a[k]] + a[k]);
            }
            else {
                F[k][v] = F[k - 1][v];
            }
        }
    }
    cout << "Tong khoi luong cac mon hang bo vao ba lo la: " << F[n][W] << endl;
    int k = n, v = W;
    vector<int> ans;
    while (k > 0) {
        if (F[k][v] != F[k - 1][v]) {
            ans.push_back(a[k]);
            v -= a[k];
        }
        --k;
    }
    reverse(ans.begin(), ans.end());
    cout << "Khoi luong cac mon hang duoc chon: ";
    for (int x : ans) cout << x << ' ';
    cout << endl;
}
