// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int, int>> mainStack; 
public:
    MinStack() {
    }
    
    void push(int val) {
        if(mainStack.empty()) {
            mainStack.push({val, val});
        } else {
            int currentMin = mainStack.top().second;
            mainStack.push({val, min(val, currentMin)});
        }
    }
    
    void pop() {
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top().first;
    }
    
    int getMin() {
        return mainStack.top().second;
    }
};