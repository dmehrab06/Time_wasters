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

int grid[1003][3004];
int changemade[1003][3004];

void fillgrids(int idx){
    FREP(i,1,idx)grid[idx][(2*i)-1] = i;
    FREP(i,1,(2*idx-1))if(grid[idx][i]==0)grid[idx][i]=-1;
}

void dinaalgo(int idx){
    int mxidx = (2*idx-1);
    RFREP(i,mxidx,1){
        if(grid[idx][i]==-1)continue;
        int em = -1;
        RFREP(j,i,1){
            if(grid[idx][j]==-1){
                em = j;
                break;
            }
        }
        if(em==-1)break;
        changemade[idx][grid[idx][i]]++;
        swap(grid[idx][em],grid[idx][i]);

    }
}

void simulate(int n){
    FREP(i,1,n)fillgrids(i);
    FREP(i,1,n)dinaalgo(i);
    /*FREP(i,1,n){
        if(i%2)continue;
        FREP(j,1,i)printf("%3d",grid[i][j]);
        printf("\n");
    }
    printf("\n");
    FREP(i,1,n){
        if(i%2)continue;
        printf("for %d elements\n",i);
        FREP(j,1,i)printf("%d underwent change %d times\n",j,changemade[i][j]);
        printf("\n");
    }
    printf("\n");

    FREP(i,1,n){
        if(i%2==0)continue;
        FREP(j,1,i)printf("%3d",grid[i][j]);
        printf("\n");
    }
    printf("\n");

    FREP(i,1,n){
        if(i%2)continue;
        printf("for %d elements\n",i);
        FREP(j,1,i)printf("%d underwent change %d times\n",j,changemade[i][j]);
        printf("\n");
    }
    printf("\n");*/

    FREP(i,1,n){
        //if(i%2)continue;
        //printf("for %d elements\n",i);
        FREP(j,1,i)if( (changemade[i][j]-changemade[i][j-1])>1 && (j<i))cout<<"vua\n";
        //printf("\n");
    }
    printf("\n");

}

int main(){
    int n = 1000;
    simulate(n);
}
