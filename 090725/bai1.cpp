#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

bool nt(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}

bool tong_nt(int n) {
    int ans = 0;
    while (n != 0) {
        ans += n % 10;
        n /= 10;
    }
    return nt(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int tong = 0;
    while (cin >> n) {
        if (tong_nt(n)) {
            tong += n;
        }
    }
    cout << tong << endl;
    return 0;
}
