#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;

      int a[n+1];
      for(int i=1;i<=n;i++)
      cin>>a[i];

      int dp[n+1]={0};
      dp[0]=1;
      for(int i=1;i<=n;i++){
        if(i+a[i]<=n && dp[i-1])
        dp[i+a[i]]=1;

        if(i-a[i]-1>=0 && dp[i-a[i]-1])
        dp[i]=1;
      }
      if(dp[n])
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }
    
return 0;
}