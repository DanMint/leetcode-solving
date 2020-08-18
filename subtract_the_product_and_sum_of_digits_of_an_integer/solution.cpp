
class Solution {
public:
    int subtractProductAndSum(const int &n) {
       int remember = n;
       vector<int> brokenValues;

        while (remember != 0) {
            int l = remember%10;
            brokenValues.push_back(l);
            remember = remember/10;
        }

        int productOfValues = 1;

        for (const int &el : brokenValues) {
            productOfValues = productOfValues * el;
        }

        int sum = 0;

        for (const int &el : brokenValues) {
            sum = sum + el;
        }

        return (productOfValues - sum);

    }
};

