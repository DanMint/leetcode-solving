class Solution {
public:
    string removeOuterParentheses (string s) {
        queue<char> collector;
 
        size_t depth = 0;
 
        for (const char &el : s)
            if (
                (el == '(' && depth ++ != 0) ||
                (el == ')' && depth -- != 1)
            )
                collector.push(el);
 
        string answer;
 
        while (!collector.empty()) {
            answer += collector.front();
            collector.pop();
        }
 
        return answer;
    }
};

