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
 
int n,q,a;
int b[200005][30];
int node,k;
 
int main(){
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        cin >> a;
        b[i][0] = a;
    }
    for(int i = 1; i <= 30; i++){
        bool ok=0;
        for(int j = 1; j <= n; j++){
            if(b[b[j][i - 1]][i - 1] != 0){
                b[j][i] = b[b[j][i - 1]][i - 1];
                ok = 1;
            }
        }
        if(ok == 0) break;
    }
    while(q--){
        cin >> node >> k;
        int level = 0;
        bool ok = 0;
        while(k > 0){
            if(k % 2 == 1){
                if(b[node][level] == 0){
                    cout << "-1\n";
                    ok = 1;
                    break;
                }
                node = b[node][level];
            }
            k /= 2;
            level++;
        }
        if(ok == 0) cout << node << '\n';
    }
}