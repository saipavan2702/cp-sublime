#include<bits/stdc++.h>
using namespace std;
using pI=pair<int,int>;

int main(){
	int n,d;
	cin>>n>>d;
	
	vector<pI>a;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back({x,y});
	}
	sort(a.begin(),a.end());
	
	long long j=0,u=0,h=0;
	for(int i=0;i<n;i++){
		if(a[i].first-a[j].first<d){
			u+=a[i].second;
			h=max(h,u);
		}
		else
		u-=a[j].second,j++,i--;
	}
	cout<<h<<endl;
	
  return 0;
}
