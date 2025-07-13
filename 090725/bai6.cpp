#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

/*
Yeu cau 1: b co la mang con cua a hay khong
Giai thuat:
- Duyet qua ta ca cac doan con do dai n cua mang a
- So sanh tung doan con voi mang b
- Neu co doan khop thi tra ve true, nguoc lai tra ve false
*/

bool mangCon(int a[], int m, int b[], int n) {
    if (n > m) return false;
    for (int i = 0; i <= m - n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[i + j] != b[j]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

/*
Yeu cau 2: b co phai la mot hoan vi cua a hay khong
Giai thuat:
- Neu m != n -> false
- Dem tan suat cua cac phan tu trong mang a va b
- So sanh 2 tan suat
*/

bool hoanVi(int a[], int m, int b[], int n) {
    if (m != n) return false;
    map<int, int> mp1, mp2;
    for (int i = 0; i < m; i++) mp1[a[i]]++;
    for (int i = 0; i < n; i++) mp2[b[i]]++;
    return mp1 == mp2;
}

/*
Yeu cau 3: hai mang co bang nhau hay khong
Giai thuat: 
- Neu m != n -> false;
- Duyet tung vi tri, so sanh a[i] va b[i];
*/

bool bangNhau(int a[], int m, int b[], int n) {
    if (m != n) return false;
    for (int i = 0; i < m; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (mangCon(a, m, b, n)) cout << "YES\n";
    else cout << "NO\n";
    if (hoanVi(a, m, b, n)) cout << "YES\n";
    else cout << "NO\n";
    if (bangNhau(a, m, b, n)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
