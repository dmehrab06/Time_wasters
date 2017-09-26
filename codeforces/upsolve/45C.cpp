#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

struct dancer{
    int x;
    int y;
    int dif;
    dancer(){
        x=0;
        y=0;
        dif=0;
    }
    dancer(int a, int b, int w){
        x=a;
        y=b;
        dif=w;
    }
};

bool operator<(const dancer& a, const dancer& b) {
  if(a.dif==b.dif){
        return a.x>b.x;
    }
    return a.dif>b.dif;
}
int nxt[200005];
int prv[200005];
char line[200005];
int skill[200005];
int danced[200005];
vector<int>ansx;
vector<int>ansy;
priority_queue<dancer>all;
int main(){
    int N;
    scanf("%d",&N);
    scanf("%s",line);
    for(int i=N-1;i>=0;--i){
        line[i+1]=line[i];
    }
    for(int i=1;i<=N;++i){
        scanf("%d",&skill[i]);
        prv[i]=i-1;
        nxt[i]=i+1;
        danced[i]=0;
    }
    for(int i=1;i<N;++i){
        if(line[i]!=line[i+1]){
            dancer dd(i,i+1,abs(skill[i]-skill[i+1]));
            all.push(dd);
        }
    }
    while(!all.empty()){
        dancer nw=all.top();
        all.pop();
        if(danced[nw.x] || danced[nw.y])continue;
        ansx.push_back(nw.x);
        ansy.push_back(nw.y);
        danced[nw.x]=1;
        danced[nw.y]=1;
        int potentialx=prv[nw.x];
        int potentialy=nxt[nw.y];
        if(potentialx>=1)nxt[potentialx]=potentialy;
        if(potentialy<=N)prv[potentialy]=potentialx;
        if(line[potentialx]!=line[potentialy] && potentialx>=1 && potentialy<=N){
            dancer nn(potentialx,potentialy,abs(skill[potentialx]));
            all.push(nn);
        }
    }
    int l=ansx.size();
    cout<<l<<"\n";
    for(int i=0;i<l;++i){
        printf("%d %d\n",ansx[i],ansy[i]);
    }
    return 0;
}
