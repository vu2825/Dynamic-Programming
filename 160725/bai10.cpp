#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    stringstream ss(s);
    string w;
    string res = "";
    while (ss >> w) {
        reverse(w.begin(), w.end());
        res += w + " ";
    }
    for (auto it : res) {
        cout << it;
    }
}
