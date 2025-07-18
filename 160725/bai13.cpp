#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int n, k, a[100];
bool final = false;

void ktao() {
    for (int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh() {
    int i = k - 1;
    while (i >= 1 && a[i] == n - k + i) {
        --i;
    }
    if (i == 0) {
        final = true;
    }
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ktao();
    while (!final) {
        for (int i = 1; i <= k; i++) {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
}
