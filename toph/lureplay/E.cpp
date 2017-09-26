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

int people[100005];

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n; LLI ss;
        scanf("%d %lld",&n,&ss);
        vector < pair< pair<int,LLI>, int> > probs;
        vector < pair< pair<LLI,int>, int> > probs2;
        LLI lwsttime = 1000000000000000003;
        FREP(i,1,n){
            int tt; LLI diff;
            scanf("%d %lld",&tt,&diff);
            probs.push_back(make_pair(make_pair(tt,-diff),i));
            probs2.push_back(make_pair(make_pair(-diff,tt),i));
            lwsttime = min(lwsttime,(LLI)tt);
        }
        printf("Case %d: ",cs);
        if(lwsttime>ss){printf("RIP LUIUPC\n");continue;}
        SORTV(probs); SORTV(probs2);
        int globtaken = 0;
        LLI globmxx = 0;
        FREP(i,0,probs2.size()-1){
            LLI curmx = -probs2[i].first.first;
            int curid = probs2[i].second;
            int taken = 1;
            LLI timeuntil = probs2[i].first.second;
            if(timeuntil>ss)continue;
            FREP(k,0,probs.size()-1){
                LLI curdiff = -probs[k].first.second;
                int curidx = probs[k].second;
                if(curdiff>curmx)continue;
                if(curidx==curid)continue;
                if((timeuntil+probs[k].first.first)>ss){
                    break;
                }
                taken++;
                timeuntil+=probs[k].first.first;
            }
            if(taken>globtaken){
                globtaken  = taken;
                globmxx = curmx;
            }
        }

        printf("%d %lld\n",globtaken,globmxx);
    }
    return 0;
}
