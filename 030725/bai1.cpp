/*
Can tim cap (rong, dai) sao cho: rong * dai = n va abs(rong - dai) la nho nhat
Y tuong:
- Goi w la chieu rong, h la chieu dai
- Duyet w tu 1 den sqrt(n)
- Voi moi w ma n chia het thi h = n / w la mot so mot so nguyen 
- Cap nhat dai va rong sao cho abs(rong - dai) nho nhat
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
    int dai = 1, rong = n;
    for (int w = 1; w <= sqrt(n); w++) {
        if (n % w == 0) {
            int h = n / w;
            if (abs(h - w) < abs(dai - rong)) {
                dai = h;
                rong = w;
            }
        }
    }
    cout << rong << " " << dai << endl;
    return 0;
}
