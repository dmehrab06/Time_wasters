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
using namespace std;

vector<int>sides;

int getmax(int cur){
    if(cur==0){
        return max(sides[1],sides[2]);
    }
    if(cur==1){
        return max(sides[0],sides[2]);
    }
    return max(sides[0],sides[1]);
}

int getmin(int cur){
    if(cur==0){
        return min(sides[1],sides[2]);
    }
    if(cur==1){
        return min(sides[0],sides[2]);
    }
    return min(sides[0],sides[1]);
}

bool valid(int y){
    FREP(i,0,2){
        if(sides[i]!=y)return false;
    }
    return true;
}

int main(){
    int sec=0;
    int i=0;
    int x,y;
    scanf("%d %d",&x,&y);
    sides.PB(x);
    sides.PB(x);
    sides.PB(x);
    while(true){
        if(valid(y)){
            break;
        }
        if(sides[i]==y){
            i=(i+1)%3;
            continue;
        }
        int mx=getmax(i);
        int mn=getmin(i);
        int req=mx-mn+1;
        sides[i]=max(y,req);
        cout<<i<<" "<<sides[i]<<"\n";
        i=(i+1)%3;
        sec++;
    }
    printf("%d\n",sec);
    return 0;
}
