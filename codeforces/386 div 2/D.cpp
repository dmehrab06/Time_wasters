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

string n;

char ans[2003];

int seq[500005];

int main(){
    int n,k,a,b;
    scanf("%d %d %d %d",&n,&k,&a,&b);
    char ff;
    char ss;
    int mxx=max(a,b);
    int mnn=min(a,b);
    if(mxx==a){
        ff='G';
        ss='B';
    }
    else{
        ff='B';
        ss='G';
    }
    int jayga=mxx/k+(mxx%k?1:0);
    int ase=mxx;
    for(int i=1,cnt=1;cnt<=jayga;i+=2,cnt++){
        seq[i]=min(ase,k);
        ase-=k;
    }
    int minjayga=jayga-1;
    if(mnn<minjayga){
        printf("NO\n");
        return 0;
    }
    int doo=!minjayga?0:mnn/minjayga;
    int did=0;
    for(int i=2,cnt=1;cnt<=minjayga;++cnt,i+=2){
        seq[i]=doo;
        did+=doo;
    }
    int lft=mnn-did;
    for(int i=2,cnt=1;cnt<=minjayga;++cnt,i+=2){
        if(seq[i]<k && lft){
            seq[i]++;
            lft--;
        }
    }
    seq[minjayga*2+2]=lft;
    for(int i=1;seq[i];i++){
        int dimu=seq[i];
        FREP(j,1,dimu){
            if(i%2){
                printf("%c",ff);
            }
            else{
                printf("%c",ss);
            }
        }
    }
    printf("\n");
    return 0;
}


