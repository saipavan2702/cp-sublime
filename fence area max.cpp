/*
 " I AM VENGEANCE , I AM THE KNIGHT , I AM THE BATMAN ! "
____ __ __ __ __ __ ___                             ___ __ __ __ __ __ ____
 `-._:  .:'   `:::  .:\           |\__/|           /::  .:'   `:::  .:.-'
     \      :          \          |:   |          /         :       /
      \     ::    .     `-_______/ ::   \_______-'   .      ::   . /
       |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|
       |     ;::         ;::         ;::         ;::         ;::  |
       |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|
       /     :           :           :           :           :    \
      /______::_____     ::    .     ::    .     ::   _____._::____\
                    `----._:: ::'  :   :: ::'  _.----'
                           `--.       ;::  .--'
                               `-. .:'  .-'
                                  \    /
                                   \  /
                                    \/
*/
 
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
#define pb push_back
#define f first
#define s second
using pI=pair<int,int>;
using vi=vector<int>;
 
 
 
/*--------------------No.of digits------------------*/
int cntDig(int n) {
	if(n==0)
	return 1;
 
	return floor(log10(n)+1);
}
 
 
 
/*------------------isPrime--------------*/
int isPrime(int n) {
    bool h=0;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) {
            h=1;
        }
    }
    return h==0;
}
 
 
 
/*-----------------------check palindrome---------------------------*/
bool check(string s) {
	int n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1])
		return 0;
	}
	return 1;
}
 
 
 
/*------------------------print "Yes/No"-------------------*/
void print(bool h){
	if(h)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
 
 
 
/*------------------------Solve-----------------------------*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
	  int n;
	  cin>>n;
	  
	  vector<ll>a(n);
	  for(auto &i:a)
	  cin>>i;
	  
	  stack<pair<int,ll>>st;
	  vector<ll>ans(n);
	  
	  for(int i=0;i<n;i++){
	  	ll span=1;
	  	while(!st.empty() && st.top().f>=a[i] ){
	  		span+=st.top().s;
			st.pop();
		}
		st.push({a[i],span});
		ans[i]+=span*a[i];
	  }
	  
	  while(!st.empty())
	  st.pop();
	  
	  for(int i=n-1;i>=0;i--){
	  	ll span=1;
	  	while(!st.empty() && st.top().f>=a[i]){
	  		span+=st.top().s;
	  		st.pop();
		}
		st.push({a[i],span});
		ans[i]+=(span-1)*a[i];
	  }
	  
	  cout<<*max_element(ans.begin(),ans.end())<<endl;
  
  return 0;
}