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

int votegot[103];
int lastvotetime[103];

bool solve1(int n, int k, int m , int a, int idx){
    VI tot;
    int hehas = votegot[idx];
    int before = 0;
    int after = 0;
    FREP(i,1,n){
        if(i==idx)continue;
        if(votegot[i]>hehas)before++;
        if(votegot[i]<hehas){after++;tot.PB(votegot[i]);}
        if(votegot[i]==hehas){
            if(lastvotetime[i]<lastvotetime[idx])before++;
            else{
                after++;
                tot.PB(votegot[i]);
            }
        }
    }
    SORTV(tot);
    REVV(tot);
    if(before>=k)return false;
    int left = m-a;
    FREP(i,0,tot.size()-1){
        int need = hehas-tot[i]+1;
        //cout<<hehas<<" "<<tot[i]<<"\n";
        //cout<<"he needs "<<need<<"\n";
        if(need>left)break;
        left-=need;
        before++;
    }
    if(before>=k)return false;
    return true;
}

bool solve23(int n, int k, int m, int a, int idx){
    int hello = votegot[idx]+(m-a);
    if(hello==0)return true;
    VI tot;
    FREP(i,1,n)if(i!=idx)tot.PB(votegot[i]);
    SORTV(tot);
    int has = 0;
    RFREP(i,tot.size()-1,0){
        if(tot[i]>=hello)has++;
        else break;
    }
    return (has>=k);
}

int main(){
    int n,k,m,a;
    scanf("%d %d %d %d",&n,&k,&m,&a);
    FREP(i,1,a){
        int cit;
        scanf("%d",&cit);
        votegot[cit]++;
        lastvotetime[cit]=i;
    }
    FREP(idx,1,n){
        if(votegot[idx]>0 && solve1(n,k,m,a,idx)){
            printf("1 ");
        }
        else{
            if(solve23(n,k,m,a,idx)){
                printf("3 ");
            }
            else{
                printf("2 ");
            }
        }
    }
    printf("\n");
    return 0;
}
