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
LLI mxx;
LLI mnn;

void init(){
    LLI tot=mxx-mnn+1;
    vector <LLI> line;
    FREP(i,1,(tot+2)){
        divisors.PB(line);
        divisorsorted.PB(line);
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
            divisors[idx].PB(i);
            LLI another=j/i;
            if(another!=i){
                divisors[idx].PB(another);
            }
        }
    }
}

void store(){
    FREP(i,1,(mxx-mnn+1)){
        int sz=divisors[i].size();
        int lastseen;
        divisorsorted[i].PB(1);
        for(int j=0;j<sz;j+=2){
            lastseen=j;
            divisorsorted[i].PB(divisors[i][j]);
        }
        int nxtj=sz-1;
        if(lastseen==nxtj)nxtj--;
        for(int j=nxtj;j>=0;j-=2){
            divisorsorted[i].PB(divisors[i][j]);
        }
    }
}

void print(){
    int total=0;
    set<LLI>oka;
    FREP(i,1,(mxx-mnn+1)){
        int sz=divisorsorted[i].size();
        total+=sz;
        //printf("%lld : ",mnn+i-1);
        for(int j=0;j<sz;j++){
            oka.insert(divisorsorted[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n",total);
    printf("%d\n",oka.size());
}

int main(){
    scanf("%lld %lld",&mnn,&mxx);
    init();
    segmentedsieve();
    store();
    print();
}
