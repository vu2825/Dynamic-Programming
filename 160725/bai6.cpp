#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> a;
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> n) {
        a.push_back(n);
    }
    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        ans.push_back(a[i]);
        if (i == a.size() - 1 || a[i] >= a[i + 1]) {
            if (ans.size() >= 2) {
                for (int x : ans) {
                    cout << x << " ";
                }
                cout << endl;
            }
            ans.clear();
        }
    }
}
