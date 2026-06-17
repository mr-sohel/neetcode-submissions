class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto &it: nums) {
            freq[it]++;
        }
        vector<pair<int,int>> ans;
        for(auto [x,y]: freq) {
            ans.push_back({y,x});
        }
        sort(ans.rbegin(), ans.rend());
        vector<int> x;
        for(int i = 0; i < k; i++) {
            x.push_back(ans[i].second);
        }
        return x;
    }
};
