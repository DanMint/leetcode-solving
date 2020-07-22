    class Solution {
public:
    int calPoints(const vector<string>& ops) {
        stack<int> counter;

        for (const string &op : ops) {
            if (op == "C") {
                counter.pop();
            }
            else if (op == "D") {
                counter.push(counter.top() * 2);
            }
            else if (op == "+") {
                const int a = counter.top();
                counter.pop();
                const int b = counter.top();
                counter.push(a);
                counter.push(a + b);
            }
            else {
                counter.push(stoi(op));
            }
        }

        int sum = 0;
        while (!counter.empty()) {
            sum += counter.top();
            counter.pop();
        }
        return sum;
    }
};

