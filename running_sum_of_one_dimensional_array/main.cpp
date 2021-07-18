class Solution {
public:
    vector<int> runningSum(const vector<int>& nums) {
        queue<int> addition;

        for (const int &el : nums) {
            if (addition.empty()) {
                addition.push(el);
            }
            else {
                int newEl;
                newEl = el + addition.back();
                addition.push(newEl);
            }
        }
        
        vector<int> answer;
        
        while (!addition.empty()) {
            answer.push_back(addition.front());
            addition.pop();
        }
        
        return answer;
    }
};

