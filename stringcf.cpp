#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        unordered_set<char>st;
        int n,cnt=0;
        n=s.size();
        for(int i=0;i<n;i++)
        {
            st.insert(s[i]);
            if(st.size()>3)
            {
                cnt++;
               st.clear();
            }
            st.insert(s[i]);
        }
        if(n-3*cnt==0)
        cout<<cnt<<endl;
        else
        cout<<cnt+1<<endl;
    }
   

}
