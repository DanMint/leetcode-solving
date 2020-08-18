class Solution {
public:
    int numTeams(const vector<int>& rating) {
        int counter = 0;
        
        for (size_t i = 0; i < rating.size(); ++ i) {
            for (size_t j = 0; j < i; ++ j) {
                for (size_t k = 0; k < j; ++ k) {
                    if (rating[i] > rating[j] && rating[j] > rating[k]) 
                        ++ counter;

                    if (rating[i] < rating[j] && rating[j] < rating[k])
                        ++ counter;
                }
            }
        }
        
        return counter;
    }
};

