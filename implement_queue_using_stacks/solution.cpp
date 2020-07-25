class MyQueue {
private:
    stack<int> myQueue;

public:
    /** Initialize your data structure here. */
    MyQueue () : myQueue() {}

    /** Push element x to the back of queue. */
    void push (int x) {
        stack<int> temp;
        
        while (!myQueue.empty()) {
            temp.push(myQueue.top());
            myQueue.pop();
        }
        
        myQueue.push(x);
        
        while (!temp.empty()) {
            myQueue.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop () {
        int peek = myQueue.top();
        myQueue.pop();
        return peek;
    }


    /** Get the front element. */
    int peek () {
        return myQueue.top();
    }

    /** Returns whether the queue is empty. */
    bool empty () {
        return myQueue.empty();
    }
};

