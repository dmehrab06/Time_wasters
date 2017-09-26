#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

long long int LCA(long long int u, long long int v){
    map<long long int,int>possible;
    while(v){
        possible[v]=1;
        v/=2;
    }
    while(u){
        if(possible.find(u)!=possible.end()){
            return u;
        }
        u/=2;
    }
    return -1;
}

map< pair<long long int,long long int> ,long long int >edgecost;
int main(){
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int type;
        scanf("%d",&type);
        if(type==1){
            long long int u,v,w;
            cin>>u>>v>>w;
            long long int lc=LCA(u,v);
            long long int pu=u/2;
            while(pu>=lc){
                pair<long long int,long long int>eg1=make_pair(u,pu);
                if(eg1.first!=eg1.second){
                    if(edgecost.find(eg1)==edgecost.end()){
                        edgecost[eg1]=w;
                    }
                    else{
                        edgecost[eg1]+=w;
                    }
                }
                else{
                    edgecost[eg1]=0;
                }
                u=pu;
                pu/=2;
            }
            long long int pv=v/2;
            while(pv>=lc){
                pair<long long int,long long int>eg2=make_pair(v,pv);
                if(eg2.first!=eg2.second){
                    if(edgecost.find(eg2)==edgecost.end()){
                        edgecost[eg2]=w;
                    }
                    else{
                        edgecost[eg2]+=w;
                    }
                }
                else{
                    edgecost[eg2]=0;
                }
                v=pv;
                pv/=2;
            }
        }
        else{
            long long int u,v;
            cin>>u>>v;
            long long int lc=LCA(u,v);
            //cout<<lc<<"\n";
            long long int cost=0;
            long long int pu=u/2;
            while(pu>=lc){
                pair<long long int,long long int>eg1=make_pair(u,pu);
                if(edgecost.find(eg1)!=edgecost.end()){
                    cost+=edgecost[eg1];
                }
                u=pu;
                pu/=2;
            }
            long long int pv=v/2;
            while(pv>=lc){
                pair<long long int,long long int>eg2=make_pair(v,pv);
                if(edgecost.find(eg2)!=edgecost.end()){
                    cost+=edgecost[eg2];
                }
                v=pv;
                pv/=2;
            }
            cout<<cost<<"\n";
        }
    }
    return 0;
}
