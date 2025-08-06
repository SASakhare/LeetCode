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
public:
    void inorder(TreeNode *root,vector<int>&in)
    {
        if(root==nullptr)
        {
            return ;
        }

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
        return ;
    }

    TreeNode * balanceBSTHelper(vector<int>&in,int low,int high)
    {
        if(low>high)
        {
            return nullptr;
        }

        int ind=(high+low)/2;
        TreeNode * root=new TreeNode(in[ind]);
        root->left=balanceBSTHelper(in, low,ind-1);
        root->right=balanceBSTHelper(in,ind+1, high);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int>in;
        inorder(root,in);

        return balanceBSTHelper(in,0,in.size()-1);
    }
};