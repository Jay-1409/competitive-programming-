class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> deg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            deg[i[0]]++;
        }  
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> vis(numCourses, false);
        while(!q.empty()) {
            auto course = q.front(); q.pop();
            vis[course] = true;
            for(auto &i : adj[course]) {
                if(!vis[i]) {
                    deg[i]--;
                    if(deg[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        for(auto &i : vis)
            if(!i)
                return false;
        return true;
    }
};