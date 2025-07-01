#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	 int n,s,r;
	 cin>>n>>s>>r;
	 
	 cout<<s-r<<" ";
	 n--;
	while(r!=0){
	 	int l=r/n;
	 	cout<<l<<" ";
	 	r-=l;
	 	n--;
	 }
	}
  return 0;
}
