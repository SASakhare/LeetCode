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
    int countNodes(TreeNode* root) {
        
        // if(root==nullptr) return 0;

        // queue<TreeNode * > qu;

        // qu.push(root);

        // int count=0;

        // while(!qu.empty())
        // {
        //    TreeNode * node = qu.front();
        //    qu.pop();

        //    if(node->left!=nullptr) 
        //    {
        //     qu.push(node->left);
        //    }

        //    if(node->right!=nullptr)
        //    {
        //     qu.push(node->right);
        //    }
        //    count++;
        // }

        // return count;


        // Method 2 : Recursive Traversal  Post Order :

        if(root==nullptr)
        {
            return 0;
        }

        int left=countNodes(root->left);
        int right=countNodes(root->right);

        return left+right+1;
    }
};