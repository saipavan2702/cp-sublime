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

#define ll long long
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
using pI=pair<int,int>;


bool check(string s) {
	int n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1])
		return 0;
	}
	return 1;
}


int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    
    if(check(s))
    cout<<"Yes"<<endl;
    else{
    	int inv=0;
    	for(int i=0;i<n/2;i++) {
    		
    		if(s[i]!=s[n-i-1] && !inv){
    			s[i]=(!(s[i]-'0'))+'0';
    			inv=!inv;
			}
			else if(s[i]!=s[n-i-1] && inv) {
				s[i]=(!(s[i]-'0'))+'0';
			}
			else if(inv && s[i]==s[n-i-1])
			break;
		}
		if(check(s))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
		
	}


  }
  return 0;
}
