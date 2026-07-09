public class Solution {
    public int count(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if((n & (1 << i)) != 0) {
                ans++;
            }
        }
        return ans;
    }
    public int[] CountBits(int n) {
        int[] ans = new int [n+1];
        for(int i = 0; i <= n;i++) {
            ans[i] = count(i);
        }
        return ans;
    }
}
