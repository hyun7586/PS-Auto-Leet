class MinStack {
private:
    vector<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        int min_value = st.empty()?val:getMin();

        if(min_value>val) min_value=val;

        st.push_back(make_pair(val, min_value));
    }
    
    void pop() {
        if(!st.empty())
            st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */