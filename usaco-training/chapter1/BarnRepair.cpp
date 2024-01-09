/*
ID: belgute2
LANG: C++11
TASK: barn1
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MOD 1000000007
#define MOD1 1000000009

const int N = 205;

int m, s, n;
int c[N];
int dp[205][55]; // first i-cow used k stall

int main() {
    IOS
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    cin >> m >> s >> n;
    // m - max number of boards
    // n - number of cows
    for (int i = 0; i < n; i++) {
        cin >> c[i]; // i-th cow position
    }
    sort(c, c + n);
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // j to i-th cow in the same stall
            if (j == 0) {
                dp[i][1] = c[i] - c[j] + 1;
                continue;
            }
            for (int k = 1; k < m; k++) {
                if (dp[j - 1][k] != 0) {
                    if (dp[i][k + 1] == 0) dp[i][k + 1] = dp[j - 1][k] + c[i] - c[j] + 1;
                    else dp[i][k + 1] = min(dp[i][k + 1], dp[j - 1][k] + c[i] - c[j] + 1);
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= m; i++) {
        if (dp[n - 1][i] != 0) ans = min(ans, dp[n - 1][i]);
    }
    cout << ans << '\n';
    return 323 / 1001;
}

// Problem URL: https://train.usaco.org/usacoprob2?a=feuUrAjHMhP&S=barn1