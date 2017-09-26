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
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int gorualive[1003];

int milk[1003][25211];

int gorucycle[1003];

int arr[1003];

int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}
int findlcm(int n)
{
    int ans = arr[0];
    for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
                (gcd(arr[i], ans)) );
    return ans;
}

void init(int n){
    FREP(i,1,n){
        gorualive[i]=1;
    }
}

int fillarray(int n){
    int llc = findlcm(n);
    FREP(i,1,n){
        FREP(j,0,(llc-1)){
            milk[i][j]=milk[i][j%gorucycle[i]];
        }
    }
    return llc;
}

PII solve(int n, int llc){
    int khaisi = 0;
    int lastday = -1;
    int goruase = n;
    int it = 0;
    while(true){
        int gese = 0;
        FREP(day,0,(llc-1)){
            if(goruase==0)break;
            int minproduce = 100000;
            int mincount = 1;
            int hotovagagoru = -1;
            FREP(i,1,n){
                if(gorualive[i]==1){
                    if(milk[i][day]<minproduce){
                        minproduce = milk[i][day];
                        mincount = 1;
                        hotovagagoru = i;
                    }
                    else if(milk[i][day]==minproduce){
                        mincount++;
                    }
                }
            }
            if(mincount==1 && hotovagagoru!=-1){
                gorualive[hotovagagoru]=0;
                goruase--;
                lastday = day+(it*llc);
                khaisi++;
                gese  =1;
            }
        }
        if(!gese)break;
        it++;
    }
    return make_pair(n-khaisi,lastday+1);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        FREP(i,1,n){
            scanf("%d",&gorucycle[i]);
            arr[i-1]=gorucycle[i];
            FREP(k,0,gorucycle[i]-1){
                scanf("%d",&milk[i][k]);
            }
        }
        int llc = fillarray(n);
        /*FREP(i,1,n){
            FREP(j,0,llc-1){
                printf("%d ",milk[i][j]);
            }
            printf("\n");
        }*/
        PII ans = solve(n,llc);
        printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}
