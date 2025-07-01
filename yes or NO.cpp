#include <bits/stdc++.h>
using namespace std;
int main() {
    //cout<<"Hello World!";
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if(s=="YES")
        {
            cout<<"YES"<<endl;
        }
        else
        cout<<"No"<<endl;
    }
}
