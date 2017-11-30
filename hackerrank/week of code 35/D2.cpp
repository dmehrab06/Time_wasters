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

vector < VI > arr;
vector < VI > lsum;
vector < VI > rsum;
vector < VI > sum;

void init(int n, int m){
    //cout<<"aschi\n";
    FREP(i,1,(n+3)){
        VI line;
        arr.PB(line);
        lsum.PB(line); rsum.PB(line);
        sum.PB(line);
        FREP(j,1,m+2){
            arr[i-1].PB(0);
            lsum[i-1].PB(0); rsum[i-1].PB(0);
            sum[i-1].PB(0);
        }
    }
}

void takeinp(int n, int m){
    FREP(i,1,n)FREP(j,1,m)scanf("%d",&arr[i][j]);
}

int solve(int n, int m){
    {
        FREP(i,1,n)FREP(j,1,m)lsum[i][j]=-1000000009;
        FREP(j,1,m)lsum[1][j]=arr[1][j];
        lsum[1][1] = arr[1][1];
        FREP(j,2,m){
            if((arr[1][j]+lsum[1][j-1])>lsum[1][j]){
                lsum[1][j] = arr[1][j]+lsum[1][j-1];
            }
        }
    }

    {
        FREP(i,1,n)FREP(j,1,m)rsum[i][j]=0;
        rsum[1][m] = arr[1][m];
        RFREP(j,m-1,1){
            if((arr[1][j+1]+rsum[1][j+1])>rsum[1][j]){
                rsum[1][j] = arr[1][j+1]+rsum[1][j+1];
            }
        }
    }
    FREP(i,1,n)FREP(j,1,m)sum[i][j]=-1000000009;
    FREP(j,1,m)sum[1][j]=lsum[1][j]+rsum[1][j];

    {
        FREP(i,1,n-1){
            FREP(j,1,m){
                RFREP(l,j,1){
                    FREP(r,j,m){
                        int ss = 0;
                        FREP(k,l,r)ss+=arr[i+1][k];
                        FREP(k,l,r)sum[i+1][k]=max(sum[i+1][k],ss+sum[i][j]);
                    }
                }
            }
        }
    }

    int mxx = -1000000009;
    FREP(j,1,m)mxx = max(mxx,sum[n][j]);
    return mxx;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init(n,m);
    //cout<<"init hoise\n";
    takeinp(n,m);
    printf("%d\n",solve(n,m));
}
