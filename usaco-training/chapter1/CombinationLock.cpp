/*
ID: belgute2
LANG: C++11
TASK: combo
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

const int N = 200005;

int n, a[5][105], b[5];

bool check(int type) {
    for (int i = 0; i < 3; i++) {
        bool ok = false;
        if (abs(b[i] - a[type][i]) <= 2) ok = 1;
        if (n - b[i] + a[type][i] <= 2) ok = 1;
        if (n - a[type][i] + b[i] <= 2) ok = 1;
        if (!ok) return false;
    }
    return true;
}

int main() {
    IOS
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> a[1][i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                b[0] = i;
                b[1] = j;
                b[2] = k;
                if (check(0) || check(1)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 323 / 1001;
}

// Problem URL: https://train.usaco.org/usacoprob2?a=feuUrAjHMhP&S=combo