class RecentCounter {
private:
    queue<int> recentPings;
 
public:
    RecentCounter (): recentPings() {}
 
    int ping (const int& time) {
        recentPings.push(time);
 
        while (time - recentPings.front() > 3000)
            recentPings.pop();
 
        return recentPings.size();
    }
};
