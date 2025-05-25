/*
Problem: https://www.codechef.com/problems/MRC
*/
#include<bits/stdc++.h>
using namespace std;


void print(bool h){
	if(h)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		string s;cin>>s;

		vector<int>v;
		int diff=1;
		for(int i=1;i<n;i++){ 
			if(s[i]==s[i-1]) diff++;
			else{
				v.push_back(diff);
				diff=1;
			}
		}
		v.push_back(diff);

		int cn=0;
		vector<int>ind;
		for (int i=0;i<size(v);i++){
			if(v[i]>=k) cn++, ind.push_back(i);
		}

		if(cn>2) print(0);
		else if(cn==0) print(1);
		else if(cn==2){
			if((ind[0]&1) == (ind[1]&1)) print(0);
			else if(v[ind[0]]<2*k-1 && v[ind[1]]<2*k-1) print(1);
			else print(0);
		}else{
			if(v[ind[0]]>2*k-2) {
				print(0);
				continue;
			}

			bool h=false;
            for(int i = (ind[0] + 1) % 2; i < v.size(); i += 2){
                if(v[i] > 1 || i == 0 || i == v.size()-1){
                    h=true;
                    break;
                }
            }

            for(int i = ind[0] % 2; i < v.size(); i += 2){
                if(v[ind[0]] + v[i] < 2LL * k - 1){
                    h=true;
                    break;
                }
            }
            print(h);
		}
	}
	return 0;
}

// 1 2 2 1