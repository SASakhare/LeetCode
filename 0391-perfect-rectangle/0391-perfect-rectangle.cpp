class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        map<pair<int,int>,int>mp;// point,count 

        // int n=rectangles.size();

        for(auto& rec : rectangles)
        {
            mp[{rec[0],rec[1]}]+=1;// BL
            mp[{rec[2],rec[3]}]+=1;// TR
            mp[{rec[0],rec[3]}]-=1;// TL 
            mp[{rec[2],rec[1]}]-=1;// BR
        }

        int cnt=0;

        for(auto & [point,count] :mp)
        {
            if(count!=0 && abs(count)==1)
               cnt++;
            else if(count!=0)
                return false;
        }


        return cnt==4;

    }
};