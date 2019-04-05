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

int xs[10005];
int hs[10005];

LLI solve(int l, int r, int a){
    //cout<<"checking from "<<l<<" to "<<r<<"\n";
    if(l>=r)return 0;
    int hleft = hs[l];
    int hright = hs[r];
    if(hleft<hright){
        //cout<<"left smaller than right\n";
        int found = -1;
        FREP(i,l,r){
            if(hs[i]>hleft){
                found = i;
                break;
            }
        }
        if(found==-1){
            //purata mile ans;
            int len = xs[r]-xs[l];
            //cout<<"length for this portion "<<len<<"\n";
            //cout<<"returning "<<a*len*hleft<<" from here\n";
            return (LLI)a*(LLI)len*(LLI)hleft;
        }
        else{
            //cout<<"length for left portion "<<(xs[found]-xs[l])<<"\n";
            LLI lans = (LLI)a*(LLI)hleft*(xs[found]-xs[l]);
            //cout<<"returning left part: "<<lans<<" and some more...\n";
            return lans+solve(found,r,a);
        }
    }
    else{
        //cout<<"right smaller than left\n";
        int found = -1;
        RFREP(i,r,l){
            if(hs[i]>hright){
                found = i;
                break;
            }
        }
        if(found==-1){
            //purata mile ans;
            int len = xs[r]-xs[l];
            //cout<<"length for this portion "<<len<<"\n";
            //cout<<"returning "<<a*len*hright<<" from here\n";
            return (LLI)a*(LLI)len*(LLI)hright;
        }
        else{
            //cout<<"length for right portion "<<xs[r]-xs[found]<<"\n";
            LLI rans = (LLI)a*(LLI)hright*(xs[r]-xs[found]);
            //cout<<"returning right part: "<<rans<<" and some more...\n";
            return rans+solve(l,found,a);
        }
    }

}

/*LLI solve2(int l, int r, int a){
    int tl = l, tr = r;
    int lok = 1, rok = 1;
    while(l<=r && (lok || rok)){
        if(lok && hs[l]>hs[tl])lok = 0;
        else if(lok)l++;
        if(rok && hs[r]>hs[tr])rok = 0;
        else if(lok)r--;
    }
    int llen = xs[l]-xs[tl];
    int rlen = xs[tr]-xs[r];
    return 0;
}*/

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,n;
        scanf("%d %d",&a,&n);
        FREP(i,1,n)scanf("%d",&xs[i]);
        FREP(i,0,n)scanf("%d",&hs[i]);
        FREP(i,1,n)xs[i]+=xs[i-1];
        printf("%lld\n",solve(0,n,a));
    }
    return 0;
}
