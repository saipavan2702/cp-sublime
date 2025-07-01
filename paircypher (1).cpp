#include <bits/stdc++.h>
using namespace std;
int main() {
    //cout<<"Hello World!";
     int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char,int>freq;
        for(auto x:s)
        {
            freq[x]++;
        }
        int sum=0;
       for(auto x:freq)
       {
           sum+=x.second+1;
       }
       cout<<sum<<endl;
        
    }
}
