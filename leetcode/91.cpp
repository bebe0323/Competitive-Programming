#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < s.size(); i++) {
            // 1 -> 9
            if ('1' <= s[i] && s[i] <= '9') {
                if (i == 0) dp[i] = 1;
                else dp[i] += dp[i - 1];
            }
            // 10 -> 19
            if (i > 0 && s[i - 1] == '1') {
                if (i == 1) dp[i]++;
                else dp[i] += dp[i - 2];
            }
            // 20 -> 26
            if (i > 0 && s[i - 1] == '2' && s[i] <= '6') {
                if (i == 1) dp[i]++;
                else dp[i] += dp[i - 2];
            }
        }
        return dp[s.size() - 1];
    }
};