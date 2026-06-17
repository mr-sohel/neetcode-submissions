class Solution {
public:
    bool isOpen(char ch) {
        return (ch == '(' or ch == '{' or ch == '[');
    }
    bool isOkay(char open, char close) {
        return ((open == '(' and close == ')') or (open == '{' and close == '}') or (open == '[' and close == ']'));
    }
    bool isValid(string s) {
        vector<char> st;
        int n = s.size();
        for(char &ch : s) {
            if(isOpen(ch)) {
                st.push_back(ch);
            } else {
                if(!st.empty() and isOkay(st.back(), ch)) {
                    st.pop_back();
                } else return false;
            }
        }
        return st.empty();
    }
};
