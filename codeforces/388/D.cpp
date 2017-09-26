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

vector<VI>personpos;
int elemfreq[200006];
int forbidden[200006];
int forb[200006];



vector<PII>oka;

void init(int n){
    VI line;
    FREP(i,0,(n+4)){
        personpos.PB(line);
        elemfreq[i]=0;
    }
}

void takeinp(int n){
    FREP(i,1,n){
        int idx,tk;
        scanf("%d %d",&idx,&tk);
        oka.PB(make_pair(idx,tk));
        personpos[idx].PB(i);
        elemfreq[idx]++;
    }
}

int binlow(int z, int x){ //find first p such that p>=x
    int l=0;
    int r=elemfreq[z]-1;
    int lo=l;
    int hi=r;
    if(elemfreq[z]==0 || personpos[z][r-1]<x)return r;
    while(true){
        int m=(lo+hi)/2;
        int p=personpos[z][m];
        if(p>=x){
            if(m>0 && personpos[z][m-1]>=x){
                hi=m;
            }
            else{
                return m;
            }
        }
        else{
            lo=m+1;
        }
    }
}

int binhigh(int z, int x){ //find first p such that p<=x
    int l=0;
    int r=elemfreq[z]-1;
    int lo=l;
    int hi=r;
    if(elemfreq[z]==0 || personpos[z][l]>x)return -1;
    while(true){
        int m=(lo+hi)/2;
        int p=personpos[z][m];
        if(p<=x){
            if(m<(r) && personpos[z][m+1]<=x){
                lo=m+1;
            }
            else{
                return m;
            }
        }
        else{
            hi=m;
        }
    }
}

int cntfreq(int l, int r, int z){
    if(elemfreq[z]==0)return 0;
    int lidx=binlow(z,l);
    int ridx=binhigh(z,r);
    if(ridx<lidx){
        return 0;
    }
    //cout<<z<<" ase "<<l<<" theke "<<r<<" er vitore "<<lidx<<" theke "<<ridx<<" porjonto\n";
    return ridx-lidx+1;
}

bool komase(int lo, int m, int hi, int elem, int forbiddensize){
    int lpos=personpos[elem][m];
    int rpos=personpos[elem][hi];
   // cout<<"lo : "<<lo<<" m : "<<m<<" hi : "<<hi<<"\n";
   // cout<<"lpos : "<<lpos<<" rpos: "<<rpos<<"\n";
    int f1=cntfreq(lpos,rpos,elem);
  //  cout<<"elem "<<elem<<" ase "<<f1<<" bar\n";
    FREP(i,1,forbiddensize){
        int ff=cntfreq(lpos,rpos,forbidden[i]);
   //     cout<<"current forbidden element "<<forbidden[i]<<" ase "<<ff<<" bar "<<"\n";
        f1+=ff;
        // cout<<lpos<<" "<<rpos<<" "<<forbidden[i]<<" "<<ff<<"\n";
    }
    int ase=(rpos-lpos+1);
   // cout<<"ase "<<ase<<" f1 "<<f1<<"\n";
    if(f1<ase)return true;
    return false;
}

int findbid(int forbiddensize, int elem){
    int l=0;
    int r=elemfreq[elem]-1;
    int lo=l;
    int hi=r;
   // cout<<"findbid for "<<elem<<"\n";
    while((lo+1)<hi){
        int m=(lo+hi)/2;
        bool kom=komase(lo, m,hi,elem, forbiddensize);
        if(!kom){
            hi=m;
        }
        else{
            lo=m;
        }
    }
    if(lo==hi)return lo;
    if(komase(lo,lo,hi,elem,forbiddensize))return hi;
    return lo;
}


int main(){
    int n;
    scanf("%d",&n);
    init(n);
    takeinp(n);
    int q;
    /*FREP(i,0,(n+1)){
        printf("%d : ",i);
        FREP(j,0,elemfreq[i]-1){
            printf("%d ",personpos[i][j]);
        }
        printf("\n");
    }*/
    scanf("%d",&q);
    FREP(qq,1,q){
        int k;
        scanf("%d",&k);
        FREP(i,1,k){
            scanf("%d",&forbidden[i]);
            forb[forbidden[i]]=qq;
        }
        int myidx=-1;
        RFREP(i,(n-1),0){
            int idx=oka[i].first;
            if(forb[idx]!=qq){
                myidx=idx;
                break;
            }
        }
        //cout<<myidx<<"\n";
        if(myidx==-1){
            printf("0 0\n");
        }
        else{
            int hoho=findbid(k,myidx);
            printf("%d %d\n",myidx,oka[personpos[myidx][hoho]-1].second);
        }
    }
    return 0;
}

