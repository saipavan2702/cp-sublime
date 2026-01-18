
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

long long solve(string dna) {
    int n = dna.length();
    vector<long long> total1(26, 0); 
    vector<int> bit(26, 0);
    int parity = 0;
    long long p1 = 0, p0 = 1;    
    
    for (int i = 0; i < n; i++) {
        int c = dna[i] - 'a';
        // flip bit[c]
        if (bit[c] == 1) {
            bit[c] = 0;
            parity ^= 1;
        } else {
            bit[c] = 1;
            parity ^= 1;
        }
        
        // add current prefix's bits to total1
        for (int j = 0; j < 26; j++) {
            total1[j] += bit[j];
        }
        
        if (parity == 1) p1++;
        else p0++;
    }
    
    // include empty prefix in parity counts? Already p0=1 at start covers empty prefix.
    long long sum_odd = 0;
    for (int j = 0; j < 26; j++) {
        long long cnt0 = (n+1) - total1[j];
        sum_odd += total1[j] * cnt0;
    }
    
    long long sum_odd_mod2 = p1 * p0;
    
    long long ans = (sum_odd - sum_odd_mod2) / 2;
    return ans;
}

/*------------------------Solve-----------------------------*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
  }
  return 0;
}

/*
Problem:
*/