class MyStack {
private:
    deque<int> q1;
public:
    MyStack(): q1{} {}
    
    void push(int x) {
        q1.push_back(x);
    }
    
    int pop() {
        int tmp=top();
        q1.pop_back();
        return tmp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */