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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI sod(int n){
    int p =sqrt(n);
    LLI s=0;
    FREP(i,2,p){
        if(n%i==0){
            s+=i;
            int j=n/i;
            if(i!=j){
                s+=j;
            }
        }
    }
    return s;
}

LLI brutesolve(int n){
    LLI s=0;
    FREP(i,1,n){
        s+=sod(i);
    }
    return s;
}

LLI getsum(int from , int to, int mul){
    if(from>to){
        return 0;
    }
    LLI a1 = (LLI)to*(to+1); a1/=2;
    LLI a2 = (LLI)from*(from-1); a2/=2;
    return (a1-a2)*mul;
}

LLI solve(int n){
    LLI s = 0;
    int sq = sqrt(n);
    int prev = -1;
    int prevcnt  = -1;
    int frnt  = 1000000000;
    int bck = 1;
    for(int i=2; i<=sq; ++i){
        int div1= i;
        int div2 = n/i;
        frnt = div1;
        bck = div2;
        int cntdiv1 = div2-1;
        if(div1==div2)cntdiv1=0;
        int cntdiv2 = (n/div2)-1;
        //cout<<div1<<" ache "<<cntdiv1<<"\n";
        //cout<<div2<<" ache "<<cntdiv2<<"\n";
        s = s + (LLI)div1*cntdiv1;
        //cout<<"s now "<<s<<"\n";
        s = s + (LLI)div2*cntdiv2;
        //cout<<"s now "<<s<<"\n";
        if(prev!=-1){
            int to = prev - 1;
            int from = div2 + 1;

            s = s  + getsum(from,to,prevcnt);
            //cout<<"aro jog korlam "<<inbetween<<" "<<prevcnt<<" sonkhok\n";
            //cout<<"s now "<<s<<"\n";
        }
        prev = div2;
        prevcnt = cntdiv2;
    }
    s  = s+getsum(frnt+1,bck-1,prevcnt);
    return s;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cs++,solve(n));
    }
    return 0;
}
