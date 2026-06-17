#include <bits/stdc++.h>
class Solution {
public:
    int dp[50];
    int f(int i, int n) {
        if(i >= n) {
            if(i == n) {
                return 1;
            }
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int res = 0;
        res = f(i+1, n);
        res += f(i+2, n);
        return dp[i] = res;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return f(0, n);
    }
};