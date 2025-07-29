/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int findHeight(TreeNode* root) {
        // base case :

        if (root == nullptr) {
            return 0;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);

        return 1 + max(left, right);
    }

public:
    bool isCompleteTree(TreeNode* root) {

        // base case :
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        // 'bool flag = false;'

        long long height = findHeight(root);

        long long max_levels = height - 1;
        long long lev = 0; // current level:
        q.push(root);

        while (!q.empty()) {
            if (q.size() != pow(2, lev))
                return false;

            if (lev < (max_levels - 1)) {
                int n = q.size();
                for (int i = 0; i < n; i++) {
                    TreeNode* node = q.front();
                    q.pop();

                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }

            } else {
                // bool flag = (q.front()->left==nullptr && q.front()->right==nullptr); // for marking the boundary
                int n = q.size();
                bool flag=false;// it going to set by 2 condition : 1.got left one  2.got childless node

                for (int i = 0; i < n; i++) {
                    // if node has two child then ignore go forward
                    TreeNode* node = q.front();
                    q.pop();

                    if(!flag && (node->left ==nullptr && node->right))
                        return false;

                    if(!flag && node->right==nullptr)
                    {
                        flag=true;
                        continue;
                    }


                    if(flag && (node->left || node->right) )
                    {
                        // continue;
                        return false;
                    }



                }
            }

            lev++;
        }

        return true;
    }
};