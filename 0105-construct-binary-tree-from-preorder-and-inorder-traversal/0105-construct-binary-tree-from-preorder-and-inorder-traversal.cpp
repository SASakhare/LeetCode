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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        map<int,int> mp;

        int n=in.size();

        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }

        TreeNode * root= BuildTree(pre,0,pre.size()-1,in,0,in.size()-1,mp);

        return root;

    }

    TreeNode * BuildTree(vector<int>& pre,int startPre,int endPre,vector<int>& in,int startIn,int endIn,map<int,int> & mp)
    {
        if(startPre>endPre || startIn> endIn) return nullptr;

        TreeNode * root= new TreeNode(pre[startPre]);
        int rootIndex=mp[root->val];

        int numsLeft=rootIndex-startIn;// this is number of element in left side of the root index in the tree.

        root->left=BuildTree(pre,startPre+1,startPre+numsLeft,in,startIn,rootIndex-1,mp);

        root->right=BuildTree(pre,startPre+numsLeft+1,endPre,in,rootIndex+1,endIn,mp);

        return root;


    }


};