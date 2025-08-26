class Solution {
    private :
    void dfs(vector<vector<int>>&rooms,vector<int>&vis,int Node,int& cnt)
    {
        vis[Node]=1;
        cnt++;

        for(auto it:rooms[Node])
        {
            if(!vis[it])
            {
                dfs(rooms,vis,it,cnt);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int>vis(n,0);
        int cnt=0;

        dfs(rooms,vis,0,cnt);
        cout<<cnt<<endl;

        return cnt==n ; // checking the no of rooms visited is equal to the n , as total rooms is n.

    }
};