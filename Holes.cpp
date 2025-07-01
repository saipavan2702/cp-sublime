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
      /_____::____     ::    .     ::    .     ::   _____._::____\
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


bool test(int u, vi&a, int n){
	int cnt=1,curr=0;
	for(int i=0;i<a.size();){
		if(curr+a[i]>u)
		curr=0,cnt++;
		else{
			curr+=a[i++];
		}
	}
	return cnt<=n;
}

/*------------------------Solve-----------------------------*/
int main(){
    int n,p;
    cin>>n>>p;
    
    vi a(p);
    for(int &i:a)
    cin>>i;
    
    int s=accumulate(a.begin(),a.end(),0);
    int f=*max_element(all(a));
    int lo=f,hi=s;
    int ans=INT_MAX;
    
    while(lo<=hi){
    	int u=(lo+hi)/2;
    	if(test(u,a,n))
    	ans=min(ans,hi),hi=u-1;
    	else
    	lo=u+1;
	}
	cout<<ans<<endl;
  return 0;
}