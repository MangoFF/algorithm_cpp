#include <bits/stdc++.h>
using namespace std;
//我没能写出一个判断筛子种类的题目，这是我的问题，以后再写吧，我是傻子
void classify_f(vector<vector<int>> &nums,unordered_map<string,vector<int>> &classify)
{

}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> nums(n);
        for(int i=0;i<n;i++)
        {
            int temp;
            unordered_map<string,vector<int>> classify;
            for(int j=0;j<6;j++)
            {
                cin>>temp;
                nums[i].emplace_back(temp);
            }
            classify_f(nums,classify);
            cout<<classify.size()<<endl;
            for(auto &[key,num]:classify)
            {
                cout<<num.size()<<" ";
            }
            cout<<endl;
        }
       
    }
}