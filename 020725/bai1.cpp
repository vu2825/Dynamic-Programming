/*
Y tuong chinh:
- X[i]: thanh pho duoc chon o vi tri i trong hanh trinh
- visited[j]: danh dau xem da tham thanh pho j hay chua
- amin: chi phi nho nhat giua cac cap trong thanh pho A[i][j]
- Try(i, tong): phep thu cho tung thanh pho tong.
*/

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int n, A[100][100], X[100], visited[100];
int ans = INT_MAX, amin = INT_MAX;

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            if (A[i][j] != 0) {
                amin = min(amin, A[i][j]);
            }
        }
    }
}

void Try(int i, int tong) {
    for (int j = 1; j <= n; j++) {
        if (visited[j] == 0) {
            X[i] = j;
            visited[j] = 1;
            tong += A[X[i - 1]][X[i]];
            if (i == n) {
                ans = min(ans, tong += A[X[n]][X[1]]);
            }
            else if (tong + (n - i + 1) * amin < ans) {
                Try(i + 1, tong);
            }
            tong -= A[X[i - 1]][X[i]];
            visited[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    X[1] = 1;
    visited[1] = 1;
    Try(2, 0);
    cout << ans << endl;
}
