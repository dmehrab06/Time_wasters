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

#define MXBIT 20

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int shelfposafterop[100005][1003]; //=-1 means still empty
char shelfstate[100005][1003];
int qans[100005];

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int ans = 0;
    FREP(i,1,q){
        int type;
        scanf("%d",&type);
        if(type==1){
            int shelf,pos;
            scanf("%d %d",&shelf,&pos);
            FREP(j,1,n){
                //copy all things previously here
                shelfposafterop[i][j] = shelfposafterop[i-1][j];
            }
            if(shelfposafterop[i][shelf]==0){
                //hasn't been done anything with the shelf yet
                shelfposafterop[i][shelf] = i;
                FREP(j,1,m)shelfstate[i][j] = '0';
                shelfstate[i][pos] = '1';
                ans++;
            }
            else{
                int prevop = shelfposafterop[i][shelf];
                FREP(j,1,m)shelfstate[i][j] = shelfstate[prevop][j];
                if(shelfstate[i][pos]==0)ans++;
                shelfstate[i][pos] = '1';
                shelfposafterop[i][shelf] = i;
            }
            qans[i] = ans;
        }
        else if(type==2){
            int shelf,pos;
            scanf("%d %d",&shelf,&pos);
            FREP(j,1,n){
                //copy all things previously here
                shelfposafterop[i][j] = shelfposafterop[i-1][j];
            }
            if(shelfposafterop[i][shelf]==0){
                //hasn't been done anything with the shelf yet
                shelfposafterop[i][shelf] = i;
                FREP(j,1,m)shelfstate[i][j] = '0';
            }
            else{
                int prevop = shelfposafterop[i][shelf];
                FREP(j,1,m)shelfstate[i][j] = shelfstate[prevop][j];
                if(shelfstate[i][pos]==1)ans--;
                shelfstate[i][pos] = '0';
                shelfposafterop[i][shelf] = i;
            }
            qans[i] = ans;
        }
        else if(type==3){
            int shelf;
            scanf("%d",&shelf);
            FREP(j,1,n){
                //copy all things previously here
                shelfposafterop[i][j] = shelfposafterop[i-1][j];
            }
            if(shelfposafterop[i][shelf]==0){
                //hasn't been done anything with the shelf yet
                shelfposafterop[i][shelf] = i;
                FREP(j,1,m)shelfstate[i][j] = '1';
                ans+=m;
            }
            else{
                int prevop = shelfposafterop[i][shelf];
                FREP(j,1,m){
                    if(shelfstate[prevop][j]=='0'){
                        ans++;
                        shelfstate[i][j] = '1';
                    }
                    else{
                        ans--;
                        shelfstate[i][j] = '0';
                    }
                }
                shelfposafterop[i][shelf] = i;
            }
            qans[i] = ans;
        }
        else if(type==4){
            int op;
            scanf("%d",&op);
            FREP(j,1,n){
                shelfposafterop[i][j] = shelfposafterop[op][j];
            }
            qans[i] = qans[op];
            ans = qans[i];
        }
    }
    FREP(i,1,q){
        printf("%d\n",qans[i]);
    }
    return 0;
}
