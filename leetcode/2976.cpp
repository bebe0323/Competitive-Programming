#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ff first
    #define ss second
    int total_cost[200][200];
    priority_queue<pair<int,int>> pq;
    int visited[200];
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for (int i = 0; i < original.size(); i++) {
            if (total_cost[original[i]][changed[i]] == 0) {
                total_cost[original[i]][changed[i]] = cost[i];
            } else {
                total_cost[original[i]][changed[i]] = min(cost[i], total_cost[original[i]][changed[i]]);
            }
        }
        for (int k = 'a'; k <= 'z'; k++) {
            for (int i = 'a'; i <= 'z'; i++) {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (total_cost[i][k] != 0 && total_cost[k][j] != 0) {
                        if (total_cost[i][j] == 0) total_cost[i][j] = total_cost[i][k] + total_cost[k][j];
                        else total_cost[i][j] = min(total_cost[i][j], total_cost[i][k] + total_cost[k][j]);
                    }
                }
            }
        }
        long long ret = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (total_cost[source[i]][target[i]] == 0) return -1;
                ret = (long long) ret + total_cost[source[i]][target[i]];
            }
        }
        return ret;
    }
};