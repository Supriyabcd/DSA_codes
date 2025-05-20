#include<bits/stdc++.h>
using namespace std;

class MinStack_1{
    public:

        stack<pair<int,int>> st;

        void push(int val){
            if(st.empty()){
                st.push({val,val});
            } else {
                    st.push({val, min(val ,st.top().second)});   
            }
        }

        void pop(){
            if(st.empty()) return;
            st.pop();
        }

        int top(){
            if(st.empty()) return -1;
            return st.top().first;
        }

        int getMin(){
            if(st.empty()) return -1;
            return st.top().second;
        }
};

class MinStack {
public:
    MinStack() {}
    
    stack<long long> st;
    long long mini ;

    void push(int val) {
        if(st.empty()){
                mini = val; 
                st.push(val);
            } else {
                if(val >= mini){
                    st.push(val);
                } else {
                st.push(2LL*val - mini);
                mini = val;  
                }
            }
    }
    
    void pop() {
        if(st.empty()) return;
            long long x = st.top();
            st.pop();
            if(x < mini){
                mini = 2LL*mini - x;
            }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top(); 
        if(mini <= x) return x;
        return mini;
    }
    
    int getMin() {
            if(st.empty()) return -1;
            return mini;
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