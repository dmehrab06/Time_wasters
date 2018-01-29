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

int seq[1000002];

void generateseq(int n, int m){
    seq[1] = 1; seq[2] = 2; seq[3] = 3;
    FREP(i,4,n)seq[i]=(seq[i-1]+seq[i-2]+seq[i-3])%m+1;
}

int getmin(int k, int n){
    int freq[1002]; MSET(freq,0);
    int found = 0; int flagfront = 1;
    int fp = 0; int bp = 1;
    int minlen = 100000000;
    while(true){
        if(flagfront==1 && fp==n)break;
        if(flagfront){
            fp++;
            if(freq[seq[fp]]==0 && INRANGEI(seq[fp],1,k)){
                found++;
            }
            freq[seq[fp]]++;
            if(found==k){
                flagfront = 1-flagfront;
            }
        }
        else{
            if(freq[seq[bp]]==1 && INRANGEI(seq[bp],1,k)){
                found--;
            }
            freq[seq[bp]]--;
            bp++;
            if(found<k){
                flagfront = 1-flagfront;
            }
        }
        if(found==k){
            minlen = min(minlen,(fp-bp+1));
        }
    }
    return minlen;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        generateseq(n,m);
        int ans = getmin(k,n);
        printf("Case %d: ",cs);
        if(ans<=n){
            printf("%d\n",ans);
        }
        else{
            printf("sequence nai\n");
        }
    }
    return 0;
}

