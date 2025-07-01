#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		using pI=pair<int,int>;
		using ll=long long;
		
		int key=0;
		vector<pI>p;
		ll cnt=0;
		for(ll i=2;i*i<=n;i++){
			if(n%i==0){
				cnt=0;
				while(n%i==0){
					cnt++;
					n/=i;
				}
				p.push_back({i,cnt});
			}
		}
		if(n>1)
		p.push_back({n,1});
		
		ll ans=0;
		
		for(auto x:p)
		key=max(x.second,key);
		
		for(int i=1;i<=key;i++){
			ll a=1;
			for(auto x:p){
				if(x.second>=i)
				a*=x.first;
			}
			ans+=a;
		}
		cout<<ans<<endl;
	}
  return 0;
}
