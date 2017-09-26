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
#define MXX 1000000000000000000
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


typedef tree < PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int cnt[100005];

vector< vector<int> >oka;
vector< vector<int> >oka2;
void takeg(int n,int k){
    VI line;
    FREP(i,1,(k+3))oka.PB(line);
    FREP(i,1,(n+3))oka2.PB(line);
    FREP(i,1,n){
        int p;
        scanf("%d",&p);
        FREP(k,1,p){
            int ing;
            scanf("%d",&ing);
            cnt[ing]++;
            oka[ing].PB(i);
            oka2[i].PB(ing);
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        oka.clear();
        oka2.clear();
        memset(cnt,0,sizeof(cnt));
        takeg(n,k);
        int f=0;
        FREP(i,1,k){
            if(oka[i].size()==0){
                printf("sad\n");
                f=1;
                break;
            }
        }
        if(f!=1){

            int ff=0;
            FREP(island,1,n){
                int sz=oka2[island].size();
                int can=1;
                FREP(j,0,(sz-1)){
                    if(cnt[oka2[island][j]]==1){
                        can=0;
                        break;
                    }
                }
                if(can){
                    ff=1;
                    break;
                }
            }
            if(ff){
                printf("some\n");
            }
            else{
                printf("all\n");
            }

        }
    }
}
