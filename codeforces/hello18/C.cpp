/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI vals[43];
LLI twopows[43];

void calc(){
    twopows[0] = 1;
    FREP(i,1,40)twopows[i]=twopows[i-1]*2;
}

void dp(int n){
    FREP(i,2,n){
        int cnt = 2;
        RFREP(j,(i-1),1){
            vals[i] = min(vals[i],(vals[j]*cnt));
            cnt<<=1;
        }
    }
}

vector<LLI>anss;

int main(){
    int n,L;
    calc();
    scanf("%d %d",&n,&L);
    FREP(i,1,n){
        cin>>vals[i];
    }
    dp(n);
    //FREP(i,1,n){
      //  cout<<vals[i]<<" ";
    //}
    //cout<<"\n";
    LLI cost = 0;
    //LLI cost1 = 1000000000000000000;
    int it = n-1;
    //int ff = 1;
    while(it>=0){
        if(twopows[it]>L){
            anss.PB(cost+vals[it+1]);
        }
        if(twopows[it]<=L){
            LLI need = (L/twopows[it]);
            //ff = 0;
            cost+=(need*vals[it+1]);
            L-=(need*twopows[it]);
        }
        it--;
    }
    anss.PB(cost);
    SORTV(anss);
    cout<<anss[0]<<"\n";
    return 0;
}
