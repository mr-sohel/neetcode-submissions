class MinStack {
public:
    vector<pair<int,int>> stack;  
    void push(int val) {
        if(stack.empty()) {
            stack.push_back({val,val});
        } else {
            int prev = stack.back().second;
            stack.push_back({val, min(val, prev)});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};