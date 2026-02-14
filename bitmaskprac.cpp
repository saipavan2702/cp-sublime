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


// Brute Force
// void recur(int i, int curr, vector<bool>&vis, vector<vector<int>>grid){
// 	int n=grid.size();
// 	if(i==n){
// 		ans=min(ans,curr);return;
// 	}

	
// 	for(int j=0;j<n;j++){
// 		if(!vis[j]){
// 			vis[j]=true;
// 			recur(i+1,curr+grid[i][j],vis,grid);
// 			vis[j]=false;
// 		}
// 	}
// }


/*------------------------Solve-----------------------------*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>grid[i][j];
    	}
    }

    vector<vector<int>>dp(n,vector<int>(1<<n,-1));
    function<int(int,int)>recur=[&](int i, int mask) -> int {
    	if(i==n) return 0;
    	if(dp[i][mask] != -1) return dp[i][mask];

    	int ans=INT_MAX;
    	for(int j=0;j<n;j++){
    		if(!(mask & (1<<j))){
    			mask |=(1<<j);
    			ans=min(ans,grid[i][j]+recur(i+1,mask));
    			mask &= ~(1<<j);
    		}
    	}
    	return dp[i][mask]=ans;
    };
    cout<<recur(0,0)<<endl;
  }
  return 0;
}

/*
Problem: https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit?tab=t.0#
*/