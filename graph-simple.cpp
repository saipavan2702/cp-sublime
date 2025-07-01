#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		vector<int>c(n+1);
		for(int i=1;i<=n;i++)
		cin>>c[i];
		
		vector<int>adj[n+1];
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		int r=n;
		vector<int>h(n+1,n);
		auto recur=[&](int i){
			queue<int>q;
			q.push(i);
			h[i]=0;
			while(!q.empty()) {
				int v=q.front();
				q.pop();
				
				if(h[v]>=r)
				continue;
				
				for(auto u:adj[v]) {
					if(h[u]>h[v]+1){
						h[u]=h[v]+1;
						q.push(u);
					}
				}
			}
		};
		recur(c[1]);

		for(int i=2;i<=n;i++) {
			r=min(r,h[c[i]]);
			recur(c[i]);
			cout<<r<<" ";
		}
		cout<<endl;
	}
  return 0;
}
