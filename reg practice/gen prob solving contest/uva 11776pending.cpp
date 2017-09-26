#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
#define MNN -MXX
#define DBL double
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
using namespace std;
//start 1
//end 2
struct job{
    int t;
    int type;
    int jobno;
    job(int _a=0, int _b=0, int _c=0){
        t=_a;
        type=_b;
        jobno=_c;
    }
};

bool cmp(job &a, job &b){
    if(a.t==b.t){
        if(a.type==b.type)return a.jobno<b.jobno;
        return a.type<b.type;
    }
    return a.t<b.t;
}

job all[5001];
int cmplt[5001];

void init(int N){
    FREP(i,1,N){
        cmplt[i]=0;
    }
}
int main(){
    //int t;
    int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N!=-1){
        //stack<int>going;
        FREP(i,1,N){
            int s,e;
            init(N);
            scanf("%d %d",&s,&e);
            job a(s,1,i);
            job b(e,2,i);
            all[(2*i)-1]=a;
            all[2*i]=b;
        }
        sort(all+1,all+1+(2*N),cmp);
        int enf=0;
        int cur=0;
        FREP(i,1,(2*N)){
            int curtype=all[i].type;
            //int curtime=all[i].t;
          //  int curno=all[i].jobno;
            if(curtype==1){
              //  going.push(curno);
              cur++;
              enf=max(cur,enf);
            }
            else if(curtype==2){

                cur--;
                //enf=max(enf,sz);

            }
        }
        printf("Case %d: %d\n",cs++,enf);
    }
    //int cs=1;
    return 0;
}
