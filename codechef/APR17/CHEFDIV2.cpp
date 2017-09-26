/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000000
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< vector <LLI> >divisors;
vector< vector <LLI> >divisorsorted;
vector< vector <LLI> >cnt;
vector< vector <LLI> >mxchild;
vector< vector <LLI> >divcnt;
LLI mxx;
LLI mnn;

void init(){
    LLI tot=mxx-mnn+1;
    vector <LLI> line;
    //set<LLI>line2;
    FREP(i,1,(tot+2)){
        divisors.PB(line);
        divisorsorted.PB(line);
        cnt.PB(line);
        mxchild.PB(line);
        divcnt.PB(line);
    }
}

void segmentedsieve(){
    LLI upto=sqrt(mxx);
    FREP(i,2,upto){
        LLI mindiv=mnn/i;
        LLI countstart=i*mindiv;
        for(LLI j=countstart;j<=mxx;j+=i){
            if(j<mnn)continue;
            LLI idx=j-mnn+1;
            if(i<j && i>1)divisors[idx].PB(i);
            LLI another=j/i;
            if(another<j && another>i){
                divisors[idx].PB(another);
            }
        }
    }
}

void store(){
    FREP(i,1,(mxx-mnn+1)){
        divisorsorted[i].PB(1);
        cnt[i].PB(0);
        mxchild[i].PB(0);
        divcnt[i].PB(0);
        //set<LLI>::iterator it;
        int lastseen=-1;
        int sz=divisors[i].size();
        for(int j=0;j<sz;j+=2){
            divisorsorted[i].PB(divisors[i][j]);
            lastseen=j;
            cnt[i].PB(0);
            mxchild[i].PB(0);
            divcnt[i].PB(0);
        }
        int nxtj=sz-1;
        if(lastseen==nxtj)nxtj--;
        for(int j=nxtj;j>=0;j-=2){
            divisorsorted[i].PB(divisors[i][j]);
            //lastseen=j;
            cnt[i].PB(0);
            mxchild[i].PB(0);
            divcnt[i].PB(0);
        }
    }
}

LLI getscore(int idx){
    int sz=divisorsorted[idx].size();
    LLI mxx=0;
    FREP(i,0,(sz-1)){
        cnt[idx][i]=mxchild[idx][i]+divcnt[idx][i];
        mxx=max(cnt[idx][i],mxx);
        FREP(j,(i+1),(sz-1)){
            if(divisorsorted[idx][j]%divisorsorted[idx][i]==0){
                mxchild[idx][j]=max(mxchild[idx][j],cnt[idx][i]+1);
                divcnt[idx][j]++;
            }
        }
    }
    return (mxx+sz+1);
}

void print(){
    int total=0;
    set<LLI>oka;
    FREP(i,1,(mxx-mnn+1)){
        int sz=divisorsorted[i].size();
        //cout<<sz<<"\n";
        total+=sz;
        printf("%lld : ",mnn+i-1);
        for(int j=0;j<sz;j++){
            oka.insert(divisorsorted[i][j]);
            printf("%lld ",divisorsorted[i][j]);
        }
        printf("\n");
        //printf("\n");
    }
    //set<LLI>::iterator it; it=oka.end();
    //printf("%lld\n",*(--it));
    //printf("%d\n",total);
    //printf("%d\n",oka.size());
}

void solve(){
    LLI total=0;
    FREP(i,1,(mxx-mnn+1)){
        LLI pp=getscore(i);
        if((i+mnn-1)==1)pp=0;
     //   cout<<i+mnn-1<<": "<<pp<<"\n";
        total+=pp;
    }
    printf("%lld\n",total);
}

int main(){
    scanf("%lld %lld",&mnn,&mxx);
    init();
    segmentedsieve();
    store();
    print();
    solve();
    return 0;
}
