
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
    ll s,k,n;
    cin>>s>>k>>n;

    ll p=n%k,q=n/k;
    if (s <= k) {
        // CASE 1: Small hourglass
        // It resets every k minutes
        long long time_in_cycle = n % k;
        
        if (time_in_cycle == 0) {
            // Exactly at flip time, it is fully reset
            cout << s << endl;
        } else {
            // Check if sand ran out
            long long remaining = s - time_in_cycle;
            if (remaining < 0) remaining = 0;
            cout << remaining << endl;
        }
    } 
    else {
        // CASE 2: Large hourglass (s > k)
        // The cycle repeats every 2*k minutes
        long long time_in_cycle = n % (2 * k);
 
        if (time_in_cycle < k) {
            // Phase 1: We are draining the large pile 's'
            cout << (s - time_in_cycle) << endl;
        } else {
            // Phase 2: We flipped the 'k' amount back to top
            // Remaining = Initial_K - (Time_Elapsed_Since_K)
            // Remaining = k - (time_in_cycle - k)
            // Remaining = 2*k - time_in_cycle
            cout << (2 * k - time_in_cycle) << endl;
        }
    }
    
  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2184/problem/B
*/