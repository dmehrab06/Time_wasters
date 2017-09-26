#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define XX first
#define YY second
using namespace std;

int vessel[100005];
int minval;
int maxval;
bool can(int d, int n, int k){
    int left=k;
    int taken=0;
    int prev=0;
    for(int i=1;i<=n;){
       // cout<<"at "<<i<<" "<<taken<<"\n";
        if((taken+vessel[i])>d){
         //   cout<<"besi hoye jabe "<<taken+vessel[i]<<"\n";
            int goback=i-1;
            if(goback==prev){
                return false;
            }
            else{
                prev=goback;
                i=goback+1;
                left--;
                taken=0;
            }
        }
        else{
            if((n-i+1)<left){
                return false;
            }
            else if((n-i+1)==left){
           //     cout<<"nite e hobe\n";
                prev=i;
                i=i+1;
                taken=0;
                left--;
            }
            else{
                taken+=vessel[i];
                i=i+1;
            }
        }
    }
    if(left!=0 || prev!=n)return false;
    return true;
}

int bs(int n, int k){
    int l=minval;
    int r=maxval;
    while(l<r){
        int mid=(l+r)/2;
       // cout<<"trying with "<<mid<<"\n";
        if(can(mid,n,k)){
         //   cout<<"parbo\n";
            if(mid==minval || !can(mid-1,n,k)){
                return mid;
            }
            else{
                r=mid;
            }
        }
        else{
           // cout<<"parbo na\n";
            l=mid+1;
        }
    }
    return l;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        vessel[0]=0;
        minval=-1;
        maxval=0;
        FREP(i,1,n){
           // int a;
            scanf("%d",&vessel[i]);
            minval=max(minval,vessel[i]);
            maxval+=vessel[i];
        }
      //  FREP(i,0,n)cout<<vessel[i]<<" ";
      //  cout<<"\n";
        int val=bs(n,k);
        printf("Case %d: %d\n",cs++,val);

    }
    return 0;
}
