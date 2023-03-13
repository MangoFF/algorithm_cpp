#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        
        int e_num;
        cin>>e_num;
        vector<vector<int>> hp(n,vector<int>(e_num));
        for(int i=0;i<n;i++)
            for(int j=0;j<e_num;j++)
            {
                cin>>hp[i][j];
            }
        for(int i=0;i<n;i++)
        {
            
            //有限杀hp低的敌人
            sort(hp[i].begin(),hp[i].end());
            int shots=0;
            for(int j=0;j<e_num;j++)
            {
                if(j+1<n&&hp[i][j]==hp[i][j+1]&&hp[i][j]==1)
                {
                    shots++;
                    j++;
                }else
                {
                    shots++;
                }
            }
            cout<<shots<<endl;
        }
        
        

    }
}