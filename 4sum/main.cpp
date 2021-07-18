class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int answer = 0;
        /// here i will be creating a unorderd map of the sums on all nums1 + nums2 and all nums3 + nums4;

        /// in the unorderd map the key is the sum and the value is the amount of reps meaning diffrent nums that create the same sum
        unordered_map<int,int> sumsOf12;
        unordered_map<int,int> sumsOf34;

        mapCreation(nums1, nums2, sumsOf12);
        mapCreation(nums3, nums4, sumsOf34);

        /// here we want to find the other sum to make a zero
        for (const auto &el : sumsOf12) {
            int toFind = -el.first;
            auto search = sumsOf34.find(toFind);
            if (search != sumsOf34.end()) {
                int targetFound = el.second * search->second;
                if (targetFound == 0)
                    ++ targetFound;
                answer += targetFound;
            }
        }

        return answer;
    }

    void mapCreation (vector<int>& a, vector<int>& b, unordered_map<int,int> &c) {
        for (const auto &el : a) {
            for (const auto &elo : b) {
                int sum = el + elo;
                auto search = c.find(sum);

                if (search != c.end())
                    search->second = ++ search->second;

                else
                    c.insert({sum, 1});
            }
        }
    }
};
