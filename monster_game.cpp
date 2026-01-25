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
    ll n;cin>>n;

    vl a(n),b(n);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;

    vector<pair<int, int>> swords;
    for (int i = 0; i < n; i++) {
        swords.emplace_back(a[i], b[i]);
    }
    
    // Sort by strength descending
    sort(swords.begin(), swords.end(), greater<pair<int, int>>());
    
    // Prefix sum of strikes needed
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + b[i];
    }
    
    ll ans = 0;
    
    // Try each possible number of strongest swords
    for (int k = 1; k <= n; k++) {
        // k strongest swords are available
        // Difficulty x = strength of k-th strongest sword
        
        // Check how many levels we can complete with k swords
        // We need to complete levels in order
        // This is equivalent to: find max L such that sum of smallest L b-values ≤ k
        
        // But we need the b-values of the actual levels, not swords
        
        // Actually, we should think differently
        
        // We have k swords, each gives 1 strike
        // We need b[0] strikes for level 1, b[1] for level 2, etc.
        // We complete levels in order until we run out of strikes
        
        // So we need to find max L such that prefix[L] ≤ k
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (prefix[mid] <= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        ll levels = lo;
        ll x = swords[k - 1].first;
        ans = max(ans, x * levels);
    }
    cout << ans << endl;
  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2193/problem/D
*/