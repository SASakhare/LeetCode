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
    private :
    void fun(TreeNode * root,int targetSum,int currentSum,vector<vector<int>>&res,vector<int>&temp)
    {

        //base case :
        if(!root)
        {
            if(targetSum==currentSum)
            {
                res.push_back(temp);   
            }
            return ;
        }

        // trying both direction :
        temp.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr)
        {
            fun(root->left,targetSum,currentSum+root->val,res,temp);
        }
        
         if(root->left)
        {
            fun(root->left,targetSum,currentSum+root->val,res,temp);
        } 
        
         if(root->right)
        {
            fun(root->right,targetSum,currentSum+root->val,res,temp);
        }

        temp.pop_back();

        return ;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>res;
        vector<int>temp;
        if(!root)
            return res;

        fun(root,targetSum,0,res,temp);

        return res;
    }
};