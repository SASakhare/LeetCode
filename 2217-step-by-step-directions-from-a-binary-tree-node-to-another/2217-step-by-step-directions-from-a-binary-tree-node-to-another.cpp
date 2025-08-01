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

    TreeNode * LCA(TreeNode * root,int s,int d)
    {
        // base case :
        if(!root)
        {
            return root;
        }

        //recursive case :

        if(root->val==s || root->val==d)
        {
            return root;
        }


        TreeNode * left=LCA(root->left,s,d);
        TreeNode * right=LCA(root->right,s,d);

        if(left && right)
        {
            return root;
        }

        return left ? left : right;
    }

    bool findPath(TreeNode * root,string & path,int value)
    {
        // base case :
        if(!root)
        {
            return false;
        }

        if(root->val == value)
        {
            return true;
        }
        // try the left side :
        path.push_back('L');
        if(findPath(root->left,path,value))
        {
            return true;
        }

        path.pop_back();

        // try the right side :
        path.push_back('R');

        if(findPath(root->right,path,value))
        {
            return true;
        }

        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        

        // 1st . find the LCA :
        TreeNode * lca=LCA(root,startValue,destValue);

        // lca to start path : Here we just move upward or not(if start node itself the lca)
        
        string lca_to_start="",lca_to_dest="";

        findPath(lca,lca_to_start,startValue);
        findPath(lca,lca_to_dest,destValue);


        // since for lca to start all the we are moving upward :
        for(char & c:lca_to_start)
        {
            c='U';
        }

        return lca_to_start+lca_to_dest;
    }
};