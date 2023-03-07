#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode * next;
    ListNode ():val(0),next(nullptr){}
    ListNode (int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode *next):val(x),next(next){}
    ListNode(ListNode* next):val(0),next(next){}
    void print()
    {
        ListNode* cur=this;
        while(cur)
        {
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
};
ListNode *buildList(vector<int> nums)
{
    int n=nums.size();
    if(!n)
    {
        return nullptr;
    }
    ListNode * head=new ListNode(nums[0]);
    ListNode *cur=head;
    for(int i=1;i<n;i++)
    {
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    return head;
}






struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):value(val),left(nullptr),right(nullptr){}
};
//这是一份基于层序遍历的完全二叉树重建方法
TreeNode * buildTree(vector<string> & nums)
{
    int n=nums.size();
    if(!n)
    {
        return nullptr;
    }
    TreeNode *head=new TreeNode(stoi(nums[0]));
    queue<TreeNode*> q;
    q.push(head);
    int index=0;
    while(q.size())
    {
        auto i=q.front();
        q.pop();
        if(index<n)
        {
            if(nums[index]!="nullptr")
            {
                i->left=new TreeNode(stoi(nums[index]));
                q.push(i->left);
            }else
            {
                i->left=nullptr;
            }
            index++;   
        }
        
        if(index<n)
        {
            if(nums[index]!="nullptr")
            {
                i->right=new TreeNode(stoi(nums[index]));
                q.push(i->right);
            }else
            {
                i->right=nullptr;
            }
            index++;   
        }
    }
    return head;
    
}