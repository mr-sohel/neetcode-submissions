public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> set = new HashSet<int>(nums);
        int ans = 0;
        foreach(int num in set) {
            if(!set.Contains(num-1)) {
                int streak = 1;
                while(set.Contains(num + streak)) {
                    streak++;
                }
                ans = Math.Max(ans, streak);
            }
        }
        return ans;
    }
}
