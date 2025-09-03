class Solution {
public:

    void findCombSum(vector<vector<int>> & res,vector<int> & candidates,int target,int index,vector<int> temp)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                res.push_back(temp);
            }
            return ;

        }

        // pick condition;

        if(candidates[index]<=target)
        {
        temp.push_back(candidates[index]);
         findCombSum(res,candidates,target-candidates[index],index,temp);
         temp.pop_back();   
        }


        findCombSum(res,candidates,target,index+1,temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        

        vector<vector<int>> res;

        findCombSum(res,candidates,target,0,{});

        return res;
    }
};