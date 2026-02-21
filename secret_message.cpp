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
  
  int T;
  cin>>T;
  while(T--){
    int n,k;cin>>n>>k;
    vector<string>enc(k);
    for(auto &x:enc) cin>>x;

    vector<int>mask(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) mask[i] |= (1<<(enc[j][i]-'a'));
    }
    
    for(int d=1;d<=n;d++){
        if(n%d!=0) continue;
        string pat="";

        bool pos=true;
        for(int r=0;r<d;r++) {
            int common=(1<<26)-1;
            for(int x=r;x<n;x+=d) {
                common &= mask[x];
                if(common==0){
                    pos=false;
                    break;
                }
            }

            if(common==0) {
                pos=false;
                break;
            }
            
            int cidx=0;
            while(!((common >> cidx) & 1)) cidx++;
            pat+=(char)('a'+cidx);
        }

        if(pos){
            string ans="";
            for(int i=0;i<(n/d);i++) ans+=pat;
            cout<<ans<<endl;
            break;
        }
    }
  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2194/problem/C
*/