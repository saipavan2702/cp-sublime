#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int a[2][2];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0;
         for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(a[i][j]==1)
                cnt++;
            }
        }
        if(cnt==0)
        cout<<0<<endl;
        else if(cnt==2 or cnt==1 or cnt==3)
        cout<<1<<endl;
        else if(cnt==4)
        cout<<2<<endl;
    }
}
