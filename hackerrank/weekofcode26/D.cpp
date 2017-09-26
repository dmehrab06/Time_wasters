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

int arr[100005];

int oka[100005];

int cum[100005];

int binsearch(int n, int z){
    int lo=0;
    int hi=(n);
    while(true){
        int mid=(lo+hi)/2;
        if(oka[mid]<=z){
            if(mid<n && oka[mid+1]<=z){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi=mid;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    int tot,h1,h2;
    scanf("%d %d %d",&tot,&h1,&h2);
    oka[0]=arr[1]-h2;
    FREP(i,1,n){
        oka[i]=arr[i];
    }
    oka[n+1]=oka[n]+h2;
    cum[0]=0;
    FREP(i,1,(n+1)){
        if((oka[i]-oka[i-1])>=h1 && (oka[i]-oka[i-1])<=h2){
            cum[i]=0;
        }
        else{
            cum[i]=1;
        }
        cum[i]=cum[i-1]+cum[i];
    }
    int flag=0;
    int ans=111111;
    FREP(i,0,n){
        int cur=oka[i];
        int ed=cur+tot;
        int idx=binsearch(n,ed);
        int thislisten=ed-oka[idx];
        int ase=cum[idx]-cum[i];
        if(ase==0 && (thislisten==0 || (thislisten>=h1 && thislisten<=h2))){
            flag=1;
            ans=cur;
            break;
        }
    }
    if(!flag){
        FREP(i,1,n){
            int cur=oka[i]-h1;
            if(cur<oka[i-1])continue;
            int ed=cur+tot;
            int idx=binsearch(n,ed);
            if(idx>=i){
                int ase=cum[idx]-cum[i];
                if(ase==0){
                    int thislisten=ed-oka[idx];
                    if(thislisten==0 || (thislisten>=h1 && thislisten<=h2)){
                        flag=1;
                        ans=cur;
                        break;
                    }
                }
            }
        }
    }
    if(!flag){
        FREP(i,1,n){
            int cur=oka[i]-h2;
            if(cur<oka[i-1])continue;
            int ed=cur+tot;
            int idx=binsearch(n,ed);
            if(idx>=i){
                int ase=cum[idx]-cum[i];
                if(ase==0){
                    int thislisten=ed-oka[idx];
                    if(thislisten==0 || (thislisten>=h1 && thislisten<=h2)){
                        flag=1;
                        ans=cur;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
