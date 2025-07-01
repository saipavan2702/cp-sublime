#include<bits/stdc++.h>
using namespace std;
using pI=pair<int,int>;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		
		long long y=n/2;
		if(n&1){
			
			if((y+1)%10==0) {
				
				long long u=n;
				int len=0;
				while(u!=0){
					u/=10;
					len++;
				}
				len--;
				long long k=pow(10,len);
				if(n/k!=2 && len>1) {
					
					long long  x=(n+1)/2;
				    long long  r=n%10;
				    r/=2;
				    
					long long f=k/2;
					cout<<x+r+f<<" "<<n-x-r-f<<endl;
				}
				else{
				  long long  x=(n+1)/2;
				  long long  r=n%10;
				  r/=2;
				  cout<<x+r<<" "<<n-x-r<<endl;	
				}
				
			}
			else
			cout<<y<<" "<<y+1<<endl;
			
		}
		else{
			cout<<y<<" "<<y<<endl;
		}
	}
  return 0;
}
