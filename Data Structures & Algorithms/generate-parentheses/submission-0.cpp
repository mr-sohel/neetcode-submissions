class Solution {
public:
    vector<string> ans;
    void f(int pos, int cnt, int n, string s) {
        if(cnt < 0) return;
        if(s.size() == n) {
            if(cnt == 0) {
                ans.push_back(s);
            }
            return;
        }
        f(pos + 1, cnt + 1, n, s + "(");
        f(pos + 1, cnt - 1, n, s + ")");
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        f(1, 0, 2*n, s);
        return ans;
    }
};
