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

int vts[200005];
int atheight1[200005];
int atheight2[200005];

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,0,n){
        scanf("%d",&vts[i]);
    }
    int f = -1;
    FREP(i,1,n){
        if(vts[i]>1){
            if(vts[i-1]>1){
                f = i;
                break;
            }
        }
    }
    if(f==-1){
        printf("perfect\n");
    }
    else{
        printf("ambiguous\n0 ");
        //sequence 1
        atheight1[0]=1;
        int lastnode = 1;
        FREP(h,1,n){
            int curvs = vts[h];
            int par = atheight1[h-1];
            int temp = lastnode;
            FREP(node,temp+1,(temp+curvs)){
                printf("%d ",par);
                atheight1[h] = node;
                lastnode = node;
            }
        }
        printf("\n0 ");
        //sequence 2
        atheight2[0]=1;
        lastnode = 1;
        FREP(h,1,f-1){
            int curvs = vts[h];
            int par = atheight2[h-1];
            int temp = lastnode;
            FREP(node,temp+1,(temp+curvs)){
                printf("%d ",par);
                atheight2[h] = node;
                lastnode = node;
            }
        }
        int thisvs = vts[f]; //jei height e change ta ghotbe
        int par1 = atheight2[f-1];
        int par2 = par1-1; //karon at least 2 ta ache okhane
        int curtemp = lastnode;
        printf("%d ",par2);
        FREP(node,curtemp+2,(curtemp+thisvs)){
            printf("%d ",par1);
            atheight2[f] = node;
            lastnode = node;
        }
        FREP(h,f+1,n){
            int curvs = vts[h];
            int par = atheight2[h-1];
            int temp = lastnode;
            FREP(node,temp+1,(temp+curvs)){
                printf("%d ",par);
                atheight2[h] = node;
                lastnode = node;
            }
        }
        printf("\n");
    }
    return 0;
}
