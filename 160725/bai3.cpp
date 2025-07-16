#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

void fibo(int n) {
    ll F[100];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 92; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fibo(n);
}
