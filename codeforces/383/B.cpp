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

map<int,VI>positions;

int binsearch(int val, int pos){
    int l=positions[val].size();
    FREP(i,0,(l-1))cout<<positions[val][i]<<" ";
    cout<<"\n";
    if(l==0 || positions[val][l-1]<=pos)return 0;
    if(positions[val][0]>pos)return l;
    int ll=0;
    int hh=l-1;
    while(true){
        int mid=(ll+hh)/2;
        if(positions[val][mid]<=pos){
            ll=mid+1;
        }
        else{
            if((mid>0) && positions[val][mid-1]>pos){
                hh=mid;
            }
            else{
                return (l-mid);
            }
        }
    }
    return -1;
}

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        positions[a].PB(i);
        arr[i]=a;
    }
    int tot=0;
    FREP(i,1,n){
        int cur=arr[i];
        int xx=cur^x;
        tot+=binsearch(xx,i);
    }
    cout<<tot<<"\n";
}
