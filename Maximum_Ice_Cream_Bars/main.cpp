class Solution {
public:
    int maxIceCream(vector<int> costs, int coins) {
        sort(costs.begin(), costs.end());

        int sum = 0;
        int iceAmount = 0;
        for (int i = 0; i < costs.size(); i ++) {
            if (sum < coins && costs[i] <= coins && sum + costs[i] <= coins) {
                sum += costs[i];
                iceAmount += 1;
                continue;
            }
            break;
        }
        return iceAmount;
    }
};
