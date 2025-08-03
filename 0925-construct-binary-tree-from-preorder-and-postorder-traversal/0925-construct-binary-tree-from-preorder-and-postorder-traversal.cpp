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
    int pre_index=0;
    int post_index=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        TreeNode * root= new TreeNode(preorder[pre_index]);

        if(preorder[pre_index]==postorder[post_index])
        {
            pre_index++;
            post_index++;
            return root;
        }

        // recursivse case :
        pre_index++;

        root->left=constructFromPrePost( preorder, postorder);

        if(root->val !=postorder[post_index])
            root->right=constructFromPrePost( preorder, postorder);

        post_index++;

        return root;
    }
};