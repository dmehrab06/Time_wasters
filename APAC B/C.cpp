//data structure--
//algo --  implementation
//wrong answer

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
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
using namespace std;
//char s[1003];

struct rng{
    int L; int R;
    rng(int _L=0, int _R=0){
        L=_L;
        R=_R;
    }
};

bool cmp(rng &a, rng &b){
    if(a.L==b.L)return a.R<b.R;
    return a.L<b.L;
}

rng arr[500006];
int may[500006];
int sole[500006];
int N;

void load(int N,int L1, int R1, LLI A,LLI B, LLI C1, LLI C2, LLI M){
    int prevx=L1;
    int prevy=R1;
    rng a(prevx,prevy);
    arr[0]=rng(-2,-1);
    arr[1]=a;
    may[1]=0;
    FREP(i,2,N){
        may[i]=0;
        LLI x = ( A*prevx + B*prevy + C1 ) % M;
        LLI y = ( A*prevy + B*prevx + C2 ) % M;
        //rng r(min(x,y),max(x,y));
        int ll=x;
        int rr=y;
        arr[i]=rng(min(ll,rr),max(ll,rr));
        prevx=ll;
        prevy=rr;
    }
    arr[N+1]=rng(1000000008,1000000009);
    sort(arr+1,arr+1+N,cmp);
    return;
}

int intersect(int l1, int r1, int l2, int r2){
    if(l1>r1)return 0;
    if(l2>=l1 && r2<=r1){
        return (r2-l2+1);
    }
    else if(l2<l1 && r2>r1){
        return (r1-l1+1);
    }
    else if(r2<l1 || l2>r1)return 0;
    else{
        if(l2<l1 && r2<=r1){
            return (r2-l1+1);
        }
        else if(r2>r1 && l2>=l1){
            return (r1-l2+1);
        }
    }
}

int calc(int N){
    FREP(i,1,N){
        int pvmx=arr[i-1].R;
        int nxmn=arr[i+1].L;
        int curl=arr[i].L;
        int curr=arr[i].R;
        sole[i]=intersect(pvmx+1,nxmn-1,curl,curr);
    }
    int mx=sole[1];
    FREP(i,2,N){
        if((sole[i]>mx)){
           mx=sole[i];
        }
    }
    return mx;
}

LLI initcover(int N){
    LLI tot=0;
    LLI last=-1;
    FREP(i,1,N){
        int mn=arr[i].L;
        int mx=arr[i].R;
        if(mn>last){
            tot+=(mx-mn+1);
            last=mx;
            may[i]=1;
        }
        else{
            if(mx>last){
                tot+=(mx-last);
                last=mx;
                may[i]=1;
            }
        }
    }
    return tot;
}

LLI cover(int N, int baad){
    LLI tot=0;
    LLI last=-1;
    FREP(i,1,N){
        if(i==baad)continue;
        int mn=arr[i].L;
        int mx=arr[i].R;
        if(mn>last){
            tot+=(mx-mn+1);
            last=mx;
            may[i]=1;
        }
        else{
            if(mx>last){
                tot+=(mx-last);
                last=mx;
                may[i]=1;
            }
        }
    }
    return tot;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int N, L1, R1;
        LLI A, B, C1, C2,M;
        scanf("%d %d %d %lld %lld %lld %lld %lld" ,&N,&L1,&R1,&A,&B,&C1,&C2,&M);
        load(N,L1,R1,A,B,C1,C2,M);
        LLI ans1=initcover(N);
        /*LLI mn=MXX;
        FREP(i,1,N){
            if(may[i]==1){
                LLI cur=cover(N,i);
                if(cur<mn){
                    mn=cur;
                }
            }
        }*/
        int ans2=calc(N);
        FREP(i,1,N){
            printf("%d\n",sole[i]);
        }
        LLI ans=ans1-(LLI)ans2;
       // tot=tot%1000000007;
        printf("Case #%d: %lld\n",cs++,ans);
    }
    return 0;
}
