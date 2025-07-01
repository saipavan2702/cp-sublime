#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	
		vector<int>a(n);
		for(auto &i:a)
		cin>>i;
		
		int s=accumulate(a.begin(),a.end(),0);
		int y=0;
		bool f=0;
		for(int i=0;i<n-1;i++) { 
			if(a[i]==-1 and a[i+1]==-1){
				y=s+4,f=1;
			    break;
			}
		}
		if(f)
		cout<<y<<endl;
		else{
			int cnt=count(a.begin(),a.end(),-1);
			if(cnt==0)
			cout<<s-4<<endl;
			else 
			cout<<s<<endl;
		}
	}
  return 0;
}
