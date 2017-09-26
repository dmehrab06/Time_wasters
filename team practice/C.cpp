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
#define VS vector<string>
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

struct Point
{
    LLI x, y;
};

Point all[400005];
LLI cumsum[400005];
LLI totalarea=0;

void calc(int n){
    int upto=2*n-2;
    FREP(i,0,upto){
        cumsum[i]=all[i].x*all[i+1].y-all[i+1].x*all[i].y;
    }
    FREP(i,1,upto){
        cumsum[i]=cumsum[i-1]+cumsum[i];
    }
}

LLI getarea(int st, int ed){
    LLI first=all[ed].x*all[st].y-all[st].x*all[ed].y;
    LLI sec=cumsum[ed-1]-(st>0?cumsum[st-1]:0);
    LLI tot=first+sec;
    return abs(tot);
}


LLI getdif(LLI area1){
    LLI area2=totalarea-area1;
    return abs(area1-area2);
}

PLLI bs(int start, int n){
    int l=start;
    int r=(start+n);
    FREP(i,1,30){
        int mid=(l+r)/2;
        LLI curarea=getarea(start,mid);
        LLI go=getdif(curarea);
        LLI gol=getdif(getarea(start,mid-1));
        LLI gor=getdif(getarea(start,mid+1));
        if(gol>=go && gor>=go){
            LLI a=curarea;
            LLI b=totalarea-curarea;
            return make_pair(max(a,b),min(a,b));
        }
        else if(gol<go){
            r=mid;
        }
        else if(gor<go){
            l=mid;
        }
    }
    LLI a=getarea(start,l);
    LLI b=totalarea-a;
    return make_pair(max(a,b),min(a,b));
}

PLLI ans[400005];
int main()
{
    int n;
    while(scanf("%d",&n)==1){
      //  vector<PLLI>ans;
        FREP(i,0,(n-1)){
            scanf("%lld %lld",&all[i].x,&all[i].y);
            all[i+n].x=all[i].x;
            all[i+n].y=all[i].y;
        }
        calc(n);
        totalarea=getarea(0,n);
        FREP(i,0,(n-1)){
            PLLI paisi=bs(i,n);
            paisi.first=-paisi.first;
            paisi.second=-paisi.second;
            ans[i]=paisi;
        }
        sort(ans,ans+n);
        //sort(ans.begin(),ans.end());
        PLLI ok=ans[0];
        printf("%lld %lld\n",-ok.first,-ok.second);
    }
    return 0;
}
