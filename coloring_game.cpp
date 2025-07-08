
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

int find(vector<int>& a, int x)
{
    int n=a.size();
    int l = 0, r = n-1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] < x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    
    vi a(n);
    for(int &i:a)cin>>i;

    sort(all(a));
    ll ans=0;
    int Z=a[n-1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i] + a[j];
            int l = max(a[j], Z - sum + 1), r = min(sum - 1, Z);
            auto lidx = find(a, l), ridx = find(a, r + 1);
            lidx = max(lidx, j);
            if (lidx > ridx) continue;
            ans += ridx - lidx;
        }
    }

    cout<<ans<<endl;

  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2112/problem/C
*/