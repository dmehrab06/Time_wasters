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

LLI twopow[50];
LLI threepow[50];

set <LLI> all;
vector <LLI> fin;

void init(){
    twopow[0] = 1; threepow[0] = 1;
    FREP(i,1,40){
        twopow[i] = twopow[i-1]*2;
        if(twopow[i]>(LLI)2000000000){
            twopow[i] = 0;
            break;
        }

    }
    FREP(i,1,40){
        threepow[i] = threepow[i-1]*3;
        if(threepow[i]>(LLI)2000000000){
            threepow[i] = 0;
            break;
        }
    }
    FREP(i,1,40){
        FREP(j,1,40){
            LLI pp = twopow[i]*threepow[j];
            if(pp>0)all.insert(pp);
        }
    }
    set<LLI>::iterator it;
    for(it = all.begin(); it!=all.end();++it)fin.PB(*it);
}

int main(){
    int l,r;
    scanf("%d %d",&l,&r);
    init();
    int c = 0;
    FREP(i,0,fin.size()-1){
        LLI x = fin[i];
        if(INRANGEI(x,(LLI)l,(LLI)r))c++;
    }
    cout<<c<<"\n";
    return 0;
}
