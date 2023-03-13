#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    vector<int> prefix_sum(n);
    prefix_sum[0]=data[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+data[i];
    }
    vector<double> averages(n);
    for(int i=0;i<n;i++)
    {
        averages[i]=(double)prefix_sum[i]/(i+1);
        cout<<averages[i]<<" ";
    }
    cout<<endl;
    vector<int> sorted_data;
   
    vector<int> median(n);
    for(int i=0;i<n;i++)
    {
        //这里可以解决问题，但是显然这里时间复杂度越界了，可以用更好的方案，但是这里先不弄了
        sorted_data.push_back(data[i]);
        sort(sorted_data.begin(),sorted_data.end());
        if(i&2==0)
        {
            median[i]=sorted_data[i/2];
        }else
        {
            median[i]=sorted_data[i/2]+sorted_data[i/2+1];
            median[i]/=2;
        }
        cout<<median[i]<<' ';
    }
    cout<<endl;
    return 0;
}