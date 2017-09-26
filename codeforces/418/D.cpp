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
#define LEFT 1
#define RIGHT 2
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int emptypos[30][1503];

int ans[1503][30];

char orig[1503];

int strl;

void findpos(char c){
    emptypos[c-'a'][0]=1;
    emptypos[c-'a'][1]=-1;
    FREP(i,0,(strl-1)){
        if(orig[i]!=c){
            emptypos[c-'a'][0]++;
            emptypos[c-'a'][emptypos[c-'a'][0]]=i;
        }
    }
    emptypos[c-'a'][0]++;
    emptypos[c-'a'][emptypos[c-'a'][0]]=strl;
}

int findmax(char c, int m){
    int asolempty = emptypos[c-'a'][0]-2;
    if(m>=asolempty){
        return strl;
    }
    int mx=0;
    for(int i=1;(i+m-1)< emptypos[c-'a'][0] ; ++i){
        int first=emptypos[c-'a'][i-1]+1;
        int last=emptypos[c-'a'][i+m]-1;
        mx=max(mx,last-first+1);
    }
    return mx;

}

void solve(){
    for(char c='a';c<='z';++c){
        findpos(c);
        FREP(i,1,strl){
            ans[i][c-'a']=findmax(c,i);
        }
    }
}

int main(){
    scanf("%d",&strl);
    scanf("%s",orig);
    solve();
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int m;
        char cc[3];
        scanf("%d %s",&m,cc);
        printf("%d\n",ans[m][cc[0]-'a']);
    }
    return 0;
}
