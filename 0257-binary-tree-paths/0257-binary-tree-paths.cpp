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

    void fun(TreeNode * root,vector<string>&res,string st)
    {
        // base case :
        st+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            res.push_back(st);
            return ;
        }

        // recurisive case :

        if(root->left)
        {
            fun(root->left,res,st+"->");
        }

        if(root->right)
        {
            fun(root->right,res,st+"->");
        }

        return ;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>res;
        fun(root,res,"");
        return res;
    }
};