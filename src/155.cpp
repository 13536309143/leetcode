#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    
public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    
    cout << "Test Case:" << endl;
    cout << "Operations: [\"MinStack\",\"push\",\"push\",\"push\",\"getMin\",\"pop\",\"top\",\"getMin\"]" << endl;
    cout << "Arguments: [[],[-2],[0],[-3],[],[],[],[]]" << endl;
    
    obj->push(-2);
    cout << "push(-2) -> null" << endl;
    
    obj->push(0);
    cout << "push(0) -> null" << endl;
    
    obj->push(-3);
    cout << "push(-3) -> null" << endl;
    
    cout << "getMin() -> " << obj->getMin() << endl;
    
    obj->pop();
    cout << "pop() -> null" << endl;
    
    cout << "top() -> " << obj->top() << endl;
    
    cout << "getMin() -> " << obj->getMin() << endl;
    
    delete obj;
    
    return 0;
}