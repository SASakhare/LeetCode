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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode * > st;
        // creating the stacK:
        TreeNode * node=root;
        while(node!=nullptr)
        {
            st.push(node);
            node=node->left;
        }

        int cnt=0;

        while(!st.empty())
        {
            TreeNode * node=st.top();st.pop();
            cnt++;
            if(cnt==k)
            {
                return node->val;
            }

            node=node->right;

            while(node!=nullptr)
            {
                st.push(node);
                node=node->left;
            }
        }

        return -1;
    }
};