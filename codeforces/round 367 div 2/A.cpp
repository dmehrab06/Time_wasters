#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000009
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define PB push_back
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

int main(){
    double x,y;
    cin>>x>>y;
    int n;
    scanf("%d",&n);
    double mn=-1.0;
    FREP(i,1,n){
        double vx,vy,v;
        cin>>vx>>vy>>v;
        double dis=(vx-x)*(vx-x)+(vy-y)*(vy-y);
        dis=sqrt(dis);
        double t=dis/v;
        if(mn<0 || t<mn){
            mn=t;
        }
    }
    cout<<mn<<"\n";
}
