#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_sum = a[0], curr_sum = a[0];
    int start = 0, end = 0;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            curr_sum += a[i];
        }
        else {
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                start = idx;
                end = i - 1;
            }
            curr_sum = a[i];
            idx = i;
        }
    }
    if (curr_sum > max_sum) {
        max_sum = curr_sum;
        start = idx;
        end = n - 1;
    }
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl << max_sum << endl;
}
