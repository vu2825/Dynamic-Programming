#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

vector<int> xoaTrung(vector<int> a) {
    set<int> se;
    vector<int> res;
    for (int x : a) {
        if (se.find(x) == se.end()) {
            res.push_back(x);
            se.insert(x);
        }
    }
    return res;
}

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
    vector<int> ans = xoaTrung(a);
    for (int x : ans) {
        cout << x << " ";
    }
}
