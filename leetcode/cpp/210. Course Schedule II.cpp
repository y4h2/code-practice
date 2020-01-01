class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto it:prerequisites) {
            graph[it.second].push_back(it.first);
            ++indegree[it.first];
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
            }
                
        }
        
        int counter = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ++counter;
            for( auto v: graph[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                    result.push_back(v);
                }
            }
        }
        
        
        if (counter != numCourses)
            result.clear();
        return result;
    }
};
