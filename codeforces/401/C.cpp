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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<VI>mat;

int minrange[100005];

void takemat(int n, int m){
    FREP(i,1,max(n,m)){
        minrange[i]=1000000000;
    }
    mat.clear();
    VI line;
    FREP(i,0,(n+3)){
        mat.PB(line);
        mat[i].PB(-1);
    }
    FREP(i,1,n){
        FREP(j,1,m){
            int a;
            scanf("%d",&a);
            mat[i].PB(a);
        }
    }
}

void docolumn(int col, int n){
    int prev=mat[1][col];
    int curstart=1;
    int curend=0;
    while(true){
        curend++;
        if(curend>n || mat[curend][col]<prev){
            //cout<<"for col "<<col<<" updating from "<<curstart<<" to "<<curend-1<<"\n";
            if(minrange[curend-1]>curstart){
                minrange[curend-1]=curstart;
            }
            curstart=curend;
            if(curend>n){
                break;
            }
            else{
                prev=mat[curstart][col];
                curend--;
            }
        }
        else{
            prev=mat[curend][col];
            minrange[curend]=min(minrange[curend],curstart);
        }
    }
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takemat(n,m);
    FREP(i,1,m){
        docolumn(i,n);
    }
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int l,r;
        scanf("%d %d",&l,&r);
        int mnn=minrange[r];
        if(mnn<=l){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
