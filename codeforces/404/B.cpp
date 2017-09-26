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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI rarr1=1000000000;
LLI larr1=-1;

LLI rarr2=1000000000;
LLI larr2=-1;

pair<LLI,LLI> arr1[200005];
pair<LLI,LLI> arr2[200005];

int main(){
    LLI ans=0;
    int val1;
    cin>>val1;
    FREP(i,1,val1){
        LLI l,r;
        cin>>l>>r;
        pair<LLI,LLI>oka1=make_pair(l,r);
        arr1[i]=oka1;
        rarr1=min(rarr1,r);
        larr1=max(larr1,l);
    }
    int val2;
    cin>>val2;
    FREP(i,1,val2){
        LLI l,r;
        cin>>l>>r;
        pair<LLI,LLI>oka2=make_pair(l,r);
        arr2[i]=oka2;
        rarr2=min(rarr2,r);
        larr2=max(larr2,l);
    }
    FREP(i,1,val1){
        pair<LLI,LLI>cur=arr1[i];
        LLI dif1=max((LLI)0,cur.first-rarr2);
        LLI dif2=max((LLI)0,larr2-cur.second);
        ans=max(ans,max(dif1,dif2));
    }
    FREP(i,1,val2){
        pair<LLI,LLI>cur=arr2[i];
        LLI dif1=max((LLI)0,cur.first-rarr1);
        LLI dif2=max((LLI)0,larr1-cur.second);
        ans=max(ans,max(dif1,dif2));
    }
    cout<<ans<<"\n";
}
