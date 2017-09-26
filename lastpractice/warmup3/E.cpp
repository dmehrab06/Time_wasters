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

ifstream fin("E.IN");

int cursz = 0;
int curcolumsz = 0;
vector< VI >folds;

void init(int n){
    FREP(i,0,(n-1)){
        VI line;
        folds.PB(line);
        folds[i].PB(i+1);
    }
    cursz = n;
    curcolumsz = 1;
}

void processRD(){
    //left fixed thakbe
    int half = cursz/2;
    int dest = 0;
    RFREP(i,cursz-1,half){
         RFREP(k,curcolumsz-1,0){
            folds[dest].PB(folds[i][k]);
         }
         dest++;
    }
    cursz/=2;
    curcolumsz*=2;
}

void processLD(){
    //right fixed thakbe
    int half = cursz/2;
    int dest = cursz-1;
    FREP(i,0,half-1){
         RFREP(k,curcolumsz-1,0){
            folds[dest].PB(folds[i][k]);
         }
         dest--;
    }
    FREP(i,half,cursz-1){
        folds[i-half]=folds[i];
    }
    cursz/=2;
    curcolumsz*=2;
}

void processRU(){
    //left fixed thakbe
    int half = cursz/2;
    int dest = 0;
    RFREP(i,cursz-1,half){
         REVV(folds[dest]);
         RFREP(k,0,curcolumsz-1){
            folds[dest].PB(folds[i][k]);
         }
         REVV(folds[dest]);
         dest++;
    }
    cursz/=2;
    curcolumsz*=2;
}

void processLU(){
    //right fixed thakbe
    int half = cursz/2;
    int dest = cursz-1;
    FREP(i,0,half-1){
         REVV(folds[dest]);
         FREP(k,0,curcolumsz-1){
            folds[dest].PB(folds[i][k]);
         }
         REVV(folds[dest]);
         dest--;
    }
    FREP(i,half,cursz-1){
        folds[i-half]=folds[i];
    }
    cursz/=2;
    curcolumsz*=2;
}

void print(){
    FREP(j,0,(curcolumsz-1)){
        FREP(i,0,cursz-1){
            cout<<folds[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

string str;

int main(){
    init(1024);
    while(fin>>str){
        //cout<<"before\n";
        //print();
        //cout<<"\n\n";
        if(str[0]=='L' && str[1]=='U'){
            processLU();
        }
        if(str[0]=='R' && str[1]=='U'){
            processRU();
        }
        if(str[0]=='L' && str[1]=='D'){
            processLD();
        }
        if(str[0]=='R' && str[1]=='D'){
            processRD();
        }
        //cout<<"after\n";
        //print();
        //cout<<"\n\n";
    }
    FREP(i,0,folds[0].size()-1){
        cout<<folds[0][i]<<"\n";
    }
    fin.close();
    return 0;
}
