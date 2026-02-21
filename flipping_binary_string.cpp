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

#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;

const int MOD=1000000007;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};


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
  
  int t;
  cin>>t;
  while(t--){
    ll n; cin>>n;
    string s; cin>>s;
    ll ocnt=count(s.begin(),s.end(),'1');
    if(ocnt==0) cout<<0<<endl;
    else{
    	if(ocnt%2==1 and n%2==0){
    		vi ops;
    		for(ll i=0;i<n;i++){
				if(s[i]=='0') ops.push_back(i+1);	
    		}
    		cout<<ops.size()<<endl;
    		for(auto x:ops) cout<<x<<" ";
    		cout<<endl;
    	}else if(ocnt%2==0){
    		vi ops;
    		for(ll i=0;i<n;i++){
				if(s[i]=='1') ops.push_back(i+1);	
    		}
    		cout<<ops.size()<<endl;
    		for(auto x:ops) cout<<x<<" ";
    		cout<<endl;
    	}else cout<<-1<<endl;
    }
  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2192/problem/B
*/