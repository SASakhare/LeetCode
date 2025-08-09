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

    void dfs(TreeNode * root,int q,vector<vector<int>>&ans,int ind)
    {
        // base case :
        if(root==nullptr)
        {
            return ;
        }

        // recursive case :
        if(root->val==q)
        {
            ans[ind][0]=q;
            ans[ind][1]=q;
            return ;
        }

        // root -> val > q , ie. go to left 
        if(root->val>q)
        {   
            ans[ind][1]=root->val;
            dfs(root->left,q,ans,ind);
        }else
        {
            ans[ind][0]=root->val;
            dfs(root->right,q,ans,ind);
        }
        return ;
    }

    void inorder(TreeNode * root,vector<int>&in)
    {
        // base case :
        if(root==nullptr)
        {
            return ;
        }

        // recurisive case :
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
        return ;
    }

    void qAns(vector<vector<int>>&ans,vector<int>&in,int q,int ind)
    {

            int low=0;
            int high=in.size()-1;

            while(low<=high)
            {
                int mid = (low+high)/2;

                if(in[mid]==q)
                {
                    ans[ind][0]=q;
                    ans[ind][1]=q;
                    break;
                }else if(in[mid]>q)
                {
                    ans[ind][1]=in[mid];
                    high=mid-1;
                }else
                {
                    ans[ind][0]=in[mid];
                    low=mid+1;
                }
            }

            return ;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        int n=queries.size();
        vector<vector<int>>ans(n,vector<int>(2,-1));
        vector<int>in;
        inorder(root,in);

        for(int i=0;i<n;i++)
        {
            // dfs(root,queries[i],ans,i);
             qAns(ans,in,queries[i],i);            

        }
        
        return ans;
    }
};