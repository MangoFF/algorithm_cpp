#include <bits/stdc++.h>
using namespace std;
/*
给定两个有序数组，把两个数组合并为一个。
*/
/*
这里我们使用了 ++ 和--的小技巧：a++ 和 ++a 都是将 a 加1，但是 a++ 返回值为 a，而
++a 返回值为 a+1。如果只是希望增加 a 的值，而不需要返回值，则推荐使用++a，其运行速度
会略快一些。
*/
void mergeTwoArray(vector<int> &nums1,int m,vector<int> &nums2,int n)
{
    int pos=m+n-1;
    m--;n--;
    while(m>=0&&n>=0)
    {
        if(nums1[m]>nums2[n])
        {
            nums1[pos--]=nums1[m--];
        }else
        {
            nums1[pos--]=nums2[n--];
        }
    }
    while(m>=0)
    {
        nums1[pos--]=nums1[m--];
    }
    while(n>=0)
    {
        nums1[pos--]=nums2[n--];
    }
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<int> nums1(m+n),nums2(n);
        int temp;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            nums1[i]=temp;
        }
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            nums2[j]=temp;
        }
        mergeTwoArray(nums1,m,nums2,n);
        for(auto i:nums1)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}