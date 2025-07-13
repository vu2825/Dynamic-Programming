#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.begin()) {
        cout << "NONE\n";
    }
    else {
        --it;
        cout << *it << endl;
    }
    return 0;
}
