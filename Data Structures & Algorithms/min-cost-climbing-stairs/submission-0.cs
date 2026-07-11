public class Solution {
    int[] dp = new int[101];

    public int f(int i, ref int[] cost) {
        if(i >= cost.Length) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
       
        return dp[i] = cost[i] + Math.Min(f(i+1, ref cost), f(i+2, ref cost));
    }
    public int MinCostClimbingStairs(int[] cost) {
        for (int i = 0; i < 101; i++) dp[i] = -1;

        return Math.Min(f(0, ref cost), f(1, ref cost));
    }
}
