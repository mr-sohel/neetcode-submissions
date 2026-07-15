public class Solution {

    int[] dp;
    int f(int i, int [] nums) {
        if(i >= nums.Length) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int left = nums[i] + f(i+2, nums);
        int right = f(i+1, nums);

        return dp[i] = Math.Max(left, right);

    }
    public int Rob(int[] nums) {
        dp = new int [101];
        for(int i = 0; i < 101; i++) {
            dp[i] = -1;
        }
        return f(0, nums);
    }
}