#include "tool.h"
/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
ListNode * addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode dummy;
    ListNode *cur=&dummy;
    int carry=0;

    while(l1||l2)
    {
        int num1=l1?l1->val:0;
        int num2=l2?l2->val:0;
        int sum=num1+num2+carry;
        carry=sum/10;
        sum=sum%10;
        cur->next=new ListNode(sum);
        cur=cur->next;
        if(l1)
        {
            l1=l1->next;
        }
        if(l2)
        {
            l2=l2->next;
        }
    }
    if(carry)
    {
        cur->next=new ListNode(1);
        cur=cur->next;
    }
    cur->next=nullptr;
    return dummy.next;
}

int main()
{
    auto example={1,2,34,6};
    auto example2={9,9,9,9,9,9,9};
    ListNode *l1= buildList(example);
    ListNode *l2=buildList(example2);
    ListNode * sum=addTwoNumbers(l1,l2);
    sum->print();
}