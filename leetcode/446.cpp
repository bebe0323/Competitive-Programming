#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ff first
    #define ss second
    #define ll long long
    unordered_map<ll, int> mp[1005];
    unordered_map<ll, int> :: iterator it, it1;
    int ans;
    int dp[1005][1005];
    int numberOfArithmeticSlices(vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                mp[i][(ll) v[i] - v[j]] = 1;
            }
            int cnt = 0;
            // compressing the differences at position i to all the previous positions
            for (it = mp[i].begin(); it != mp[i].end(); it++) {
                mp[i][it->ff] = cnt;
                cnt++;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < i; j++) {
                ll dif = (ll) v[i] - v[j];
                it = mp[j].find(dif);
                it1 = mp[i].find(dif);
                if (it != mp[j].end()) {
                    int cnt = dp[j][it->ss]; // at pos j, mp[it->ff] difference
                    dp[i][it1->ss] += cnt;
                    ans += cnt;
                }
                dp[i][it1->ss]++;
            }
        }
        return ans;
    }
};

// Problem URL: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/