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
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char voter[200005];
int hasright[200005];

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    int x4=(x1+x2)-x3;
    int y4=(y1+y2)-y3;
    int x5=(x1+x3)-x2;
    int y5=(y1+y3)-y2;
    int x6=(x3+x2)-x1;
    int y6=(y3+y2)-y1;
    PII pt1=make_pair(x4,y4);PII pt2=make_pair(x5,y5);PII pt3=make_pair(x6,y6);
    pts.insert(pt1);
    pts.insert(pt2);
    pts.insert(pt3);
    cout<<pts.size()<<"\n";
    set<PII>::iterator it;
    for(it=pts.begin();it!=pts.end();++it){
        PII oka=*it;
        cout<<oka.first<<" "<<oka.second<<"\n";
    }
    return 0;
}

