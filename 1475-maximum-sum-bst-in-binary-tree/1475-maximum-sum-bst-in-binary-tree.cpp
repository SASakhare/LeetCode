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
    int ans;
    vector<int> findMaxSumBst(TreeNode * root)
    {
        vector<int>status(3);// min , max,sum
        if(root==nullptr)
        {
            status[0]=INT_MAX;// it is min 
            status[1]=INT_MIN;// it is max :
            status[2]=0;
            return status;
        }

        vector<int> left=findMaxSumBst(root->left);
        vector<int> right=findMaxSumBst(root->right);



        if(root->val > left[1] && root->val < right[0])
        {
            status[0]=min(left[0],root->val);
            status[1]=max(root->val,right[1]);
            status[2]=root->val + left[2]+right[2];
            this->ans=max(this->ans,status[2]);
        }else
        {
            status[0]=INT_MIN;
            status[1]=INT_MAX;
            status[2]=max(left[2],right[2]);
        }
        return status;
    }
public:
    int maxSumBST(TreeNode* root) {
         this->ans=0;
        findMaxSumBst(root);
        return this->ans;
    }
};