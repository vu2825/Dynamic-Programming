#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

string nhiPhan(int n) {
    string ans = "";
    while (n != 0) {
        ans.push_back(n % 2 + '0');
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << nhiPhan(a[i]) << "\n";
    }
}
