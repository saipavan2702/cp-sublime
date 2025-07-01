#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  using ll=long long;
  while(t--){
  	int n,x;
  	cin>>n>>x;
  	
  	vector<ll>a(n),pref(n);
  	for(int i=0;i<n;i++)
  	cin>>a[i];
  	
  	pref[0]=a[0];
  	for(int i=1;i<n;i++) {
  	  pref[i]=pref[i-1]+a[i];
	}
    priority_queue<ll>pq;
    priority_queue<ll,vector<ll>,greater<ll>>rq;
    
    ll cnt=0;
    ll lo=pref[x-1];
    for(int i=x-1;i>=0;i--){
    	while(pref[i]<lo) {
    		ll u=pq.top();
    		pq.pop();
    		lo-=2*u;
    		cnt++;
		}
		pq.push(a[i]);
	}
	//1 2 3 4
	//1 3 6 10
	//lo=6
	//3,2
	//6-6=0
	//
	lo=pref[x-1];
    for(int i=x;i<n;i++){
    	rq.push(a[i]);
    	
    	while(pref[i]<lo){
    		ll u=rq.top();
    		rq.pop();
    		lo+=2*u;
    		cnt++;
		}
	}
	
  	cout<<cnt<<endl;
  	
  }
  return 0;
}
