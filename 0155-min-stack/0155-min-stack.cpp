// class MinStack {
// public:
//     long long minVal = INT_MAX;
//     stack<long long>st;
//     // stack<long long>st2;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         long long currVal = val;
//         if(val < minVal && !st.empty()) {
//             currVal = (2 * (long long)val) - minVal;
//             minVal = val;
//         }

//         if(st.empty()) minVal = val;
//         st.push(currVal);
//         // st2.push(val);
//     }
    
//     void pop() {
//         if(st.top() < minVal) {
//             minVal = (2*minVal) - (st.top());
//         }
//         st.pop();
//         // st2.pop();
//     }
    
//     int top() {
//         return st.top() < minVal ? minVal : st.top(); 
//     }
    
//     int getMin() {
//         return minVal;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */


class MinStack {
public:
    long long minVal = INT_MAX;
    stack<long long>st;
    stack<long long>st2;
    MinStack() {
        
    }
    
    void push(int val) {
        long long currVal = val;
        if(val < minVal && !st.empty()) {
            currVal = (2 * (long long)val) - minVal;
            minVal = val;
        }

        if(st.empty()) minVal = val;
        st.push(currVal);
        st2.push(val);
    }
    
    void pop() {
        if(st.top() != st2.top()) {
            minVal = (2*st2.top()) - (st.top());
        }
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st2.top();
    }
    
    int getMin() {
        return minVal;
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