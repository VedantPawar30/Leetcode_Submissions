class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() != 1){
            int fr =q1.front();
            q2.push(fr);
            q1.pop();
        }

        int top = q1.front();
        q1.pop();
        while(!q2.empty()){
            int fr=q2.front();
            q1.push(fr);
            q2.pop();
        }
        return top;
    }
    
    int top() {
        while(q1.size() != 1){
            int fr =q1.front();
            q2.push(fr);
            q1.pop();
        }

        int top = q1.front();
        q1.pop();
        q2.push(top);
        while(!q2.empty()){
            int fr=q2.front();
            q1.push(fr);
            q2.pop();
        }
        return top;
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