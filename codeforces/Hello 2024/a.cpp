#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

void solve() {
    ll a, b;
    cin >> a >> b;
    a += b;
    if (a % 2 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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

// Problem URL: https://codeforces.com/contest/1919/problem/A