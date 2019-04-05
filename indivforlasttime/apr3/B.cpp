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

double dp[52][2503];
int width[52];


double dodp(int forbidguest, int maxw, int n){
    MSET(dp,0);
    dp[0][0] = 1.0;

    for(int i = 1;i<=n;++i){
        if(i==forbidguest)continue;

        int ww = width[i];

        //will try to add ith person

        for(int has = n-2; has>=0; --has){ //i dunno why this is working
            //for(int has = 0; has<(n-1); ++has) eita dia kaaj kortese na ageo ek problem e erokom hoyechilo
            for(int sum = 0; (sum+ww)<=maxw; ++sum){
                //i already have has people
                //can put ith person in (has+1) different places
                //i already have has people
                //i have (n-has) people to choose from
                //so probability of ith being chosen 1/(n-has)
                dp[has+1][sum+ww]+= (dp[has][sum]/(double)(n-has))*(double)(has+1);
            }
        }
    }

    double tmp = 0.0;

    for(int has = 0; has<n; ++has){
        //counting probability of having has people
        //when forbiddenguest will ruin it
        for(int sum = 0; sum<=maxw; ++sum){
            if(width[forbidguest]+sum>maxw){
                //then this will contribute to my answer.
                tmp = tmp + (dp[has][sum])/(double)(n-has)*has; //expected value of has having forbidguest ruining it
                //n-has people left so 1/(n-has) probability of being chosen.
            }
        }
    }
    return tmp;
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%d",&width[i]);
    int p; scanf("%d",&p);
    double ans = 0.0;
    int ww = 0; FREP(i,1,n)ww+=width[i];
    if(ww<=p){
        printf("%d\n",n);
        return 0;
    }
    FREP(i,1,n){
        ans+=dodp(i,p,n);
    }
    printf("%.10lf\n",ans);
    return 0;
}
