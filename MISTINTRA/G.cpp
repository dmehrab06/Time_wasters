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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

vector<PII>allt;

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        LLI n; int m;
        scanf("%lld %d",&n,&m);
        allt.clear();
        FREP(task,1,m){
            int tt,need;
            scanf("%d %d",&tt,&need);
            allt.PB(make_pair(tt,need));
        }
        SORTV(allt);
        LLI curt = 0;
        int f = 1;
        FREP(i,0,allt.size()-1){
            curt+=allt[i].second;
            //cout<<curt<<" "<<allt[i].first<<"\n";
            if(curt>(LLI)allt[i].first){
                f = 0;
                break;
            }
        }
        if(!f || curt>n){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
