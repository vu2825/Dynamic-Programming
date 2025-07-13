/*
Y tuong:
- Su dung backtracking
- Sinh tat ca chuoi hop le co m ky tu
- Theo doi:
    open: so dau '(' da dung
    close: so dau ')' da dung
    depth: do sau hien tai
    maxDepth: do sau lon nhat dat duoc
- Chi in chuoi neu maxDepth == n
*/

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int n, m;
string s;

void Try(int open, int close, int depth, int maxDepth) {
    if (s.length() == n) {
        if (open == close && maxDepth == m) {
            cout << s << endl;
            return;
        }
    }
    if (open < n / 2) {
        s.push_back('(');
        Try(open + 1, close, depth + 1, max(maxDepth, depth + 1));
        s.pop_back();
    }
    if (close < open) {
        s.push_back(')');
        Try(open, close + 1, depth - 1, maxDepth);
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    Try(0, 0, 0, 0);
}
