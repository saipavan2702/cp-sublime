#include<bits/stdc++.h>
using namespace std;
using pI=pair<int,int>;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		
		vector<int>a(n);
		long long int net=0,s=0,cnt=0;
		
		for(int i=0;i<n;i++)
		cin>>a[i];
	   
	    for(int i=0;i<n;i++){
	      s+=abs(a[i]);
		  if(a[i]<0)
		  net++;
		  
		  if(a[i]==0)
		  cnt++;
		}

		if(cnt>0)
		cout<<s<<endl;
		else {
			
			if(net%2==0)
			cout<<s<<endl;
			else {
				int q=INT_MAX;
				for(int i=0;i<n;i++) {
					q=min(q,abs(a[i]));
				}
				cout<<s-2*q<<endl;
			}    
		}
	}
  return 0;
}
