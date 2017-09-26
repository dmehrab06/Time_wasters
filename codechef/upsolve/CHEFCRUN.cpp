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
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;

int mainarr[1000007];
int cwarr[1000007];
LLI cwminarr[1000007];
int ccwarr[1000007];
LLI ccwminarr[1000007];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&mainarr[i]);
        }
        LLI globalmin=MXX;
        int s,e;
        scanf("%d %d",&s,&e);
        //clockwise
        int cur=s;
        int deshere;
        for(int i=1;i<=n;++i){
            cwarr[i]=mainarr[cur];
            if(cur==e){
                deshere=i;
            }
            cur++;
            if(cur>n)cur=1;
        }
       // cout<<"hoyese\n";
        int cur2=s;
        int deshere2;
        for(int i=1;i<=n;++i){
            ccwarr[i]=mainarr[((cur2-1)==0)?n:cur2-1];
            if(cur2==e){
                deshere2=i;
            }
            cur2--;
            if(cur2<1)cur2=n;
        }
        cwminarr[1]=0;
        int minidx=-1;
        LLI minval=MXX;
        for(int i=2;i<=n;++i){
            cwminarr[i]=cwminarr[i-1]+cwarr[i-1];
            if(cwminarr[i]<minval){
                minval=cwminarr[i];
                minidx=i;
            }
        }
        cwminarr[1]=cwminarr[n]+cwarr[n];
        if(cwminarr[1]<minval){
            minval=cwminarr[1];
            minidx=1;
        }
        ccwminarr[1]=0;
        int minidx2=-1;
        LLI minval2=MXX;
        for(int i=2;i<=n;++i){
            ccwminarr[i]=ccwminarr[i-1]+ccwarr[i-1];
            if(ccwminarr[i]<minval2){
                minval2=ccwminarr[i];
                minidx2=i;
            }
        }
        ccwminarr[1]=ccwminarr[n]+ccwarr[n];
        if(ccwminarr[1]<minval){
            minval2=ccwminarr[1];
            minidx2=1;
        }
        //clockwise calculation
     /*   cout<<deshere<<" "<<deshere2<<"\n";
        for(int i=1;i<=n;++i){
            cout<<cwminarr[i]<<" ";
        }
        cout<<"\n";
        for(int i=1;i<=n;++i){
            cout<<ccwminarr[i]<<" ";
        }
        cout<<"\n";*/
        globalmin=cwminarr[deshere]; //clockwise direct gelam //wherever it is
        globalmin=min(globalmin,cwminarr[1]+cwminarr[deshere]);
        if(deshere<=minidx || minidx==1){
            LLI mintoend=cwminarr[minidx]-cwminarr[deshere];
            globalmin=min(globalmin,cwminarr[minidx]+mintoend);
        }
        else if(deshere>minidx){
            globalmin=min(globalmin,2*cwminarr[minidx]+ccwminarr[deshere2]);
        }
        //anti clockwise calculation
        globalmin=min(globalmin,ccwminarr[deshere2]); //clockwise direct gelam //wherever it is
        globalmin=min(globalmin,ccwminarr[1]+ccwminarr[deshere]);
        if(deshere2<=minidx2 || minidx2==1){
            LLI mintoend=ccwminarr[minidx2]-ccwminarr[deshere2];
            globalmin=min(globalmin,ccwminarr[minidx2]+mintoend);
        }
        else if(deshere2>minidx2){
            globalmin=min(globalmin,2*ccwminarr[minidx2]+cwminarr[deshere]);
        }
        cout<<globalmin<<"\n";
    }
    return 0;
}
