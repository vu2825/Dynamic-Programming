#include <bits/stdc++.h>

#define ll long long
#define endl '\n'

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ifstream fin("TAMPHAN.INP");
    ofstream fout("TAMPHAN.OUT");
    int n;
    fin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        fin >> points[i].x >> points[i].y;
    }
    vector<vector<double>> dp(n, vector<double>(n, 0.0));
    vector<vector<int>> choice(n, vector<int>(n, -1));
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i + 1; k < j; k++) {
                double cost = dp[i][k] + dp[k][j];
                if (k != i + 1) cost += distance(points[i], points[k]);
                if (k != j - 1) cost += distance(points[k], points[j]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    choice[i][j] = k;
                }
            }
        }
    }
    fout << fixed << setprecision(4) << dp[0][n-1] << endl;
    vector<pair<int, int>> ans;
    function<void(int, int)> trace = [&](int i, int j) {
        if (j - i <= 2) return;
        int k = choice[i][j];
        if (k != -1) {
            if (k != i + 1) ans.push_back({i + 1, k + 1}); 
            if (k != j - 1) ans.push_back({k + 1, j + 1}); 
            trace(i, k);
            trace(k, j);
        }
    };
    trace(0, n - 1);
    for (auto it : ans) {
        fout << it.first << " " << it.second << endl;
    }
    fin.close();
    fout.close();
}