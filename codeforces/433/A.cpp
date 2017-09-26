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

#define MAXN 300002
//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
using namespace std;

int costs[MAXN];
PII planes[MAXN];
int timeslot[2*MAXN];
int finaltime[MAXN];

void init(){
    memset(timeslot,-1,sizeof(timeslot));
}

void place(int n, int k){
    int latest = k+1;
    FREP(i,1,n){
        PII cur = planes[i]; int id = -cur.second;
        if(id>k && timeslot[id]==-1){
            timeslot[id]=id;
            if(id==latest)
                while(timeslot[latest]!=-1)latest++;

        }
        else{
            timeslot[latest]=id;
            while(timeslot[latest]!=-1)latest++;
        }
    }
    FREP(i,(k+1),(k+n)){
        finaltime[timeslot[i]]=i;
    }
}

LLI getcost(int n, int k){
    LLI sum = 0;
    FREP(i,1,n){
        LLI d = finaltime[i]-i;
        LLI c = costs[i];
        sum = sum + (d*c);
    }
    return sum;
}

int main(){
    int n,k;
    init();
    scanf("%d %d",&n,&k);
    FREP(i,1,n){
        int cost;
        scanf("%d",&cost);
        costs[i]=cost; planes[i]=make_pair(-cost,-i);
    }
    sort(planes+1,planes+1+n);
    place(n,k);
    LLI ans = getcost(n,k);
    cout<<ans<<"\n";
    for(int i=1;i<=n;++i){
        cout<<finaltime[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
