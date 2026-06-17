class Solution {
public:
    bool isOperator(string ch) {
        return (ch == "+" or ch == "-" or ch == "*" or ch == "/");
    }
    int eval(int a, int b, string ch) {
        if(ch == "+") return a + b;
        else if(ch == "-") return a - b;
        else if(ch == "*") return a * b;
        else return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens) {
            if(it.size() == 1 and isOperator(it)) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(eval(b, a, it));
            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
