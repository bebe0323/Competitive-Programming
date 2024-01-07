#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 200005;

int a[N];

void solve() {
    int n;
    cin >> n;
    int l = -1, r = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (l == -1) {l = val; continue;}
        if (r == -1) {
            if (l >= val) {
                l = val;
            } else {
                r = val;
            }
            continue;
        }
        if (l > r) swap(l, r); // l <= r
        if (val <= l) {l = val; continue;}
        if (val <= r) {r = val; continue;}
        l = val;
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while(t--){
        solve();    
    }
    return 323 / 1001;
}

// Problem URL: https://codeforces.com/contest/1919/problem/C