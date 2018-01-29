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

char tictac[9][9];

int conv(int val){
    int ret = val%3;
    if(ret==0)return 3;
    return ret;
}

PII getrange(int val){
    int lv = val*3;
    int rv = lv+2;
    return make_pair(lv,rv);
}

bool isempty(PII xrange, PII yrange){
    bool f = false;
    FREP(i,xrange.first,xrange.second){
        FREP(j,yrange.first,yrange.second){
            if(tictac[i][j]=='.'){
                f = true;
                tictac[i][j] = '!';
            }
        }
    }
    return f;
}

void fillup(){
    FREP(i,0,8)FREP(j,0,8)if(tictac[i][j]=='.')tictac[i][j]='!';
}

void print(){
    FREP(i,0,8){
        FREP(j,0,8){
            printf("%c",tictac[i][j]);
            if((j%3)==2)printf(" ");
        }
        printf("\n");
        if((i%3)==2)printf("\n");
    }
}

int main(){
    FREP(i,1,9){
        FREP(j,1,3){
            string myst;
            cin>>myst;
            FREP(k,0,myst.size()-1){
                tictac[i-1][k+(j-1)*3]=myst[k];
            }
        }
    }
    int x,y;
    scanf("%d %d",&x,&y);
    x = conv(x)-1; y = conv(y)-1;
    if(isempty(getrange(x),getrange(y))){
        print();
    }
    else{
        fillup();
        print();
    }
    return 0;
}
