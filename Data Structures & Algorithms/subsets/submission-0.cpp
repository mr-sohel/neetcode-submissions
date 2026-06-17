class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int mask = 0; mask < (1LL << n); mask++) {
            vector<int> st;
            for(int i = 0; i < n; i++) {
                
                if(mask & (1LL << i)) {
                    st.push_back(nums[i]);
                }
            }
            ans.push_back(st);
        }
        return ans;
    }
};
