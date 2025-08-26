class Solution {

    bool dfs(vector<vector<int>> &adjList,int Node,int dest,vector<int>&vis)
    {
        vis[Node]=1;
        if(Node == dest)
            return true;
        

        for(auto it:adjList[Node])
        {
            if(!vis[it] && dfs(adjList,it,dest,vis)) // if not visited node then go to visited and after visiting the node return the true then there exist the dest  so return the true and go to another node
            {
                return true;
            }
        }

        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // creating the adjacency list :
        vector<vector<int>> adjList(n);

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // creating the visited array :
        vector<int>vis(n,0);// 0 --> unvisited and 1 ---> visited
        return dfs(adjList,source,destination,vis);
    }
};