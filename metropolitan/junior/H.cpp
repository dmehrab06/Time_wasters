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

int pts[500005];

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n,k,d;
        cin>>n>>k>>d;
        FREP(i,1,n){
            scanf("%d",&pts[i]);
        }
        sort(pts+1,pts+1+n);
        int f = -1;
        int lastneg = 0;
        int smallest = d+1;
        FREP(i,1,n){
            if(pts[i]<0)lastneg = i;
            if(pts[i]<0)continue;
            int righter = i+k-1;
            int lefter = i-k+1;
            if(righter<=n){
                int dis = pts[righter]-pts[i];
                if(dis<smallest){
                    smallest = dis;
                    f = pts[i];
                }
            }
            if(lefter>=1){
                int dis = abs(pts[lefter]-pts[i]);
                if(dis<smallest){
                    smallest = dis;
                    f = pts[i];
                }
            }
        }
        //0 point nia check
        if((lastneg-k+1)>=1){
            int nwleft = pts[lastneg-k+1];
            int nwdis = abs(nwleft);
            if(nwdis<=smallest && nwdis<=d){
                smallest = nwdis;
                f = 0;
            }
        }
        if(smallest<=d){
            printf("Case %d: %d %d\n",cs,smallest,f);
        }
        else{
            /*if(allneg){
                //int curp = 0;
                int lefti = pts[n-k+1];
                int dis = abs(lefti);
                if(dis<=d){
                    printf("Case %d: %d 0\n",cs,dis);
                }
                else{
                    printf("Case %d: Get Slimmer. :/\n",cs);
                }
            }
            else{*/
                printf("Case %d: Get Slimmer. :/\n",cs);
            //}

        }
    }
    return 0;
}
