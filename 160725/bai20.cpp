#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

const int N = 305;
int n, k;
int a[N];
ll dp[N][N];
int path[N][N];

ll calc_cost(int l, int r) {
    int m = (l + r) / 2;
    ll res = 0;
    for (int i = l; i <= r; ++i)
        res += abs(a[i] - a[m]);
    return res;
}

int main() {
    ifstream fin("BuuDien.inp");
    ofstream fout("BuuDien.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    ll cost[N][N];
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            cost[l][r] = calc_cost(l, r);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int p = 0; p < i; ++p) {
                if (dp[i][j] > dp[p][j - 1] + cost[p + 1][i]) {
                    dp[i][j] = dp[p][j - 1] + cost[p + 1][i];
                    path[i][j] = p;
                }
            }
        }
    }
    vector<int> tram;
    int i = n, j = k;
    while (j > 0) {
        int p = path[i][j];
        int mid = (p + 1 + i) / 2;
        tram.push_back(a[mid]);
        i = p;
        --j;
    }
    reverse(tram.begin(), tram.end());
    for (int t : tram) fout << t << " ";
    fout << "\n" << dp[n][k] << "\n";
    fin.close();
    fout.close();
}
