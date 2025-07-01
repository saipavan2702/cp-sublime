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
#define MOD 1e9+7
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
  
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    
    vi a(n);
    for(int &i:a)
    cin>>i;
    
    vi b(n);
    for(int &i:b)
    cin>>i;
    
    unordered_map<int,ll>freq,dict;

	for(int i=0;i<n;i++){
		ll cnt=1;
		while(i+1<n && a[i]==a[i+1])
		i++,cnt++;
		
		freq[a[i]]=max(freq[a[i]],cnt);
	}
	
	for(int i=0;i<n;i++){
		ll cnt=1;
		while(i+1<n && b[i]==b[i+1])
		i++,cnt++;
		
		dict[b[i]]=max(dict[b[i]],cnt);
	}
		
	ll ans=1;
    for(auto [x,y]:freq){
    	ans=max(ans,y+dict[x]);
	}
	
	for(auto [x,y]:dict){
    	ans=max(ans,y+freq[x]);
	}
	cout<<ans<<endl;
  }
  return 0;
}
