#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}
