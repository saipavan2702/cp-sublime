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

#define pb push_back
#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

using ll = long long;
using pI = pair<int,int>;
using pL = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpI = vector<pI>;
using vpL = vector<pL>;

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




/*------------------------power of 2 numbers with MOD-----------------------*/
int powerMOD(int a, int b, int MOD) {
    int res = 1;
    while(b>0){
        if(b&1)
        res=(res*a)%MOD;

        a=(a*a)%MOD;
        b=b>>1;
    }
    return res%MOD;
}



int recur(int x){

}


/*------------------------Solve-----------------------------*/
void solve(){
	int t,p;cin>>t>>p;
	priority_queue<int>pq;

	while(t--){
		int z;cin>>z;
		if(z==1){
			int x,y;cin>>x>>y;
			int req=(x*x)+(y*y);
			pq.push(req);

			while(pq.size()>p){
				pq.pop();
			}
		}else if(z==2){
			cout<<pq.top()<<endl;
		}
	}
    return;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
