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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.00000000001
#define PI acos(-1.0)
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



typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double angleBetween(pair<LLI,LLI> v1, pair<LLI,LLI> v2)
{
    double len1 = sqrt((double)(v1.first * v1.first + v1.second * v1.second));
    double len2 = sqrt((double)(v2.first * v2.first + v2.second * v2.second));

    double dot = (double) (v1.first * v2.first + v1.second * v2.second);

    double a = dot / (len1 * len2);

    if (a > 1.0 || fabs(a-1.0)<eps)
        return 0.0;
    else if (a < -1.0 || fabs(a+1.0)<eps)
        return PI;
    else
        return acos(a); // 0..PI
}

int main()
{
    int n;
    while(scanf("%d",&n)==1){
        double ans=0.0;
        pair<LLI,LLI>p2=make_pair(5,0);
        FREP(i,1,n){
            LLI x,y;
            scanf("%lld %lld",&x,&y);
            pair<LLI,LLI>p3=make_pair(x,y);
            double rad =angleBetween(p2,p3);
            double deg = rad * 180.0 / PI;
            deg = min(deg,360.0-deg);
            ans+=deg;
            p2=p3;
        }
       // ans = ans * 180.0 / PI;
        printf("%.10lf\n",ans);
    }
    return 0;
}
