class MyStack {
private:
    queue<int> s;

public:
    /** Initialize your data structure here. */
    MyStack() : s() {}

    /** Push element x onto stack. */
    void push(int x) {
        s.push(x);
        
        for (int i = 0; i < s.size() - 1; i++) {
            int oldFront = s.front();
            s.pop();
            s.push(oldFront);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int oldTop = top();
        s.pop();
        return oldTop;
    }

    /** Get the top element. */
    int top() {
        if (!s.empty())
            return s.front();
        else {
            throw "We could not return the top element because the stack is empty";
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return s.empty();
    }
};
