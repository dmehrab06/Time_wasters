/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree<
PII,
null_type,
greater<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

LLI ai[100005];
LLI mai[100005];
LLI bi[100005];
LLI mbi[100005];

LLI binsearch(LLI mxmana, int k){
    if(mxmana>=mbi[k]){
        return bi[k];
    }
    else if(mxmana<mbi[1]){
        return 0;
    }
    int l=1;
    int h=k;
    while(true){
        int md=(l+h)/2;
        if(mxmana>=mbi[md]){
            if((md+1)<=k && mbi[md+1]<=mxmana){
                l=md+1;
            }
            else{
                return bi[md];
            }
        }
        else{
            h=md;
        }
    }
    return -1;
}
vector<string>all;
LLI xs[500006];
LLI ys[500006];

//1 rook
//2 bishop
//3 queen

int gh(char c){
    if(c=='R')return 1;
    if(c=='B')return 2;
    if(c=='Q')return 3;
}

int main(){
    int n;
    cin>>n;
    LLI kx,ky;
    cin>>kx>>ky;
    vector<PLLI>dis1a;
    vector<PLLI>dis1b;
    vector<PLLI>dis2a;
    vector<PLLI>dis2b;
    vector<PLLI>dis3a;
    vector<PLLI>dis3b;
    vector<PLLI>dis4a;
    vector<PLLI>dis4b;
    FREP(i,1,n){
        string ghuti;
        LLI x,y;
        cin>>ghuti>>x>>y;
        all.PB(ghuti);
        xs[i-1]=x;
        ys[i-1]=y;
    }
    int flag=0;
    //checking in vertical line
    FREP(i,0,(n-1)){
        if(ys[i]==ky){
            LLI ghut=gh(all[i][0]);
            LLI dis=abs(xs[i]-kx);
            if(xs[i]>kx){
                dis1a.PB(make_pair(dis,ghut));
            }
            else{
                dis1b.PB(make_pair(dis,ghut));
            }
        }
    }
    SORTV(dis1a);
    SORTV(dis1b);
    int l1a=dis1a.size();
    int l1b=dis1b.size();
    if(l1a>0){
        if(dis1a[0].second%2)flag=1;
    }
    if(l1b>0){
        if(dis1b[0].second%2)flag=1;
    }
    //vertical sesh
    FREP(i,0,(n-1)){
        if(xs[i]==kx){
            LLI ghut=gh(all[i][0]);
            LLI dis=abs(ys[i]-ky);
            if(ys[i]>ky){
                dis2a.PB(make_pair(dis,ghut));
            }
            else{
                dis2b.PB(make_pair(dis,ghut));
            }
        }
    }
    SORTV(dis2a);
    SORTV(dis2b);
    int l2a=dis2a.size();
    int l2b=dis2b.size();
    if(l2a>0){
        if(dis2a[0].second%2)flag=1;
    }
    if(l2b>0){
        if(dis2b[0].second%2)flag=1;
    }
    //horizontal sesh
    FREP(i,0,(n-1)){
        if(xs[i]>kx && (abs(xs[i]-kx)==abs(ys[i]-ky))){
            LLI ghut=gh(all[i][0]);
            LLI dis=(xs[i]-kx)*(xs[i]-kx)+(ys[i]-ky)*(ys[i]-ky);
            if(ys[i]>ky){
                dis3a.PB(make_pair(dis,ghut));
            }
            else{
                dis3b.PB(make_pair(dis,ghut));
            }
        }
        else if(xs[i]<kx && (abs(xs[i]-kx)==abs(ys[i]-ky))){
            LLI ghut=gh(all[i][0]);
            LLI dis=(xs[i]-kx)*(xs[i]-kx)+(ys[i]-ky)*(ys[i]-ky);
            if(ys[i]>ky){
                dis4a.PB(make_pair(dis,ghut));
            }
            else{
                dis4b.PB(make_pair(dis,ghut));
            }
        }
    }
    SORTV(dis3a);
    SORTV(dis3b);
    SORTV(dis4a);
    SORTV(dis4b);
    int l3a=dis3a.size();
    int l3b=dis3b.size();
    int l4a=dis4a.size();
    int l4b=dis4b.size();
    if(l3a>0){
        if(dis3a[0].second!=1)flag=1;
    }
    if(l3b>0){
        if(dis3b[0].second!=1)flag=1;
    }
    if(l4a>0){
        if(dis4a[0].second!=1)flag=1;
    }
    if(l4b>0){
        if(dis4b[0].second!=1)flag=1;
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
