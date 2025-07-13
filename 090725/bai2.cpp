#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ans = 0;
    int dem = 0;
    for (int x : a) {
        if (x > 0) {
            ans += log(x);
            ++dem;
        }
    }
    if (dem == 0) {
        cout << "0\n";
    }
    else {
        cout << fixed << setprecision(2) << exp(ans / dem) << endl;
    }
    return 0;
}
