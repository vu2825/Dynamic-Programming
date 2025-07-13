/*
Quy tac di chuyen cua ma phuong:
- Đi lên - qua phải
- Nếu bị chặn → đi xuống
- Nếu vượt biên → dùng % n để quay lại
*/

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int num = 1;
    int i = 0, j = n / 2;
    while (num < n * n) {
        a[i][j] = num;
        ++num;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        if (a[ni][nj] != 0) {
            i = (i + 1) % n;
        } 
        else {
            i = ni;
            j = nj;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
