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

int arr[50006];
vector<PII>all;
int ydone[50006];
int finaltake[50006];
int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    FREP(i,1,n){
        int cur=arr[i];
        while(cur){
            PII p=make_pair(cur,i);
            all.push_back(p);
            cur/=2;
        }
    }
    sort(all.begin(),all.end());
    FREP(i,0,(all.size()-1))cout<<all[i].first<<"\n";
    map<int,int>distinct;
    int takenfory=0;
    int dis=0;
    int sz=all.size();
    set<PII>goset;
    FREP(i,0,(sz-1)){
        if(takenfory==n && dis==n){
            printf("hoise\n");
            break;
        }
        printf("at %d ",i);
        PII cur=all[i];
        //goset.insert(cur);
        int fory=cur.second;
        int x=cur.first;
        if(distinct.find(x)==distinct.end() && ydone[fory]==0){
            dis++;
            distinct[x]=1;
            takenfory+=1;
            ydone[fory]++;
            printf("oka");
            //printf("%d ",x);
        }
        printf("\n");
    }
    printf("\n");
    set<PII>::iterator it;
    for(it=goset.begin();it!=goset.end();++it){
        PII cur=*it;
        printf("%d ",cur.first);
    }
    printf("\n");
    return 0;
}
