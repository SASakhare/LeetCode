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
void fun(TreeNode * root,long long & cnt)
    {
        if(root==nullptr)
        {
            return ;
        }

        // Right :
        fun(root->right,cnt);

        // Root :
        cnt+=root->val;
        root->val=cnt;

        // Left :
        fun(root->left,cnt);

        return ;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        long long cnt=0;
        fun(root,cnt);
        return root;
    }
};