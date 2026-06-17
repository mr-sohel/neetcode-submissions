class Solution {
public:
    bool isOpen(char ch) {
        return (ch == '(' or ch == '{' or ch == '[');
    }
    bool isOkay(char open, char close) {
        return ((open == '(' and close == ')') or (open == '{' and close == '}') or (open == '[' and close == ']'));
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(char &ch : s) {
            if(isOpen(ch)) {
                st.push(ch);
            } else {
                if(!st.empty() and isOkay(st.top(), ch)) {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};
