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
  int T;
  cin>>T;
  while(T--){
    int n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    
    bool h=0;
    map<char,int>lo;
    map<char,int>up;
    
    for(auto&x:s) {
    	if(islower(x))
    	lo[x]++;
    	else
    	up[x]++;
	}
	
	ll cnt=0;
	for(auto& [x,y]:lo) {
		int curr=0;
		curr=min(y,up[toupper(x)]);
		
		cnt+=curr;
		
		lo[x]-=curr;
		up[toupper(x)]-=curr;
	}
		
	for(auto& [x,y]:lo){
		
		if(k==0)
		break;
		
		while(y>=2 && k>0) {
			cnt++;
			y-=2;
			k--;
		}
		
	}
	
	for(auto& [x,y]:up){
		int loy=lo[tolower(x)];
		
		if(k==0)
		break;
		
		while(loy>=2 && k>0){
			cnt++;
			loy-=2;
			k--;
		}
		
		if(k==0)
	    break;
		
		while(y>=2 && k>0) {
			cnt++;
			y-=(2);
			k--;
		}
	}
	cout<<cnt<<endl;
  }
  return 0;
}
