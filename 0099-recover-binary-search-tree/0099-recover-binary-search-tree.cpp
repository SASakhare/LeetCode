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
        TreeNode * prev=nullptr;
        TreeNode * first=nullptr;
        TreeNode * second=nullptr;

    void helper(TreeNode *root)
    {
        //base case :
        if(root==nullptr)
        {
            return ;
        }
        helper(root->left);

        // 
        if(prev && prev->val > root->val)
        {
            if(!first) first=prev;
            second=root;
        }
        prev=root;

        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {

        helper(root);

        //swap 
        if(first)
        {
            int temp=first->val;
            first->val=second->val;
            second->val=temp;
        }
        return ;
    }
};