/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

private :

TreeNode * fun(ListNode * head,ListNode * last)
{
    if(head==last || head==nullptr)
    {
        return nullptr;
    }

    ListNode * fast=head;
    ListNode * slow=head;
    while(fast!=last && fast->next!=last)
    {
        fast=fast->next->next;
        slow=slow->next;
    }


    // Creating the Node :
    TreeNode * node= new TreeNode(slow->val);
    // checking is this the leaf node :
    if(slow==head)
    {
        return node;
    }

    // going to left 
    node->left=fun(head,slow);
    node->right=fun(slow->next,last);

    return node;
}

public:
    TreeNode* sortedListToBST(ListNode* head) {

     return fun(head,nullptr);   
    }
};