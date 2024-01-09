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

const int N = 50;

int n, target, a[N];
ll ans;
vector<int> l;

void add(int uld) {
    int l_pos = lower_bound(l.begin(), l.end(), uld) - l.begin();
    int r_pos = upper_bound(l.begin(), l.end(), uld) - l.begin();
    ans = (ll) ans + r_pos - l_pos;
}

void bitmask(int pos, int type, int val) {
    if (type == 0) {
        if (pos > n / 2) return;
        bitmask(pos + 1, type, val);
        if (val + a[pos] <= target) {
            l.pb(val + a[pos]);
            bitmask(pos + 1, type, val + a[pos]);
        }
    } else {
        if (pos > n) return;
        bitmask(pos + 1, type, val);
        if (val + a[pos] <= target) {
            int uld = target - (val + a[pos]);
            add(uld);
            bitmask(pos + 1, type, val + a[pos]);
        }
    }
}

int main() {
    IOS
    cin >> n >> target;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bitmask(1, 0, 0); // index 1 to (n / 2)
    l.pb(0);
    sort(l.begin(), l.end());
    add(target); // the first half make the target
    bitmask(n / 2 + 1, 1, 0); // index (n / 2 + 1) to n
    cout << ans << '\n';
    return 323 / 1001;
}

// Problem URL: https://cses.fi/problemset/task/1628