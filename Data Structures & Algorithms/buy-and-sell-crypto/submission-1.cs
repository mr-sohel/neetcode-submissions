public class Solution {
    public int MaxProfit(int[] prices) {
        int ans = 0;
        int n = prices.Length;
        int mx = prices[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (mx > prices[i]) {
                int profit = mx - prices[i];
                ans = Math.Max(ans, profit);
            }
            mx = Math.Max(mx, prices[i]);
        }
        return ans;
    }
}
