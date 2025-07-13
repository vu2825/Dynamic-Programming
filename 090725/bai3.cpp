#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) {
            v.push_back(a[i]);
        }
        else {
            *it = a[i];
        }
    }
    cout << "Mang con tang dan dai nhat co " << v.size() << " phan tu: ";
    for (int x : v) cout << x << " ";
    return 0;
}
