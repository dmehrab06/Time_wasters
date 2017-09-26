#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
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
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000
using namespace std;

int main(){
    int n;
    set<int>all;
    cin>>n;
    FREP(i,1,n){
        int x;
        scanf("%d",&x);
        all.insert(x);
    }
    if(all.size()<=2){
        printf("YES\n");
    }
    if(all.size()==3){
        set<int>::iterator it;
        VI my;
        for(it=all.begin();it!=all.end();++it){
            my.PB(*it);
        }
        if((my[1]-my[0])==(my[2]-my[1]))printf("YES\n");
        else{
            printf("NO\n");
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}
