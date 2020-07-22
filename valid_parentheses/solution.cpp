class Solution {
public:
    bool isValid(string sequence) {
        stack<int> sequenceStack;
   
    for (const char& ch : sequence) {
        if (ch == '(')
            sequenceStack.push(0);
 
        else if (ch == '[')
            sequenceStack.push(1);
 
        else if (ch == '{')
            sequenceStack.push(2);
 
            /// ch is ) or ] or }
        else {
            int tryPopValue;
 
            if (ch == ')')
                tryPopValue = 0;
 
            else if (ch == ']')
                tryPopValue = 1;
 
            else if (ch == '}')
                tryPopValue = 2;
 
            else
                break;
 
            /// Here we check that on the top of the stack we
            /// have exactly tryPopValue.
            if (!sequenceStack.empty() && sequenceStack.top() == tryPopValue)
                sequenceStack.pop();
 
            /// If we want to pop the value, but it is different that the
            /// value on the top of the stack.
            else
                return false;
        }
    }
 
    return sequenceStack.empty();
    }
};

