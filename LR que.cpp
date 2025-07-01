#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  
  while(t--) {
  	int n;
  	string s;
  	
  	cin>>n;
  	cin>>s;
  	
  	int l=0,r=n-1;
  	int pre=-1;
  	for(int i=1;i<n;i++){
  		if(s[i]=='L' and s[i-1]=='R')
  		{pre=0;break;}
	}
	if(pre==-1){
		for(int i=1;i<n;i++){
			if(s[i]=='R' && s[i-1]=='L')
			pre=i;
		}
	}
	cout<<pre<<endl;
  }
  return 0;
}
