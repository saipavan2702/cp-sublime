#include <bits/stdc++.h>
using namespace std;
int main() {
    //cout<<"Hello World!";
     int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<pair<int,string>>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p.at(i).first;
            cin>>p.at(i).second;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p.at(i).first;j++)
            {
                if(p.at(i).second[j]=='D')
                {
                    if(a[i]==9)
                    { a[i]=0;}
                    else
                    a[i]++;
                }
                else if(p.at(i).second[j]=='U')
                {
                    if(a[i]==0)
                    a[i]=9;
                    else
                    a[i]--;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
}
