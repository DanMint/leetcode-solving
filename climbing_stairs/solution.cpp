class Solution {
public:
    int climbStairs(int n) {
        const size_t stairsHeight = n + 1;
        stack<size_t> fibNums;
        fibNums.push(1);
        fibNums.push(1);

        for (size_t i = 2; i < stairsHeight; i ++) {
            const size_t a = fibNums.top();
            fibNums.pop();
            const size_t b = fibNums.top();
            fibNums.push(a);
            fibNums.push(a + b);
        }

        return fibNums.top();
    }
};
