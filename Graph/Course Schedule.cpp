Approach 1: kahn's Algorithm (Topological Sort using BFS)
  
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj(numCourses);
        for(auto it: prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        // kahn's algo
    vector<int> indegree(numCourses,0);
    for(int i=0;i<numCourses;i++)
    {
        for(auto it: adj[i])
        {
         indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0;i<numCourses;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count =0;
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        count++;
       for(auto it: adj[node])
       {
        indegree[it]--;
        if(indegree[it] == 0)
        q.push(it);
       }
    }
    if(count == N) return true;
    }
};

Approach 2: DFS

Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;
Space Complexity: O(V), because, apart from the graph, we have 2 arrays of size V, to store the required information

  class Solution {
    private:
    bool isCycleDFS(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int node)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: adj[node])
        {
            if(vis[it] == 0)
            {
         // If a cycle is detected in DFS
                if(isCycleDFS(adj,vis,pathVis,it))
                return true;
            }
// If the neighbor is already being visited (back edge), cycle detected
        else{
       if(pathVis[it] == 1) return true;
        }

        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> adj[numCourses];
       for(auto it: prerequisites)
       {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
       }
       vector<int> vis(numCourses,0);
       vector<int> pathVis(numCourses,0);
       for(int i=0;i<numCourses;i++)
       {
        if(isCycleDFS(adj,vis,pathVis,i))
        return false;
       }
       return true;
    }
};
