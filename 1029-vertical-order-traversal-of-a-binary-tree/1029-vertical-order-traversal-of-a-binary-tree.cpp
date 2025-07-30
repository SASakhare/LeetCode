/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void verticalDriver(TreeNode * root,map<int,map<int,multiset<int>>> &ds)
    {
        // base case :
        if(!root)
        {
            return ;
        }
        // Recursive case :
        int level=0;
        int col=0;
        queue<pair<TreeNode *,pair<int,int>> > q;// node , col,level
        q.push(make_pair(root,make_pair(col,level)));

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto item=q.front();
                q.pop();
                TreeNode * node=item.first;
                int col=item.second.first;
                int level=item.second.second;
                ds[col][level].insert(node->val);

                // now inserting the child of the node :
                if(node->left)
                {
                    q.push(make_pair(node->left,make_pair(col-1,level+1)));
                }
                if(node->right)
                {
                    q.push(make_pair(node->right,make_pair(col+1,level+1)));
                }
            }
        }

        return ;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>>ds;// col,level,element of each column in sorted ordered.

        verticalDriver(root,ds);
        // iterating throught the map :
        int size=ds.size();// no of column  
        vector<vector<int>>res(size);
        int i=0;
        for(auto x:ds)
        {
            // x.first --> column and x.second --> map<int,multiset<int>>
            for(auto y:x.second)
            {
                //y.first --> column and y.second multiset :
                for(auto z:y.second)
                { 
                    // element of multiset :
                    res[i].push_back(z);
                }
            }
            i++;
        }

        return res;
    }
};