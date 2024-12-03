class MinStack {
private:
    stack<int> data_;
    stack<int> minStk_;
public:
    MinStack() { }
    
    void push(int val) {
        data_.push(val);
        minStk_.push(minStk_.empty() ? val : min(minStk_.top(), val));
    }
    
    void pop() {
        data_.pop();
        minStk_.pop();
    }
    
    int top() {
        return data_.top();
    }
    
    int getMin() {
        return minStk_.top();
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