#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    cout<<endl;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        unordered_map<int,vector<int>>freq;
        for(int i=0;i<n;i++)
        {
            freq[a[i]].push_back(i);
        }
        int l=0;
        for(int i=0;i<k;i++)
        {
            int p,q;
            cin>>p>>q;
            int l,r;
            if(freq[p].size()==0 or freq[q].size()==0)
            {
                cout<<"No"<<endl;
            }
            else
            {
            l=*freq[p].begin();
            r=freq[q].back();
            if(l<r)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
            }
            
        }
    }
}
