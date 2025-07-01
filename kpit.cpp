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



int findM(vector<int> arr){
	int s=INT_MAX;
	int idx=-1;
	for(int i=0;i<arr.size();i++){
		if(s>arr[i]){
			s=arr[i];
			idx=i;
		}
	}
	return idx;
}

/*------------------------Solve-----------------------------*/
void solve(){
    int n;cin>>n;
    vi v(n);
    for(int &i:v)cin>>i;

    
	// unordered_map<int, int> map;
    // map[0] = -1;
    // int len = 0;
    // int ending_index = -1;
 
    // int sum = 0;
 
    
    // for (int i = 0; i < n; i++)
    // {  
    //     sum += (nums[i] == 0)? -1 : 1;
    //     if (map.find(sum) != map.end())
    //     {
    //         if (len < i - map[sum])
    //         {
    //             len = i - map[sum];
    //             ending_index = i;
    //         }
    //     }
    //     else {
    //         map[sum] = i;
    //     }
    // }

    // int n;cin>>n;
	// vector<int>arr;
	// for(int i=0;i<n;i++)cin>>arr[i];

    // int maxLen = 0;
    // int i = 0;
    // int j = i + 1;
 
    
    // while (j < n) {
    //     if (arr[i] != arr[j]) {
    //         maxLen = max(maxLen, 2);
 
    //         int l = i - 1;
    //         int r = j + 1;
    //         while (l >= 0 && r < n && arr[l] == arr[i]
    //                && arr[r] == arr[j]) {
    //             l--;
    //             r++;
    //         }
    //         maxLen = max(maxLen, 2 * (r - j));
    //     }
    //     i++;
    //     j = i + 1;
    // }
 
    // cout<<maxLen<<endl;


	// string s;cin>>s;
	// stack<pair<char,int>>st;

	// int n=s.size();
	// for(int i=0;i<n;i++){
	// 	if(st.empty()) st.push({s[i],1});
	// 	else if(st.top().first==s[i]){
	// 		if(st.top().second==2) continue;
	// 		else{
	// 			st.pop();
	// 			st.push({s[i],2});
	// 		}
	// 	}else st.push({s[i],1});
	// }


	// string ans="";
	// while(!st.empty()){
	// 	auto x=st.top();
	// 	ans=string(x.second,x.first)+ans;
	// 	st.pop();
	// }

    // cout<<ans<<endl;
    return;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
