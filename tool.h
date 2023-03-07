#include <bits/stdc++.h>
using namespace std;
//会得到一个随机数组，m，n是长和宽，当我们sort_val的时候，他会形成一个从左上角向右下角递增的平面
vector<vector<int>> getRandom2D(int m,int n,bool sort_val=false)
{
    vector<vector<int>> res(m,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        cout<<setw(3)<<0<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<setw(3)<<0<<" ";
        for(int j=1;j<n;j++)
        {
            if(!sort_val)
            res[i][j]=rand()%100;
            else
            res[i][j]=max(res[i-1][j],res[i][j-1])+rand()%5;
            cout<<setw(3)<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;
}
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