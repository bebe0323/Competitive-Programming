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
 
int n,l,r;
vector<int> edge[N];
bool visited[N];
int cnt[N];
int child_mx[N];
 
void dfs(int node){
    visited[node] = 1;
    int mx = 0;
    cnt[node] = 1;
    for(int i = 0; i < edge[node].size(); i++){
        if(visited[edge[node][i]] == 0){
            dfs(edge[node][i]);
            cnt[node] += cnt[edge[node][i]];
            mx = max(mx, cnt[edge[node][i]]);
        }
    }
    child_mx[node] = mx;
}
 
int main(){
    IOS
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> l >> r;
        edge[l].pb(r);
        edge[r].pb(l);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(child_mx[i] <= n/2 && (n-cnt[i]) <= n/2){
            cout << i;
            return 0;
        }
    }
}