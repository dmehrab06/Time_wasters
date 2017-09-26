/*-------property of the half blood prince-----*/

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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

typedef long long int ll;

int g1[105][105];
int g2[105][105];

int arr[100005];

int vis1[100005];
int vis2[100005];
int vis3[100005];
int compsize[100005];

int sz=0;
// Utility function to find GCD of 'a' and 'b'
int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

// Returns LCM of array elements
ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];

    // ans contains LCM of arr[0],..arr[i]
    // after i'th iteration,
    for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
                (gcd(arr[i], ans)) );

    return ans;
}

vector<int>elem;

void dfs1(int cur){
    vis1[cur]=1;
    elem.PB(cur);
    //mxcmp=max(cmp,mxcmp);
    int deg=g1[cur][0];
    FREP(i,1,deg){
        int nxt=g1[cur][i];
        if(!vis1[nxt]){
            dfs1(nxt);
        }
    }
    return;
}

bool check(int cur, int sz){
    int src=cur;
    int cursz=1;
    vis3[cur]=1;
    int nxt;
    while(true){
        nxt=g2[cur][1];
        if(vis3[nxt])break;
        cursz++;
        vis3[nxt]=1;
        cur=nxt;
    }
    return sz==cursz && nxt==src;
}

// Driver Code
int main()
{
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        g1[i][++g1[i][0]]=a;
        g1[a][++g1[a][0]]=i;
        g2[i][++g2[i][0]]=a;
    }
    FREP(i,1,n){
        if(!vis1[i]){
            //mxcmp=0;
            elem.clear();
            dfs1(i);
            compsize[i]=elem.size();
        }
    }
   // printf("hoise\n");
    bool f=true;
    FREP(i,1,n){
        if(compsize[i]){
            if(check(i,compsize[i])){
                arr[sz++]=((compsize[i]%2)?(compsize[i]):(compsize[i]/2));
            }
            else{
                f=false;
                break;
            }
        }
    }
    if(!f){
        printf("-1\n");
    }
    else{
        LLI ans=findlcm(arr,sz);
        cout<<ans<<"\n";
    }
}
