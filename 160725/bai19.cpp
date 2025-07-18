#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ifstream fin("KiSu.inp");
    ofstream fout("KiSu.out");
    int m, n;
    fin >> m >> n;
    int a[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
    vector<vector<int>> trace(m + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= m; i++) {
            for (int k = 0; k <= i; k++) {
                 if (dp[i - k][j - 1] + a[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i - k][j - 1] + a[k][j];
                    trace[i][j] = k;
                }
            }
        }
    }
    fout << dp[m][n] << endl;
    vector<int> ans(n + 1);
    int i = m, j = n;
    while (j > 0) {
        int k = trace[i][j]; // so ky su duoc phan cho phong j
        ans[j] = k;          // luu lai ket qua phan cong
        i -= k;              // tru di so ky su da dung
        --j;                 
    }
    for (int j = 1; j <= n; j++) {
        fout << ans[j] << " ";
    }
    fin.close();
    fout.close();
}
