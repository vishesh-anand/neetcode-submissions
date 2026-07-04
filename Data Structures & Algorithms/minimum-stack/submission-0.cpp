class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val); 
       if(mins.empty() || mins.top()>=val) mins.push(val);
       else{
        mins.push(mins.top());
       } 
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();

    }
};
