class Solution {
public:
    string defangIPaddr(string address) {
        queue<char> solution;

        for (const char &el : address) {
            if (el != '.') {
                solution.push(el);
            }
            else {
                solution.push('[');
                solution.push(el);
                solution.push(']');
            }
        }

        string answer;

        while (!solution.empty()) {
            answer.push_back(solution.front());
            solution.pop();
        }

        return answer;
    }
};


