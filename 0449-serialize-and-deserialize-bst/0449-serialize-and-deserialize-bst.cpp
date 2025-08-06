/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    void serializeHelper(TreeNode * root,string& s)
    {
        if(root==nullptr)
        {   
            s+="#,";
            return ;
        }
        s +=to_string(root->val)+",";
        serializeHelper(root->left, s);
        serializeHelper(root->right,s);

        return ;
    }
    string serialize(TreeNode* root) {
        string res="";
        serializeHelper(root,res);
        return res;
    }

    // Decodes your encoded data to tree.

    TreeNode * deserializeHelper(stringstream & s)
    {
        // base case :
        string element;
        getline(s,element,',');
        if(element=="#")
        {
            return nullptr;
        }


        TreeNode * root=new TreeNode(stoi(element));
         root->left = deserializeHelper(s);
         root->right= deserializeHelper(s);

        return root;
    }
    TreeNode* deserialize(string data) {
        
        stringstream s(data);
        return  deserializeHelper(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;