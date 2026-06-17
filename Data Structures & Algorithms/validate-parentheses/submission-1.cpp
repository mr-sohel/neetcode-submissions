class Solution {
public:
    bool isOpen(char ch) {
        if(ch == '(' or ch == '{' or ch == '[') return true;
        return false;
    }
    bool isOkay(char open, char close) {
        if(open == '(' and close == ')') {
            return true;
        } else if(open == '{' and close == '}') {
            return true;
        } else if(open == '[' and close == ']') {
            return true;
        } 
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(isOpen(s[i])) {
                st.push(s[i]);
            } else {
                if(!st.empty() and isOkay(st.top(), s[i])) {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};
