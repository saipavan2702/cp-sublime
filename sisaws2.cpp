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
    int n,k;
    cin>>n>>k;

    vi cap(n);

    for(int &i:cap){
    	cin>>i;
    }

    sort(rbegin(cap),rend(cap));
    using Tuple = tuple<long, int, int>; 
    priority_queue<Tuple> pq;
    // unordered_set<long long> vis;
    
    // pq.push({cap[0] + cap[0], 0, 0});
    // vis.insert(0);
    
    // long long total = 0;
    // while (k-- && !pq.empty()) {
    //     auto [sum, i, j] = pq.top();
    //     pq.pop();
    //     total += sum;
        
    //     if (i + 1 < n) {
    //         long long key1 = (long long)(i + 1) * n + j;
    //         if (!vis.count(key1)) {
    //             vis.insert(key1);
    //             pq.push({cap[i + 1] + cap[j], i + 1, j});
    //         }
    //     }
    //     if (j + 1 < n) {
    //         long long key2 = (long long)i * n + (j + 1);
    //         if (!vis.count(key2)) {
    //             vis.insert(key2);
    //             pq.push({cap[i] + cap[j + 1], i, j + 1});
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++) {
        pq.push({cap[i] + cap[0], i, 0});
    }
    
    long total = 0;
    while (k-- && !pq.empty()) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        total += sum;
        if (j + 1 < n) {
            pq.push({cap[i] + cap[j + 1], i, j + 1});
        }
    }
    
    cout<<total<<endl;

  }
  return 0;
}

/*
Problem:This is to maxiimse the bandwidth efficiency by chosing max badwidth rate index, and pairs can be (i,i),(i,j),(j,i),(j,j)
TCs:
input
2
3 4
5 3 6
5 6
4 3 7 3 6

output
44
74

*/