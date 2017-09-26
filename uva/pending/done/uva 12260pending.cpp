#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000005
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
using namespace std;

struct prod{
    int p;
    int j;
    prod(int _p=MXX, int _j=MNN){
        p=_p;
        j=_j;
    }
};

bool cmp(prod &a, prod &b){
    if(a.p==b.p)return a.j<b.j;
    return a.p>b.p;
}

prod all[1003];
int total;
int dpjan[1003][1003];
int dppetra[1003][1003];
void init(){
    FREP(i,0,1002)FREP(j,0,1002){dpjan[i][j]=-1;dppetra[i][j]=-1;}
    dpjan[0][0]=0;
    dppetra[0][0]=0;
}

int solve(int idx,int take){
    if(take>((idx+1)/2))return 0;
    if(idx==0)return 0;
    if(dpjan[idx][take]!=-1){
        return dpjan[idx][take];
    }
    int jret1=MNN,pret1=MNN;
    int jret2=MNN,pret2=MNN;
    jret1=solve(idx-1,take);
    pret1=dppetra[idx-1][take]+all[idx].p;
    if(take>0){
        jret2=solve(idx-1,take-1)+all[idx].j;
        pret2=dppetra[idx-1][take-1];
    }
    if(jret1>jret2){
        dpjan[idx][take]=jret1;
        dppetra[idx][take]=pret1;
    }
    else if(jret1<jret2){
        dpjan[idx][take]=jret2;
        dppetra[idx][take]=pret2;
    }
    else{
        dpjan[idx][take]=jret1;
        dppetra[idx][take]=max(pret1,pret2);
    }
    return dpjan[idx][take];
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
       // scanf("%s %s",&a,&b);
        //all.clear();
        //prod dummy;
        //all.PB(dummy);
        scanf("%d",&total);
        char name[10];
        scanf("%s",name);
        FREP(i,1,total){
            int p,j;
            scanf("%d %d",&p,&j);
            prod pp(p,j);
            all[i]=pp;
        }
        sort(all+1,all+1+total,cmp);
        int initpetra=0;
        //in dp jan always goes first
        if(name[0]=='P'){
            initpetra=all[1].p;
            FREP(i,1,(total-1)){
                all[i]=all[i+1];
            }
            total--;
        }
        init();
        int cantake=(total+1)/2;
        solve(total,cantake);
        printf("%d %d\n",dppetra[total][cantake]+initpetra,dpjan[total][cantake]);
    }
    return 0;
}
