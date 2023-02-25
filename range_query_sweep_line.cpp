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
 
int n;
int x[N], y[N], xx[N], yy[N];
 
vector<int> sg[30];
map<int, int> mp,mm;
map<int, int> :: iterator it;
int cnt = 0;
ll ans = 0;
int level,zereg[30];
int l,r;
 
vector<int> v[300005][5]; 
 
void build_tree(){
    zereg[0] = 1;
    for(int i = 0; i <= 30; i++){
        if(zereg[i] >= cnt){
            level = i;
            break;
        }
        zereg[i+1] = zereg[i]*2;
    }
    for(int i = 0; i <= level; i++){
        for(int j = 0; j < zereg[i]; j++){
            sg[i].pb(0);
        }
    }
}
 
void dfs(int k, int x){
    int y = zereg[level - k] * x;
    int z = zereg[level - k] * (x + 1) - 1;
    if(l <= y && z <= r){
        ans += sg[k][x];
        return;
    }
    if(z < l || y > r || k == level) return;
    dfs(k + 1,x * 2);
    dfs(k + 1,x * 2 + 1);
}
 
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        mp[x[i]] ++;
        mp[xx[i]] ++;
        mm[y[i]] ++;
        mm[yy[i]] ++;
    }
 
    for(it = mm.begin(); it != mm.end(); it++){
        mm[it->ff] = cnt;
        cnt++;
    }
    build_tree();
    cnt = 0;
 
    for(it = mp.begin(); it != mp.end(); it++){
        mp[it->ff] = cnt;
        cnt++;
    }
 
    for(int i = 1; i <= n; i++){
        x[i] = mp[x[i]];
        xx[i] = mp[xx[i]];
        y[i] = mm[y[i]];
        yy[i] = mm[yy[i]];
        if(x[i] == xx[i]){ // vertical  
            v[x[i]][1].pb(i);
        }
        else{ // horizontal
            v[x[i]][2].pb(i);
            v[xx[i]][0].pb(i);
        }
    }
    
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < v[i][0].size(); j++){
            int pos = v[i][0][j];
            pos = y[pos];
            sg[level][pos]--;
            for(int k = level - 1; k >= 0; k--){
                pos /= 2;
                sg[k][pos] = sg[k + 1][pos * 2] + sg[k + 1][pos * 2 + 1];
            }
        }
        for(int j = 0; j < v[i][1].size(); j++){
            int pos = v[i][1][j];
            l = y[pos];
            r = yy[pos];
            l ++;
            r --;
            if(l >= r) continue;
            
            dfs(0,0);
        }
        for(int j = 0; j < v[i][2].size(); j++){
            int pos = v[i][2][j];
            pos = y[pos];
            sg[level][pos]++;
            for(int k = level - 1; k >= 0; k--){
                pos /= 2;
                sg[k][pos] = sg[k + 1][pos * 2] + sg[k + 1][pos * 2 + 1];
            }
        }
    }
    cout << ans << '\n';
}