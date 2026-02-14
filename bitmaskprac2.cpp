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

#include <bits/stdc++.h>
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

const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

/*--------------------No.of digits------------------*/
int cntDig(int n) {
  if (n == 0)
    return 1;

  return floor(log10(n) + 1);
}

/*------------------isPrime--------------*/
int isPrime(int n) {
  bool h = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      h = 1;
    }
  }
  return h == 0;
}

/*-----------------------check palindrome---------------------------*/
bool check(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1])
      return 0;
  }
  return 1;
}

/*------------------------print "Yes/No"-------------------*/
void print(bool h) {
  if (h)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

/*------------------------Solve-----------------------------*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {

    vector<vector<int>> graph = {{1, 2, 3}, {2, 0}, {0, 1}, {0, 4}, {3}};
    // This needs bfs as we need to go thorugh visited nodes too, via dfs we
    // cannot do that as it will create a infinite cycle.
    //  int n=graph.size();
    //  vector<vector<int>>dp(n,vector<int>(1<<n,-1));
    //  function<int(int,int)>recur=[&](int i, int mask) -> int {
    //  	if (mask == (1 << n) - 1) return 0;
    //  	if(dp[i][mask]!=-1) return dp[i][mask];

    // 	int ans=INT_MAX;
    // 	for(auto x:graph[i]){
    // 		int newMask = mask | (1 << x);
    // 		ans=min(ans,1+recur(x,newMask));
    // 	}
    // 	return dp[i][mask]=ans;
    // };
    // cout<<recur(0,1)<<endl;
    using pI = pair<int, int>;
    queue<pI> q;
    vector<vector<bool>> vis(n, vector<bool>(1 << n));

    for (int i = 0; i < n; i++)
      q.push({i, 1 << i});
    int ans = 0;
    while (!q.empty()) {
      for (int i = 0; i < q.size(); i++) {
        int u = q.front().first;
        int mask = q.front().second;
        q.pop();
        if (mask == (1 << n - 1)) {
          return ans;
        }
        for (auto x : graph[u]) {
          int newMask = mask | (1 << x);
          if (!vis[x][newMask]) {
            q.push({x, newMask});
            vis[x][newMask] = true;
          }
        }
      }
      ans++;
    }
  }
  return 0;
}

/*
Problem:
https://www.geeksforgeeks.org/dsa/minimum-time-to-visit-all-nodes-of-given-graph-at-least-once/
*/
