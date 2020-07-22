class Solution {
private:
    static stack<char> reduce (const string& source) {
        stack<char> reduced;
 
        for (const char &el : source) {
            if (el == '#' && !reduced.empty())
                reduced.pop();
 
            /// Here we have normal char (not #)
            else if (el != '#')
                reduced.push(el);
        }
 
        return reduced;
    }
 
    static bool compare (stack<char> first, stack<char> second) {
        if (first.size() != second.size())
            return false;
 
        while (!first.empty() && !second.empty()) {
            if (first.top() != second.top())
                return false;
 
            first.pop();
            second.pop();
        }
 
        return true;
    }
 
public:
    bool backspaceCompare(string S, string T) {
        return compare(reduce(S), reduce(T));
    }
};
