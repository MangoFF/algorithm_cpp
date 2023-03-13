#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
//安排活动，贪心算法
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> activities(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        string votes;
        cin>>votes;
        for(char c:votes)
        {
            activities[i][c-'A']=1;
        }
    }
    vector<int> limits(3),costs(3);
    for(int i=0;i<3;i++)
    {
        cin>>limits[i]>>costs[i];
    }
    int max_people=min(limits[0],n);
    int min_cost=-1;
    for(int a=0;a<=max_people;a++)
    {
        int max_b=min(limits[1],n-a);
        for(int b=0;b<=max_b;b++)
        {
            int c=n-a-b;
            if(c>limits[2])
            {
                continue;
            }
            int total_cost=0;
            for(int i=0;i<3;i++)
            {
                total_cost+=a*activities[i][0]*costs[i];
                total_cost+=b*activities[i][1]*costs[i];
                total_cost+=c*activities[i][2]*costs[i];
            }
            if(min_cost==-1||total_cost<min_cost)
            {
                min_cost=total_cost;
            }
        }
    }
    if(min_cost==-1)
    {
        cout<<"NO"<<endl;
        int max_possiPeople=min(limits[0],n)+min(limits[1],n)+min(limits[2],n);
        cout << max_possible_people << endl;
    }else
    {
        cout<<"YES"<<endl;
        cout<<min_cost<<endl;
    }
    return 0;
}