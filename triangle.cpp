#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int x[3],y[3];
        for(int i=0;i<3;i++)
        cin>>x[i]>>y[i];

        int cnt=0;
        if(x[0]==x[1] or x[1]==x[2] or x[0]==x[2])
        cnt++;
        if(y[0]==y[1] or y[1]==y[2] or y[0]==y[2])
        cnt++;

        if(cnt==2)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;

    }
return 0;
}
