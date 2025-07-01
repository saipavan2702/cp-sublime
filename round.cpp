#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;

    int ret=0;
    for(int i=1;i<s.size();i++)
    ret+=9;

    ret+=s[0]-'0';

    cout<<ret<<endl;
  }
return 0;
}