#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>a(2*n);
        for(int i=0;i<2*n;i++)
        {
            cin>>a[i];
        }
        int flag=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if((a[n+i]-a[i])<x)
            {
               flag=1;
               break;
            }
        }
        if(flag==1)
        cout<<"no"<<endl;
        else
        cout<<"yes"<<endl;
    }
}
