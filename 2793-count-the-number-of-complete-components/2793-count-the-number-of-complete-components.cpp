class Solution {
    void dfs(vector<vector<int>>&adjList,vector<int>&vis,int Node,int &totalNode,int &totalDegree)
    {
        // 
        vis[Node]=1;
        totalNode++;
        totalDegree+=adjList[Node].size();

        for(auto it:adjList[Node])
        {
            if(!vis[it])
            {
                dfs(adjList,vis,it,totalNode,totalDegree);
            }
        }

        return ;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        //  n is no. of node/vertices in the graph .
        vector<vector<int>>adjList(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        long long cnt=0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++)
        {
            int totalNode=0;
            int totalDegree=0;
            if(!vis[i])
            {
                // cnt++;
                dfs(adjList,vis,i,totalNode,totalDegree);
                int totalEdges=(totalNode * (totalNode-1))/2;
                if(totalEdges == (totalDegree/2))
                {
                    cnt++;
                }
            }
        }
        cout<<cnt;
        return cnt;
    }
};