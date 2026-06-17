#define sz(x) x.size()
class Solution {
public:
    string encode(vector<string> strs) {
            string res = "";
            for(int i = 0; i < sz(strs); i++) {
                res += to_string(sz(strs[i])) + "#" + strs[i];
            }
            return res;
        }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < sz(s)) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};
