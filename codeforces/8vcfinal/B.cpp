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

bool can(LLI x, LLI pos, LLI pillow, LLI n){
    LLI lefthas=pos-1;
    LLI righthas=n-pos;
    LLI leftedibo=min((x-1),lefthas);
    LLI lefteprothome=(leftedibo)*(leftedibo+1);
    lefteprothome/=2;
    LLI rightedibo=min((x-1),righthas);
    LLI righteprothome=(rightedibo)*(rightedibo+1);
    righteprothome/=2;
    pillow-=x;
    pillow-=lefteprothome;
    pillow-=righteprothome;
    LLI baki=(lefthas-leftedibo)+(righthas-rightedibo);
    if(pillow<baki)return false;
    return true;
}

int main(){
    LLI n,p,k;
    cin>>n>>p>>k;
    LLI lefthas=k-1;
    LLI righthas=n-k;
    LLI leftotalminus=lefthas*(lefthas+1);
    leftotalminus/=2;
    LLI rightotalminus=righthas*(righthas+1);
    rightotalminus/=2;
    LLI total=leftotalminus+rightotalminus;
    LLI hi=(p+total)/n;
    LLI lo=p/n;
    LLI ans=-1;
    if(can(hi,k,p,n)){
        cout<<hi<<"\n";
        return 0;
    }
    while(true){
        LLI mid=lo+(hi-lo)/2;
        if(can(mid,k,p,n)){
            if(can(mid+1,k,p,n)){
                lo=mid;
            }
            else{
                ans=mid;
                break;
            }
        }
        else{
            hi=mid;
        }
    }
    cout<<ans<<"\n";
}
