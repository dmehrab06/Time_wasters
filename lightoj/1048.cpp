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

int camppos[100005];

bool can(int d, int n, int k){
    int prev=0;
    int left=k;
    for(int i=1;i<=n;){
        if((camppos[i]-prev)>d){
            int goback=i-1;
            if(camppos[goback]==prev){
                return false;
            }
            else{
                prev=camppos[goback];
                i=goback+1;
                left--;
            }
        }
        else{
            if((n-i+1)<left){
                return false;
            }
            else if((n-i+1)==left){
                prev=camppos[i];
                i=i+1;
                left--;
            }
            else{
                i=i+1;
            }
        }
    }
    if(left!=0)return false;
    if((camppos[n+1]-prev)>d){
        return false;
    }
    return true;
}

int ans[100005];

int sim(int d, int n, int k){
    int ii=1;
    int prev=0;
    int left=k;
    ans[0]=0;
    for(int i=1;i<=n;){
        if((camppos[i]-prev)>d){
            int goback=i-1;
            prev=camppos[goback];
            ans[ii++]=prev;
            i=goback+1;
            left--;
        }
        else{

            if((n-i+1)==left){
                prev=camppos[i];
                ans[ii++]=prev;
                i=i+1;
                left--;
            }
            else{
                i=i+1;
            }
        }
    }

    ans[ii]=camppos[n+1];
    return ii;
}

int bs(int n, int k){
    int l=0;
    int r=camppos[n+1]+11;
    while(true){
        int mid=(l+r)/2;
        cout<<"trying with "<<mid<<"\n";
        if(can(mid,n,k)){
            cout<<"parbo\n";
            if(mid==0 || !can(mid-1,n,k)){
                return mid;
            }
            else{
                r=mid;
            }
        }
        else{
            cout<<"parbo na\n";
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
        camppos[0]=0;
        FREP(i,1,n+1){
            int a;
            scanf("%d",&a);
            camppos[i]=camppos[i-1]+a;
        }
        FREP(i,0,n+1)cout<<camppos[i]<<" ";
        cout<<"\n";
        int val=bs(n,k);
        int sz=sim(val,n,k);
        printf("Case %d: %d\n",cs++,val);
        FREP(i,1,sz){
            printf("%d\n",ans[i]-ans[i-1]);
        }
    }
}
