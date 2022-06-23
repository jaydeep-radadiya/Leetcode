class MinStack {
private:
    stack<int> s; // stack
    stack<int> ss; // supporting stack
    
public:
    MinStack() {
        // we don't need to assign any thing
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size()==0 or val<=ss.top()){
            ss.push(val);
        }
    }
    
    void pop() {
        int val = s.top();
        s.pop();
        if(ss.top()==val){
            ss.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};