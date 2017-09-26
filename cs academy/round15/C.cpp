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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

stack<PII>lett;

int stacksize=0;
char str[100005];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    scanf("%s",str);
    FREP(i,0,(n-1)){
        int cur=str[i];
        if(stacksize==0){
            PII oka=make_pair(cur,1);
            lett.push(oka);
            stacksize++;
        }
        else{
            PII tp=lett.top();
            int toplet=tp.first;
            int freq=tp.second;
            if(toplet==cur){
                lett.pop();
                tp.second=freq+1;
                lett.push(tp);
            }
            else{
                PII oka=make_pair(cur,1);
                lett.push(oka);
                stacksize++;
            }
        }
        if(stacksize>0){
            PII tp=lett.top();
            int freq=tp.second;
            tp.second=freq%k;
            if(tp.second==0){
                lett.pop();
                stacksize--;
            }
            else{
                lett.pop();
                lett.push(tp);
            }
        }
    }
    string res="";
    while(stacksize){
        PII tp=lett.top();
        lett.pop();
        stacksize--;
        FREP(i,1,tp.second){
            res.PB(tp.first);
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
}
