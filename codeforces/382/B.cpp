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
int main(){
    int n,n1,n2;
    scanf("%d %d %d",&n,&n1,&n2);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    FREP(i,1,n){
        arr[i]=-arr[i];
    }
    sort(arr+1,arr+1+n);
    FREP(i,1,n){
        arr[i]=-arr[i];
    }
    LLI s1=0,s2=0;
    int mm=min(n1,n2);
    int mx=max(n1,n2);
    FREP(i,1,mm){
        s1+=arr[i];
    }
    FREP(i,(mm+1),(n1+n2)){
        s2+=arr[i];
    }

    double avg1=(double)s1/(double)mm+(double)s2/(double)mx;
   // double avg2=(double)t2/(double)(max(n1,n2))+(double)t1/(double)mm;
    printf("%.7lf\n",avg1);

    return 0;
}
