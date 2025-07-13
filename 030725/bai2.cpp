/*
Luong nuoc ban dau la a[i], mat di la b[i]
Can di tinh tong luong nuoc con lai sau t ngay
Phan tich:
Ngay 0: tong = a[0] + a[1] + ... + a[n - 1]
Ngay 1: boc hoi b[i], tong = a[i] - 1 * b[i]
Ngay 2: boc hoi them b[i], tong = a[i] - 2 * b[i]
...
Ngay n: tong = a[i] - k * b[i];
*/

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int k = 0; k <= t; k++) {
        ll tong = 0;
        for (int i = 0; i < n; i++) {
            int ans = a[i] - k * b[i];
            if (ans < 0) ans = 0;
            tong += ans;
        }
        cout << tong << endl;
    }
    return 0;
}
