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

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n+1);
        map<int,vector<int>>tree;
        vector<int>deg(n+1);

        for(int i=2;i<=n;i++){
            int p; cin>>p;
            tree[p].push_back(i);
            tree[i].push_back(p);
            deg[p]++;
            deg[i]++;
        }

        bool h=true;
        for(int i=1;i<=n;i++){
            if(deg[i]%2==0) {
                cout<<-1<<endl;
                h=false;
                break;
            }
        }

        if(h){
            vector<int>col(n+1);
            int ct=1;
            function<int(int,int)>dfs = [&](int u, int p)->int{
                vector<int>node;
                for(int &i:tree[u]) if(i != p){
                    int t=dfs(i,u);
                    if(t) node.push_back(t);
                }

                while(node.size()>=2){
                    int a=node.back();node.pop_back();
                    int b=node.back();node.pop_back();
                    col[a]=col[b]=ct++;
                }

                if(node.size()==1){
                    int t=node.back();
                    col[t]=col[u]=ct++;
                    return 0;
                }else return (p == 0? 0:u);
            };
            dfs(1,0);

            for(int i=1;i<=n;i++) cout<<col[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}

/*
Problem: https://www.codechef.com/problems/TREECOLOUREZ
*/
