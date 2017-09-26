#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000001

using namespace std;

//0 0
//1 khub besi
//1 khub kom

vector< set<int> > x2y;

int main(){
    //int x,y;
    int t;
    scanf("%d",&t);
	int cs=1;
    while(t--){
        x2y.clear();
        set<int>line;

        int n;
        scanf("%d",&n);
        FREP(i,1,(n+3)){
            x2y.push_back(line);
        }
        map<int,int>compress;
        int xs=1;
        int x,y;
        vector<PII>hello;
        FREP(i,1,n){
            scanf("%d %d",&x,&y);
            PII pp=make_pair(x,y);
            hello.push_back(pp);
        }
        sort(hello.begin(),hello.end());
        FREP(i,0,(n-1)){
            //scanf("%d %d",&x,&y);
            int xx=hello[i].first;
            int yy=hello[i].second;
            int valx;
            if(compress.find(xx)==compress.end()){
                compress[xx]=xs;
                valx=xs;
                xs++;
            }
            else{
                valx=compress[xx];
            }
            x2y[valx].insert(yy);
        }
       // printf("hoise\n");
        set<int>::iterator it,jt;
        LLI res=0;
        FREP(i,1,n){
            FREP(j,(i+1),n){
                it=x2y[i].begin();
                jt=x2y[j].begin();
                int poss=0;
                while(it!=x2y[i].end() && jt!=x2y[j].end()){
                    int y1=*it;
                    int y2=*jt;
                    if(y1==y2){
                        poss++;
                        it++;
                        jt++;
                    }
                    else if(y1<y2){
                        it++;
                    }
                    else{
                        jt++;
                    }
                }
                LLI pp=((LLI)poss*(LLI)(poss-1))/2;
                res+=pp;
            }
        }
        printf("Case %d: %lld\n",cs++,res);
    }
}
