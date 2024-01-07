#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    string s;
    int n;
    cin >> n >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') a++;
        else b++;
    }
    int ans = max(a, b) - min(a, b);
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
