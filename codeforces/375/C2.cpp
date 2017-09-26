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
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int arr[2005];
int newarr[2005];
int cnt[2005];
int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,m){
        cnt[i]=0;
    }
    FREP(i,1,n){
        int b;
        scanf("%d",&b);
        arr[i]=b;
    }

    int ansmin=(n/m);
    int ansmax=ansmin+((n%m)?1:0);
    int chg=0;
    vector<int>fakaplace;
    FREP(i,1,n){
        int cur=arr[i];
        if((cur<=m) && cnt[cur]>=ansmin){
            newarr[i]=-1; //means faka;
            chg++;
            fakaplace.push_back(i);
            continue;
        }
        else if(cur>m){
           newarr[i]=-1;
            fakaplace.push_back(i);
            chg++;
            continue;
        }
        newarr[i]=cur;
        cnt[cur]++;
    }
    int p=fakaplace.size()-1;
    FREP(i,1,m){
        int cur=i;
        while(cnt[cur]<ansmin){
            int curfaka=fakaplace[p];
            newarr[curfaka]=cur;
            cnt[cur]++;
            p--;
        }
    }
    FREP(i,1,n){
        if(newarr[i]==-1){
            newarr[i]=arr[i];
            chg--;
        }
    }
    cout<<ansmin<<" "<<chg<<"\n";
    FREP(i,1,n){
        cout<<newarr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
