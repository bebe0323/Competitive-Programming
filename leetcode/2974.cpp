#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pb push_back
    vector<int> numberGame(vector<int>& v) {
        vector<int> ret;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i += 2) {
            ret.pb(v[i]);
            ret.pb(v[i - 1]);
        }
        return ret;
    }
};