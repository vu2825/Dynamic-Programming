#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n; i++) {
        pascal[i].resize(i + 1);   
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i - 1; k++) cout << "  ";
        for (int j = 0; j <= i; j++) {
            cout << pascal[i][j] << "   ";
        }
        cout << endl;
    }
}
