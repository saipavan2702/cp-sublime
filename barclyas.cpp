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



/*------------------------Solve-----------------------------*/
void solve(){
    int n,p;cin>>n>>p;
    vector<vector<int>>v(n,vector<int>(p));

    for(int i=0;i<n;i++){
    	for(int j=0;j<p;j++)cin>>v[i][j];
    }
    int k;cin>>k;

    vector<vector<int>>R(n,vector<int>(p,1));
    vector<vector<int>>C(n,vector<int>(p,1));
    vector<vector<int>>pref(n+1,vector<int>(p+1,1));

    for(int i=0;i<=n;i++) pref[i][0]=1;
    for(int j=0;j<=p;j++) pref[0][j]=1;

    for(int i=0;i<n;i++){
    	for(int j=0;j<p;j++){
    		R[i][j]*=v[i][j];
    	}
    }

    for(int i=0;i<p;i++){
    	for(int j=0;j<n;j++){
    		C[j][i]*=v[j][i];
    	}
    }

    int ans=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=p;j++){
    		pref[i][j]=v[i-1][j-1]*pref[i-1][j-1]*pref[i][j-1]/pref[i-1][j-1];
    		if(pref[i-1][j-1]==0){
    			pref[i][j]=v[i-1][j-1];
    		}
    		if(pref[i][j]<=k) ans++;
    	}
    }

    int cnt=0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<p;j++){
    		if(R[i][j]*C[i][j]<=k) cnt++;
    		else if(R[i][j]*v[i][j]<=k) cnt++;
    		else if(C[i][j]*v[i][j]<=k) cnt++;
    	}
    }
    cout<<cnt<<" "<<ans;

	



    cout<<endl;
    return;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
