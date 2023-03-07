#include "tool.h"

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