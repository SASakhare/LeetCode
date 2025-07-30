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
    void sumRL(TreeNode * root,long long& sum,int currNum)
    {
        if(root->left == nullptr &&  root->right==nullptr)
        {
            currNum=currNum*10+root->val;
            sum+=currNum;
            return ;
        }
        currNum=currNum*10+root->val;
        if(root->left)
        {
            sumRL(root->left,sum,currNum);
        }
        if(root->right)
        {
            sumRL(root->right,sum,currNum);
        }

        return  ;
    }

public:
    int sumNumbers(TreeNode* root) {
        
        if(!root)
        {
            return 0;
        }

        long long sum=0;
        sumRL(root,sum,0);

        return sum;
    }
};