#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;

      int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];

      int sum=accumulate(a,a+n,0);
      if(!(sum&1))
      cout<<0<<endl;
      else
      {
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            if(a[i]&1)
            {
               while(a[i]&1)
               {
                a[i]/=2;
                cnt++;
               }
            }
            else
            {
                while(!(a[i]&1))
                {
                    a[i]/=2;
                    cnt++;
                }
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
      }
    }
return 0;
}