class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>>  mp;
        for(auto &it: strs) {
            string x = it;
            sort(x.begin(),x.end());
            mp[x].push_back(it);
        }

        for(auto &[x,y] : mp) {
            ans.push_back(y);            
        }
        return ans;
    }
};
