#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

bool check(int n) {
    string s = to_string(n);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= s[i - 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dem = 0;
    for (int x : a) {
        if (check(x)) ++dem;
    }
    cout << dem << endl;
    return 0;
}
