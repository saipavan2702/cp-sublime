#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];

        cout<<(10-n)*(10-n-1)*3<<endl;
    }
return 0;
}