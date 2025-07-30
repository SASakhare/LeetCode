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
// Method 1 :
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
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//            if(root==nullptr)
//     {
//         return {};
//     }

//     queue<pair<TreeNode*,int>> qu;
//      map<int,int>mp;

//     qu.push({root,0});

//     while(!qu.empty())
//     {

//         auto ele=qu.front();
//         qu.pop();
      
//         mp[ele.second]=ele.first->val;
        

//         if(ele.first->left!=nullptr)
//         {
//             qu.push({ele.first->left,ele.second+1});
//         }

//         if(ele.first->right!=nullptr)
//         {
//             qu.push({ele.first->right,ele.second+1});
//         }

//     }


//     vector<int>res;

//     for(auto p : mp)
//     {
//         res.push_back(p.second);
//     }

//     return res;
//     }
// };


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        // base 
        if(!root)
        {
            return {};
        }

        queue<pair<TreeNode * ,int>>q;// Node,level
        // map<int,int>mp;// to track the element
        vector<int>temp;
        q.push(make_pair(root,0));// root,level=0

        while(!q.empty())
        {
            temp.push_back(q.front().first->val);
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode * node=q.front().first;
                int level=q.front().second;
                q.pop();
                if(node->right)
                {
                    q.push(make_pair(node->right,level+1));
                }
                if(node->left)
                {
                    q.push(make_pair(node->left,level+1));
                }
            }
        }

        return temp;        
    }
};