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

int cnt[200005];
int arr[200005];
int canput[200005];
vector<VI>positions;
int availables[200005];
vector<int>needed;

void init(int n){
    VI line;
    FREP(i,1,(n+4)){
        positions.PB(line);
    }
}

int getfirstans(int n){
    MSET(availables,0);
    MSET(cnt,0);
    MSET(canput,0);
    FREP(i,1,n)cnt[arr[i]]++;
    int app = 0;
    FREP(i,1,n){
        if(cnt[i])app++;
        if(cnt[i]!=1)needed.PB(i);
    }
    return n-app;
}

void makeperm(int n){
    SORTV(needed);
    int iter = 1;
    FREP(i,0,needed.size()-1){
        int cur = needed[i];
        //cout<<cur<<"\n";
        if(cnt[cur]!=0){
            //eta repeated ache
            //cout<<"repeated\n";
            int hisfirst = positions[cur][availables[cur]];
            canput[hisfirst] = -1;
            availables[cur]++;
        }
        else{
            //cout<<"hehe\n";
            while(true){
                int nw = arr[iter];
                if(cnt[nw]>1 && canput[iter]!=-1){
                    arr[iter]=cur;
                    cnt[cur]=1;
                    cnt[nw]--;
                    availables[nw]++;
                    canput[iter]=-1;
                    iter++;
                    break;
                }
                iter++;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    init(n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
        positions[arr[i]].PB(i);
    }
    int ans = getfirstans(n);
    printf("%d\n",ans);
    makeperm(n);
    FREP(i,1,n)printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
