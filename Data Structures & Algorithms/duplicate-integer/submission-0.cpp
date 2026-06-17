class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }
        if(st.size() == nums.size()) {
            return false;
        } else return true;
    }
};