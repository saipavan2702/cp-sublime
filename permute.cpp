#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
   
        cout<<1<<" ";
        cout<<n<<" ";
        for(int i=0;i<n-2;i++)
        cout<<i+2<<" ";
    }
return 0;
}