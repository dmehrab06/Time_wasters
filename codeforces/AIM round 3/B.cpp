#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000000000009
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define FREV(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define PB push_back
using namespace std;
//char str[100006];
vector<LLI>lt;
vector<LLI>rt;
int main(){
    int n, start;
    cin>>n>>start;
    FREP(i,1,n){
        int chkp;
        scanf("%d",&chkp);
        if(chkp>=start){
            rt.PB(chkp);
        }
        else{
            lt.PB(chkp);
        }
    }
    sort(lt.begin(),lt.end());
    sort(rt.begin(),rt.end());
    int lsize=lt.size();
    int rsize=rt.size();
    FREV(i,(lsize-1),0){
        lt[i]=start-lt[i];
    }
    FREP(i,0,(rsize-1)){
        rt[i]=rt[i]-start;
    }
    int lvisit=n-1;
    int rvisit=0;
    LLI ans=MXX;
    while(lvisit>=0){
        if(lvisit>lsize || rvisit>rsize){
            lvisit--;
            rvisit++;
            continue;
        }
        LLI ldis,rdis;
        if(lvisit==0){
            ldis=0;
        }
        else{
            ldis=lt[(lsize-1)-(lvisit-1)];
        }
        if(rvisit==0){
            rdis=0;
        }
        else{
            rdis=rt[rvisit-1];
        }
        LLI dis1=2*ldis+rdis;
        LLI dis2=2*rdis+ldis;
        ans=min(ans,min(dis1,dis2));
        lvisit--;
        rvisit++;
    }
    cout<<ans<<"\n";
    return 0;
}
