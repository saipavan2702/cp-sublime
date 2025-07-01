#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
       int n,cnt=0,val;
    cin>>n;
    val=n;
    while(val!=0)
    {
         val/=10;
         cnt++;
    }
    int k;
    k=pow(10,cnt-1);
    cout<<n-k<<endl;

    }
    
}
