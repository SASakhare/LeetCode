class Solution {
    int mod=(int)(1e9+7);
    int dfs(int u,vector<int>&dp,int &n, vector<vector<pair<int,int>>>&adjList,vector<long long>&dist)
    {
        // is this last node
        if(u==n)
        {
            return 1;
        }
        
        if(dp[u]!=-1)
        {
            return dp[u];
        }
        long long ways=0;
        for(auto [v,wt]:adjList[u])
        {
            if(dist[u]>dist[v])
            {
                ways= (ways + dfs(v,dp,n,adjList,dist)) % mod;
            }
        }

        return dp[u]= (int)(ways % mod );
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        // making the graph 

        int m=edges.size();
        vector<vector<pair<int,int>>>adjList(n+1);// 1 to n so n+1 nodes

        for(int i=0;i<m;i++)
        {
          int u=edges[i][0];
          int v=edges[i][1];
          int wt=edges[i][2];

          adjList[u].push_back({v,wt});
          adjList[v].push_back({u,wt});
        }

        // applying the dijkstra from src  = n:

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<long long>dist(n+1,LLONG_MAX);
        dist[n]=0;
        pq.push({0,n});

        while(!pq.empty())
        {
            long long dst=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto [adjNode,wt]:adjList[node])
            {
                if(wt+dst<dist[adjNode])
                {
                    dist[adjNode]=wt+dst;
                    pq.push({wt+dst,adjNode});
                }
            }
        }


        //  unreachable node haiving the distance INT_MAX;
        // int mode = (int)(1e9+1);
        // long long ans=0;
        // set<vector<int>>q;// storing the vector as element inside the queue
        // q.insert({1}); // source node 1 we have to reach to dst = 5

        // while(!q.empty())
        // {
        //     vector<int> vec=*q.begin();
        //     // q.pop();
        //     q.erase(vec);
        //     int node=vec.back();// last node

        //     // current node is end node then we have to add to the ans
        //     if(node == n)
        //     {
        //         ans = (ans +1) % mode;
        //         continue;
        //     }
        //     for(auto [adjNode,wt]:adjList[node])
        //     {
        //         if(dist[node]>dist[adjNode])
        //         {
        //             vec.push_back(adjNode);
        //             // q.push(vec);
        //             q.insert(vec);
        //             vec.pop_back();
        //         }   
        //     }
        // }

        // return ans % mode;

        // dp solution for memory efficient :
        vector<int>dp(n+1,-1);
        dfs(1,dp,n,adjList,dist);


        return dp[1];// 
    }
};