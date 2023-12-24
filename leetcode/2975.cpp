#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pb push_back
    int mx = 0;
    long long area;
    unordered_map<int, bool> mp;
    unordered_map<int, bool> :: iterator it;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.pb(1);
        h.pb(m);
        v.pb(1);
        v.pb(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                // square side: h[i] -> h[j]
                int side_length = h[j] - h[i];
                mp[side_length] = true;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                // square side: v[i] -> v[j]
                int side_length = v[j] - v[i];
                it = mp.find(side_length);
                if (it != mp.end()) {
                    mx = max(mx, side_length);
                }
            }
        }
        if (mx == 0) return -1;
        area = (long long) mx * mx;
        
        int ret = area % 1000000007;
        return ret;
    }
};