#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		string s;
		cin>>s;
		
		unordered_set<char>st;
		vector<int>pref(n),suf(n);
		for(int i=0;i<n;i++) {
			st.insert(s[i]);
			pref[i]=st.size();
		}
		st.clear();
		for(int i=n-1;i>=0;i--){
			st.insert(s[i]);
			suf[i]=st.size();
		}
		int res=INT_MIN;
		for(int i=0;i<n-1;i++){
			res=max(res,pref[i]+suf[i+1]);
		}
		cout<<res<<endl;
	}
  return 0;
}
