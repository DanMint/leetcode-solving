class Solution {
public:
    enum visited {
        notVisited = 0,
        visiting = 1,
        doneVisiting = 2

    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> range(numCourses);
        for (int i = 0; i < numCourses; i ++)
            range.push_back(i);

        vector<int> ans;
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i ++)
                ans.push_back(i);

            return ans;
        }

        vector<int> visited(numCourses, notVisited);
        vector<vector<int>> graph(numCourses);
        graphCreation(prerequisites, graph);

        stack<int> toVisit;
        
        bool loop = false;

        topSort(toVisit, ans, graph, visited, loop);
        
        if (loop)
            return {};

        reverse(ans.begin(),ans.end());

        if (ans.size() == numCourses)
            return ans;

        else {

            for (const auto &el : range) {
                bool exists = false;
                for (const auto &elo : ans) {
                    if (el == elo) {
                        exists = true;
                        continue;
                    }
                }
                if (!exists)
                    ans.insert(ans.begin(),el);
            }

            return ans;
        }

    }

    void graphCreation (const vector<vector<int>>& a, vector<vector<int>> &b) {
        for (const auto &el : a)
            b[el[1]].push_back(el[0]);

    }
    
    void topSort (stack<int> &toVisit, vector<int> &ans,vector<vector<int>> graph, vector<int> &visited, bool &loop) {
        while (visited != vector<int> (visited.size(), doneVisiting)) {
            int starting = -1;
            for (int i = 0; i < visited.size(); i ++) {
                if (visited[i] == notVisited) {
                    starting = i;
                    break;
                }
            }

            visited[starting] = visiting;
            toVisit.emplace(starting);

            for (const auto &el : graph[starting]) {
                if (visited[el] == notVisited) {
                    toVisit.emplace(el);
                    break;
                }
            }

            while (!toVisit.empty()) {
                int top = toVisit.top();
                visited[top] = visiting;
                if (graph[top].empty()) {
                    visited[top] = doneVisiting;
                    ans.push_back(top);
                    toVisit.pop();
                    continue;
                }
                int numOfPushes = 0;
                for (const auto &el : graph[top]) {
                    if (visited[el] == notVisited) {
                        toVisit.emplace(el);
                        break;
                    }
                    else if (visited[el] == doneVisiting) {
                        ++ numOfPushes;
                        continue;
                    }
                    else if (visited[el] == visiting) {
                        loop = true;
                        return;
                    }
               }
                if (numOfPushes == graph[top].size()) {
                    visited[top] = doneVisiting;
                    toVisit.pop();
                    ans.push_back(top);
                    continue;
                }
            }

        }
    }
};
