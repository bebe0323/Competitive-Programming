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
 
const int N = 100005;
 
int n;
pair<ll, ll> p[N];
ll num, sum, product;
ll pre[N], suf[N];
 
ll numOfDivisors() {
    ll ret = 1;
    for (int i = 0; i < n; i++) {
        ret = (ll) (ret * (p[i].ss + 1)) % MOD;
    }
    return ret;
}
 
ll power(ll x, ll y, ll mod) {
    // x ^ y
    ll ret = 1;
    while (y > 0) {
        if ((y & 1) != 0) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        y = y >> 1;
    }
    return ret;
}
 
ll divide(ll x, ll y) {
    ll ret = (x * power(y, MOD - 2, MOD)) % MOD;
    return ret;
}
 
ll sumOfDivisors() {
    ll ret = 1;
    for (int i = 0; i < n; i++) {
        ll numerator = 1 - power((ll) p[i].ff, p[i].ss + 1, MOD);
        ll denominator = 1 - p[i].ff;
        ret = (ret * divide(numerator, denominator)) % MOD;
    }
    return ret;
}
 
ll productOfDivisors() {
    ll ret = 1;
    for (int i = 0; i < n; i++) {
        ll numDivisorsOut = 1;
        if (i != 0) numDivisorsOut = (numDivisorsOut * pre[i - 1]) % (MOD - 1);
        if (i != n - 1) numDivisorsOut = (numDivisorsOut * suf[i + 1]) % (MOD - 1);
        // (p^0) * (p^1) * ... * (p^k)
        // Fermat's little theorom
        ll y = (((ll) p[i].ss * (p[i].ss + 1)) / 2) % (MOD - 1);
        y = (y * numDivisorsOut) % (MOD - 1);
        ll tmp = power(p[i].ff, y, MOD) % MOD;
        ret = (ret * tmp) % MOD;
    }
    return ret;
}
 
int main() {
    IOS
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].ff >> p[i].ss;
        pre[i] = p[i].ss + 1;
        if (i > 0) {
            pre[i] = (pre[i] * pre[i - 1]) % (MOD - 1);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = p[i].ss + 1;
        if (i != n - 1) {
            suf[i] = (suf[i] * suf[i + 1]) % (MOD - 1);
        }
    }
    num = numOfDivisors();
    sum = sumOfDivisors();
    product =  productOfDivisors();
    cout << num << ' ' << sum << ' ' << product << '\n';  
    return 323 / 1001;
}
 
// Problem URL: https://cses.fi/problemset/task/2182