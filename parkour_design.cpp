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

const int dx[3] = {2, 3, 4},
          dy[3] = {1, 0, -1};

/*------------------------Solve-----------------------------*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T;
  cin>>T;
  while(T--){
   	ll x,y; cin>>x>>y;
    // using pi=pair<int,int>;
    // queue<pi>q;
    // q.push({0,0});
    
    // set<pi> visited;
    // visited.insert({0,0});

    // bool loopbreak=false;
    // while(!q.empty() && !h and !loopbreak){
    // 	int size = q.size(); 
    // 	for(int i=0;i<size;i++){
    // 		int qx=q.front().first;
    // 		int qy=q.front().second;
    // 		q.pop();

    // 		for(int j=0;j<3;j++){
    // 			int nx = qx+dx[j];
    // 			int ny = qy+dy[j];
    			
    // 			if(nx==x && ny==y){
    // 			    h=1;
    // 			    break;
    // 			}

    // 			if(nx>x){
    // 				loopbreak=true;
    // 			}
    			
    // 			if(visited.find({nx, ny}) == visited.end()){
    // 			    q.push({nx, ny});
    // 			    visited.insert({nx, ny});
    // 			}
    // 		}
    // 		if(h or !loopbreak) break;
    // 	}
    // }
    // print(h);
	long long d = x - 2 * y;
        
    if (d < 0 || d % 3 != 0) print(0);
    else if (y < 0 && x + 4 * y < 0) print(0);
    else print(1);
    
  }
  return 0;
}

/*
Problem: https://codeforces.com/contest/2202/problem/A
*/