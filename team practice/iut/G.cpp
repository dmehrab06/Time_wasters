/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('1'<=(a) && (a)<='9')
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

int dx[5]={-1,-1,0,1,1};
int dy[5]={-1,1,2,1,-1};

map<PII,int>m1;
map<int,PII>m2;

int main(){
    PII first=make_pair(0,0);
    m1[first]=1;
    m2[1]=first;
    int nxt=2;
    queue<int>bfsq;
    bfsq.push(1);
    while(true){
        int cur=bfsq.front();
        bfsq.pop();
        if(cur>10000){
            break;
        }
        if(cur%2){
            int curx=m2[cur].first;
            int cury=m2[cur].second;
            FREP(i,1,3){
                int nxtx=curx+dx[i];
                int nxty=cury+dy[i];
                PII nxtp=make_pair(nxtx,nxty);
                if(m1.find(nxtp)!=m1.end()){
                    continue;
                }
                else{
                    m1[nxtp]=nxt;
                    m2[nxt]=nxtp;
                    bfsq.push(nxt);
                    //cout<<cur<<" added "<<nxt<<"\n";
                    nxt++;
                }
            }
        }
        else{
            int curx=m2[cur].first;
            int cury=m2[cur].second;
            FREP(i,0,4){
                int nxtx=curx+dx[i];
                int nxty=cury+dy[i];
                PII nxtp=make_pair(nxtx,nxty);
                if(m1.find(nxtp)!=m1.end()){
                    continue;
                }
                else{
                    m1[nxtp]=nxt;
                    m2[nxt]=nxtp;
                    bfsq.push(nxt);
                  //  cout<<cur<<" added "<<nxt<<"\n";
                    nxt++;
                }
            }
        }
    }
    int a,b;
    while(scanf("%d %d",&a,&b)==2 && !(a==0 && b==0)){
        PII p1=m2[a];
        PII p2=m2[b];
        int x1=p1.first;int x2=p2.first;int y1=p1.second;int y2=p2.second;
        //printf("%d %d %d %d\n",x1,y1,x2,y2);
        int mx=max(y1,y2);
        int mn=min(y1,y2);
        int xdif=abs(x1-x2);
        int ydif=abs(y1-y2);
        if(xdif>ydif){
            printf("%d\n",xdif);
        }
        else{
            int stp=(mx-mn)-xdif;
            stp/=2;
            printf("%d\n",stp+xdif);
        }

    }
    return 0;
}
