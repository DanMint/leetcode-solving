#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> players;

        for (int i = 0; i < n; i ++)
            players.push_back(i + 1);

        int pushedOut = 0;

        int location = 1;
        int current = 0;
        int size = n;
        while (players.size() != 1) {

            current = current + k;

            if (current > size) {
                int diff = size - current;
                if (diff < 0)
                    diff = diff * -1;
                while (true) {
                    if (diff <= size)
                        break;
                    else
                        diff = diff - size;
                }
                players.erase(players.begin() + diff - 1);
                current = diff - 1;
                ++ pushedOut;
                size = size - pushedOut;
                pushedOut = 0;
                continue;
            }

            else if (current == size) {
                int currPos = current - pushedOut;
                players.erase(players.begin() + currPos - 1);
                current = 0;
                ++ pushedOut;
                size = size - pushedOut;
                pushedOut = 0;
                continue;
            }

            pushedOut = pushedOut +1;
            players.erase(players.begin() + current - pushedOut);
        }

        for (const auto &el : players)
            return el;

        return 0;
    }
};
