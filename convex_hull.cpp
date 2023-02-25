#include<bits/stdc++.h>

using namespace std;

typedef complex <double> P;
typedef pair<long long, long long> Point;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define X real()
#define Y imag()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MOD 1000000007
#define MOD1 1000000009
#define sqr(x) ((x) * (x))

const int N = 200005;

vector<int> v;
int n;
bool ok = 0;
Point p1[N],p[N];

bool IsClockWise(Point a, Point b, Point c) {
    ll S = a.ff * (b.ss - c.ss) + b.ff * (c.ss - a.ss) + c.ff * (a.ss - b.ss);
    if(S == 0) {
        if(ok ==1) return sqr(a.ff - b.ff) + sqr(a.ss - b.ss) < sqr(a.ff - c.ff) + sqr(a.ss - c.ss);
        return false;
    }
    return S > 0;
}


bool cmp(Point a, Point b) {
    return IsClockWise(p[1], a, b);
}

void read_and_delete() {
    for(int i = 1; i <= n; i ++) {
        cin >> p1[i].ff >> p1[i].ss;
    }
    sort(p1 + 1, p1 + n + 1);
    int cnt = 1;
    p[1] = p1[1];
    for(int i = 2; i <= n; i ++) {
        if(p1[i] != p1[i - 1]) {
            cnt ++;
            p[cnt] = p1[i];
        }
    }
    n = cnt;
    return;
}

void solve() {
    read_and_delete();
    if(n == 1) {
        cout << "1\n";
        cout << p[1].ff << ' ' << p[1].ss << '\n';
        return;
    }
    ok = 1;
    sort(p + 2, p + n + 1, cmp);
    v.clear();
    v.pb(1);
    v.pb(2);
    ok = 0;
    for(int i = 3; i <= n; i ++) {
        while(v.size() >= 2 && IsClockWise(p[v[v.size() - 2]], p[v[v.size() - 1]], p[i]) == false) {
            v.pop_back();
        }
        v.pb(i);
    }
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i ++) {
        cout << p[v[i]].ff << ' ' << p[v[i]].ss << '\n';
    }
}

int main() {
    IOS
    for(;;) {
        cin >> n;
        if(n == 0) break;
        solve();
    }
}
