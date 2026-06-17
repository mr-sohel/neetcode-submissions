class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>  mp;
        for(auto it: strs) {
            string x = it;
            sort(it.begin(),it.end());
            mp[it].push_back(x);
        }

        for(auto [x,y] : mp) {
            ans.push_back(y);            
        }
        return ans;
    }
};
