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
priority_queue< PII > members;
priority_queue< PII > dp[10005][4];
map<int,int> dp2[10005][4];
map<int,int>ratfrq;
int main(){
    int n;
    scanf("%d",&n);
    //int val;
    FREP(i,1,n){
        int rat;
        scanf("%d",&rat);
        PII my=make_pair(rat,i);
        members.push(my);
        ratfrq[rat]++;
       // val=rat;
    }
    dp[0][2]=members;
    dp[0][3]=members;
    dp2[0][2]=ratfrq;
    dp2[0][3]=ratfrq;
    int cur=0;
    int f=0;
    int R=-1;
    int anscur=-1;
    int mv=-1;
    while(true){
        if(cur>10000)break;
        cout<<cur<<" ekhon\n";
        for(int i=2;i<=3;++i){
            if(i==3 && (cur==0 || n<=2))continue;
            members=dp[cur][i];
            ratfrq=dp2[cur][i];
            cout<<"paisi\n";
            PII p1=members.top();
            members.pop();
            PII p2=members.top();
            members.pop();
            PII p3;
            if(n>2)p3=members.top();
            members.pop();
            if(ratfrq[p1.first]==n){
                R=p1.first;
                anscur=cur;
                mv=i;
                f=1;
                break;
            }
            priority_queue<PII>nxt2=members;
            map<int,int>nxt22=ratfrq;
            if(p1.first>0){nxt22[p1.first]--;nxt22[p1.first-1]++;}
            if(p2.first>0){nxt22[p2.first]--;nxt22[p2.first-1]++;}
            nxt2.push(p3);
            if(p2.first>0)p2.first--;if(p1.first>0)p1.first--;
            nxt2.push(p1);nxt2.push(p2);
            dp[cur+1][2]=nxt2;dp2[cur+1][2]=nxt22;
            if(n>2){
                if(p3.first>0)nxt22[p3.first]--;
                if(p3.first>0)nxt22[p3.first-1]++;
                dp2[cur+1][3]=nxt22;
                priority_queue<PII>nxt3=members;
                if(p3.first>0)p3.first--;
                nxt3.push(p1);nxt3.push(p2);nxt3.push(p3);
                dp[cur+1][3]=nxt3;
            }
        }
        cur++;
        if(f){
            break;
        }

    }
    cout<<R<<" "<<anscur<<" "<<mv<<"\n";
    return 0;
}
