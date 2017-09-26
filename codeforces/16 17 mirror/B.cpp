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

int mnsize[53];
int mxsize[53];
char rspns[3];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        FREP(i,1,n)mnsize[i]=i;
        if(n==1){
            cout<<"! 1 1\n";
            flush(cout);
            continue;
        }
        int MINID,MAXID;
        int curmnsize=n;
        int curmxsize=0;
        int mxpushed=0;
        while(curmnsize>1){
            for(int i=1;i<=curmnsize;i+=2){
                if((i+1)<=curmnsize){
                    int first=mnsize[i];
                    int second=mnsize[i+1];
                    cout<<"? "<<first<<" "<<second<<"\n";
                    flush(cout);
                    scanf("%s",rspns);
                    if(rspns[0]=='<' || rspns[0]=='='){
                        mnsize[(i+1)/2]=first;
                        if(!mxpushed){
                            mxsize[(i+1)/2]=second;
                            curmxsize++;
                        }
                    }
                    else if(rspns[0]=='>'){
                        mnsize[(i+1)/2]=second;
                        if(!mxpushed){
                            mxsize[(i+1)/2]=first;
                            curmxsize++;
                        }
                    }
                }
                else{
                    mnsize[(i+1)/2]=mnsize[i];
                    if(!mxpushed){
                        mxsize[(i+1)/2]=mnsize[i];
                        curmxsize++;
                    }
                }
            }
            mxpushed=1;
            curmnsize=curmnsize/2+curmnsize%2;
        }
        MINID=mnsize[1];
        while(curmxsize>1){
            for(int i=1;i<=curmxsize;i+=2){
                if((i+1)<=curmxsize){
                    int first=mxsize[i];
                    int second=mxsize[i+1];
                    cout<<"? "<<first<<" "<<second<<"\n";
                    flush(cout);
                    scanf("%s",rspns);
                    if(rspns[0]=='<' || rspns[0]=='='){
                        mxsize[(i+1)/2]=second;
                    }
                    else if(rspns[0]=='>'){
                        mxsize[(i+1)/2]=first;
                    }
                }
                else{
                    mxsize[(i+1)/2]=mxsize[i];
                }
            }
            curmxsize=curmxsize/2+curmxsize%2;
        }
        MAXID=mxsize[1];
        cout<<"! "<<MINID<<" "<<MAXID<<"\n";
        flush(cout);
    }
    return 0;
}
