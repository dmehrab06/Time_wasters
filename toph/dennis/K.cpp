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
#define OPEN first
#define CLOS second
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int fibo[100005];
int fiboseries[100005];

void setfibo(){
    fiboseries[0]=0;
    fiboseries[1]=1;
    FREP(i,2,100003)fiboseries[i]=fiboseries[i-1]+fiboseries[i-2];
    FREP(i,0,100003){
        if(fiboseries[i]>100005)break;
        fibo[fiboseries[i]]=1;
    }
}

char goal[100005];

int main(){
    setfibo();
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        scanf("%s",goal);
        int ll =strlen(goal);
        int m = 0;
        int b = 0;
        FREP(i,0,(ll-1)){
            if(goal[i]=='M'){
                if(!fibo[i])m++;
            }
            else if(goal[i]=='B'){
                if(!fibo[i])b++;
            }
        }
        if(b>m){
            printf("Case #%d: Aaj Kemon Bodh Korcho\n",cs);
        }
        else if(m>b){
            printf("Case #%d: Hala Madrid\n",cs);
        }
        else{
            printf("Case #%d: Meh :\\\n",cs);
        }
    }
    return 0;
}
