/*
Y tuong:
- Su dung backtracking
- Co 2 lua chon:
    Gan chi tiet i cho may A -> cong thoi gian a[i] vao tongA
    Gan chi tiet i cho may B -> cong thoi gian b[i] vao tongB
- Tiep tuc de quy cho cach tiep theo
- Dieu kien dung: khi da phan cong het chi tiet cho 2 may A va B
*/

#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int n;
int a[25], b[25];
int ans = INT_MAX;

void Try(int i, int tongA, int tongB) {
    if (i == n) {
        ans = min(ans, max(tongA, tongB));
        return;
    }
    Try(i + 1, tongA + a[i], tongB);
    Try(i + 1, tongA, tongB + b[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    Try(0, 0, 0);
    cout << ans << endl;
}
