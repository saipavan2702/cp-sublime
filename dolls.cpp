#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		vector<int>a(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		map<int,int>freq;
		for(int i:a)
		freq[i]++;
		
		int u=0;
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			if(freq[a[i]]){
				int x=a[i];
				while(freq[x]){
					freq[x]--;
					x++;
				}
				u++;
			}
		}
		cout<<u<<endl;
	}
  return 0;
}
