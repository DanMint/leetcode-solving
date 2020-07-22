class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         set<int> t;
 
    for (const int& el : nums) { /// O(N) iterations
        /// WHERE THERE IS AN EL INSIDE THE SET:
        if (t.find(el) != t.end()) /// O(logN)
            return true;
 
        t.insert(el); /// O(logN)
    }
 
    return false;
    }
};
