public class Solution {  
    List<string> ans = new List<string> ();
    void f(int pos, int cnt, int n, string s) {
        if(cnt < 0) return;
        if(s.Length == n) {
            if(cnt == 0) {
                ans.Add(s);
            }
            return;
        }
        f(pos + 1, cnt + 1, n, s + "(");
        f(pos + 1, cnt - 1, n, s + ")");
    }

    public List<string> GenerateParenthesis(int n) {
        f(0,0,2*n, "");
        return ans;
    }
}
