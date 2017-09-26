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

map<int,int>pidx;


int a[100005];
int b[100005];

void takep(int n){
    FREP(i,1,n){
        int aa;
        scanf("%d",&aa);
        pidx[aa]=i;
    }
}

bool solve(int l, int r,int n){
    int curidx=pidx[1];
    int curdif=l-a[curidx];
    FREP(i,1,n){
        curidx=pidx[i];
        int possibleb=(curdif+a[curidx]);
        if(possibleb>r){
            return false;
        }
        else if(possibleb<l){
            int difreq=l-a[curidx];
            if(difreq<curdif){
                return false;
            }
            else{
                b[curidx]=l;
                curdif=difreq+1;
            }
        }
        else{
            b[curidx]=possibleb;
            curdif++;
        }
    }
    return true;
}

void takea(int n){
    FREP(i,1,n){
        scanf("%d",&a[i]);
    }
}



int main(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    takea(n);
    takep(n);
    bool ok=solve(l,r,n);
    if(ok){
        FREP(i,1,n){
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    else{
        printf("-1\n");
    }
    return 0;
}
