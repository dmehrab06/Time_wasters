#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
using namespace std;
bool prime[1000006];
int sp[1000006];
int nod[1000006];
int seq[64727];
//submit er age aro improve korano jabe array bound komaia
void init(){
    FREP(i,0,1000005){
        prime[i]=true;
        sp[i]=-1;
        nod[i]=0;
        seq[i]=0;
    }
    seq[0]=1;
}
void sieve(){
    FREP(i,2,1000005){
        if(prime[i]){
            sp[i]=i;
            for(int j=(i+i);j<1000006;j+=i){
                prime[j]=false;
                if(sp[j]<0){
                    sp[j]=i;
                }
            }
        }
    }
}
int NOD(int n){
   int tot=1;
   while(n!=1){
    int a=sp[n];
    int m=0;
    while(n%a==0){
        n/=a;
        m++;
    }
    tot=tot*(m+1);
   }
   return tot;
}

int upto;

void calc(){
    upto=0;
    FREP(i,1,1000005){
        seq[i]=seq[i-1]+nod[seq[i-1]];
        upto=i;
        if(seq[i]>1000003 || seq[i]<seq[i-1])break;
    }
    //printf("%d\n",upto);
}

int lbs(int lo, int hi, int val){
    int mid=(lo+hi)/2;
    if(seq[mid]>=val){
        if((mid-1)<0){
            return mid;
        }
        else if(seq[mid-1]<val)return mid;
        return lbs(lo,mid,val);
    }
    return lbs(mid+1,hi,val);
}
int ubs(int lo, int hi, int val){
    int mid=(lo+hi)/2;
    if(seq[mid]<=val){
        if((mid+1)>upto){
            return mid;
        }
        else if(seq[mid+1]>val)return mid;
        return ubs(mid+1,hi,val);
    }
    return ubs(lo,mid,val);
}

int main(){
    init();
    sieve();
    FREP(i,1,1000005)nod[i]=NOD(i);
    calc();
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int a,b;
        scanf("%d %d",&a,&b);
        int lidx=lbs(0,upto,a);
        int ridx=ubs(0,upto,b);
        printf("Case %d: %d\n",i,ridx-lidx+1);
    }
    return 0;
}
