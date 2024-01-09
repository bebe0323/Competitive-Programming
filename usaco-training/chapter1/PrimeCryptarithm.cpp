/*
ID: belgute2
LANG: C++11
TASK: crypt1
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

bool a[10];

bool check(int val, int type) {
    int num_of_digit = 0;
    while (val > 0) {
        if (a[val % 10] == 0) return false;
        val /= 10;
        num_of_digit++;
    }
    if (type == -1 && num_of_digit != 2) return false;
    if (type == 0 && num_of_digit != 3) return false;
    if (type == 1 && num_of_digit != 4) return false;
    return true;
}

int main() {
    IOS
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        a[digit] = 1;
    }
    int ans = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = 10; j <= 99; j++) {
            if(
                check(i, 0) &&
                check(j, -1) &&
                check(i * (j % 10), 0) == 1 &&
                check(i * (j / 10), 0) == 1 &&
                check(i * j, 1) == 1
            ) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 323 / 1001;
}

// Problem URL: https://train.usaco.org/usacoprob2?a=feuUrAjHMhP&S=crypt1