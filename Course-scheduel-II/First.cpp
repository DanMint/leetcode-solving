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

        if (hasCycle(graph))
            return {};

        stack<int> toVisit;

        if (hasCycle(graph))
            return {};


        if (loopFinder(graph,numCourses))
            return {};

        topSort(toVisit, ans, graph, visited);

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

    bool loopFinder (vector<vector<int>> &graph, const int &k) {
        vector<visited> checker (k, notVisited);
        stack<int> toCheck;

        while(checker != vector<visited> (k, doneVisiting)) {
            int starting = -1;
            for (int i = 0; i < checker.size(); i ++) {
                if (checker[i] == notVisited) {
                    starting = i;
                    break;
                }
            }

            checker[starting] = visiting;
            toCheck.emplace(starting);
            for (const auto &el : graph[starting]) {
               if (checker[el] == notVisited) {
                   toCheck.emplace(el);
                   break;
               }
            }

            while (!toCheck.empty()) {
                int top = toCheck.top();
                checker[top] = visiting;
                if (graph[top].empty()) {
                    checker[top] = doneVisiting;
                    toCheck.pop();
                    continue;
                }

                int doneVisiting1 = 0;

                for (const auto &el : graph[top]) {
                    if (checker[el] == notVisited) {
                        toCheck.emplace(el);
                        break;
                    }
                    else if (checker[el] == doneVisiting) {
                        ++ doneVisiting1;
                        continue;
                    }
                    else if (checker[el] == visiting)
                        return true;
                }

                if (doneVisiting1 == graph[top].size()) {
                    checker[top] = doneVisiting;
                    toCheck.pop();
                    continue;
                }

            }
        }
        return false;
    }


    void topSort (stack<int> &toVisit, vector<int> &ans,vector<vector<int>> graph, vector<int> &visited) {
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

    bool hasCycle(vector<vector<int>> &graph) {
        for (int i = 0;i < graph.size(); i++) {
            for (const auto &el : graph[i]) {
                for (const auto &elo : graph[el]) {
                    if (elo == i)
                        return true;
                }
            }
        }
        return false;
    }


};
