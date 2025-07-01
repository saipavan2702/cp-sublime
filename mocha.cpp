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

int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    
    vector<int>a(n);
    for(int &i:a)
    cin>>i;
    
    bool h=0;
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		int g=__gcd(a[i],a[j]);
    		if(g<=2)
    		h=1;
		}
	}
	if(h)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;


  }
  return 0;
}
