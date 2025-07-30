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
    void dfs(TreeNode * root,int targetSum,long long & res,long long currentSum)
    {   
        if(!root)
        {   
            return ;
        }
        currentSum+=root->val;
        if(currentSum==targetSum)
        {
            res+=1;
        }
        // base case :


        if(root->left==nullptr && root->right==nullptr)
        {
            dfs(root->left,targetSum,res,currentSum);
        }
        if(root->left)
        {
            dfs(root->left,targetSum,res,currentSum);

        }

        if(root->right)
        {
            dfs(root->right,targetSum,res,currentSum);
        }
        return ;
    }
    void travers(TreeNode * root,int targetSum,long long& res)
    {
        if(!root)
        {
            return ;
        }
        dfs(root, targetSum,res, 0);
        travers(root->left,targetSum,res);
        travers(root->right,targetSum,res);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {

        long long res=0;
        travers(root,targetSum,res);
        return res;
    }
};