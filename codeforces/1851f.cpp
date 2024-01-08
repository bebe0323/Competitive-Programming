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

int n, k, a[N];
map<int, int> mp;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = k - 1; i >= 0; i--) {
        mp.clear();
        bool ok = false;
        int tmp = -1;
        for (int j = 0; j < n; j++) {
            int val = a[j];
            val = val >> i;
            if (mp[val] == 1) {
                ok = true;
                break;
            }
            mp[val] = 1;
        }
        if (ok == false) {
            for (int j = 0; j < n; j++) {
                if (((a[j] >> i) & 1) == 1) {
                    a[j] -= (1 << i);
                }
            }
        } else {
            ans += (1 << i);
        }
    }
    mp.clear();
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0) {
            mp[a[i]] = i + 1;
            continue;
        }
        int ret = 0;
        for (int j = k - 1; j >= 0; j--) {
            if (((ans >> j) & 1) == 1) {
                ret += (1 - ((a[i] >> j) & 1)) << j;
            }
        }
        cout << mp[a[i]] << ' ' << i + 1 << ' ';
        cout << ret << '\n';
        break;
    }
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

// Problem URL: https://codeforces.com/problemset/problem/1851/F