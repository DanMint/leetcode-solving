class Solution {
private:
    vector<vector<int>> map;
    vector<vector<int>> answer;
public:

    vector<vector<int>> findFarmland(vector<vector<int>> land) {
        map = land;
        /// here i want to find if a farm exists in a horizontal plot of land
        for (int i = 0; i < map.size(); i ++) {
            if (farmExists(i))
                findingFarms(i);
        }

        return answer;
    }

    void findingFarms (int farmLocOnY) {
            pair<int, int> initialFarm;
            for (int j = 0; j < map[farmLocOnY].size(); j ++) {
                if (map[farmLocOnY][j] == 1) {
                    initialFarm = {j, farmLocOnY};
                    break;
                }
            }

            int j = 1;
            int downOnY;
            while (true) {
                if (farmLocOnY + j == map.size()) {
                    downOnY = farmLocOnY + j - 1;
                    break;
                }

                if (map[farmLocOnY + j][initialFarm.first] == 0) {
                    downOnY = farmLocOnY + j - 1;
                    break;
                }

                j += 1;
            }

            pair<int, int> lastFarm;
            for (int k = 0; k < map[downOnY].size(); k ++) {
                if (k < initialFarm.first)
                    continue;

                else if (map[downOnY][k] == 0) {
                    lastFarm = {k - 1, downOnY};
                    break;
                }
                else if (k + 1 >= map[downOnY].size()) {
                    lastFarm = {k , downOnY};
                    break;
                }
            }

            makeZeros(initialFarm, lastFarm);

            answer.push_back({initialFarm.second, initialFarm.first, lastFarm.second, lastFarm.first});

            /// checking if there is more farms on the x-axis
            if (farmExists(farmLocOnY))
                findingFarms(farmLocOnY);
        }

    bool farmExists (const int horizontalPlotAxis) {
        /// checking if farm exists in the vector
        vector<int> strip = map[horizontalPlotAxis];
        if (find(strip.begin(), strip.end(), 1) != strip.end())
            return true;

        return false;
    }

    /// here we get the coordinates of the starting farm and ending farm and set them to zero also the between the farms set all to zero
    void makeZeros (const pair<int, int> start, const pair<int, int> end) {
        for (int i = start.second; i <= start.second + (end.second - start.second); i ++)
            for (int j = start.first; j <= start.first + (end.first - start.first); j ++)
                map[i][j] = 0;
    }
};
