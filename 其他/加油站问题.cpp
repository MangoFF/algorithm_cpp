#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int start = 0, cur = 0, sum = 0, total = 0;
    for (int i = 0; i < n; i++) {
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        //这个结论是需要一定证明的，但是可以感受到
        if (sum < 0) {
            start = i + 1;
            cur = i + 1;
            sum = 0;
        }
    }
    return total < 0 ? -1 : start;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> gas(n),cost(n);
        for(int i=0;i<n;i++)
        {
            cin>>gas[i];
        }
        for(int j=0;j<n;j++)
        {
            cin>>cost[j];
        }
       cout<<canCompleteCircuit(gas,cost)<<endl;
    }
}