class MinStack {
public:
    stack<int>s;
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int value) {
       s.push(value); 
       if(st.empty()){
        st.push(value);
       }
       else{
        st.push(min(value,st.top()));
       }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
            st.pop();
        }
        else{
            return;
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }
        else{
            return -1;
        }
    }
    
    int getMin() {
        return st.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */