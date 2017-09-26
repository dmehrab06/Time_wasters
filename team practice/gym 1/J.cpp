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

ifstream fin("journey.in");
ofstream fout("journey.out");

multiset<LLI>tryset;
multiset<LLI>::iterator it;
LLI tim[50003];
LLI d[50003];
LLI p[50003];
bool can(int range, int n, int t){
    tryset.clear();
    tim[1]=0;
    tryset.insert(tim[1]);
    FREP(i,2,(1+range)){
        tim[i]=d[i];
        tryset.insert(tim[i]);
    }

    FREP(i,(range+2),n){
        //out of range delete
        int out=i-(range+1);
        tryset.erase(tryset.find(tim[out]));
        it=tryset.begin();
        LLI mintime=*it;
        tim[i]=mintime+d[i];
        tryset.insert(tim[i]);
    }
    return (tim[n]<=t);
}

int main(){
    int n,t;
    fin>>n>>t;
    t=t-(n-1);
    FREP(i,1,(n-1))fin>>p[i];
    FREP(i,2,(n-1))fin>>d[i];
    int l=1;
    int r=(n-1);
    while(l<r){
        int mid=(l+r)/2;
        if(can(mid,n,t)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    LLI ans=p[l];
    FREP(i,l,(n-1)){
        if(p[i]<ans)ans=p[i];
    }
    fout<<ans<<"\n";
    fin.close();
    fout.close();
    return 0;
}
