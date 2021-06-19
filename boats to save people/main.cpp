class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer = 0;
        sort(people.begin(),people.end());
        int start = 0, end = people.size() - 1;
        int visited = 0;
        findingTerms(people, limit,answer, start, end, visited);
        return answer;
    }

    void findingTerms(vector<int> &people,const int &limit, int &answer, int &start, int &end, int &visited) {
        if (start >= end) {
            if (visited != people.size())
                ++ answer;
            return;
        }

        ++ answer;

        if (people[start] + people[end] <= limit) {
            visited+=2;
            return findingTerms(people, limit, answer, ++start, --end, visited);
        }
        ++ visited;
        return findingTerms(people, limit, answer, start, --end,visited);
    }
};
