#include<bits/stdc++.h>
using namespace std;
using pI=pair<int,int>;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		
		vector<int>a(n);
		for(auto &i:a)
		cin>>i;
		
		int lo,hi;
		if(n&1){
			lo=n/2;
			hi=n/2+2;
		}
		else{
			lo=n/2;
			hi=n/2+1;
		}
		
		vector<int>dp(n+1);
		int h=0;
		for(int i=0;i<n;i++)
		dp[a[i]]=i;
		
		while(lo>=1){
			if(dp[lo]<dp[lo+1] && dp[hi]>dp[hi-1])
			lo--,hi++,h++;
			else
			break;
		}
		cout<<n/2-h<<endl;
	}
  return 0;
}
