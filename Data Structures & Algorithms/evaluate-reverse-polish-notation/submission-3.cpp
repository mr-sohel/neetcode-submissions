class Solution {
public:
    bool isOperator(const string& ch) {
        return ch == "+" or ch == "-" or ch == "*" or ch == "/";
    }

    int eval(int a, int b, const string& ch) {
        if(ch == "+") return a + b;
        if(ch == "-") return a - b;
        if(ch == "*") return a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const auto& it : tokens) {
            if(isOperator(it)) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(eval(b, a, it));
            } 
            else {
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};