class Solution {
public:
    vector<int> shuffle(const vector<int>& nums, int n) {
        vector<int> p(nums.size());
        for( int i = 0; i < n; i++ ){
            p[2*i] = nums[i];
            p[2*i + 1] = nums[n + i];
        }
        return p;
    }
};

