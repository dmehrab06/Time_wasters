#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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

vector< vector <PII> >circlepoints;

void init(){
    vector<PII>line;
    FREP(i,1,60){
        circlepoints.PB(line);
    }
}

double dis(PII a){
    return sqrt((double)a.first*a.first+a.second*a.second);
}

void create(int radi){
    if(radi==0){
        circlepoints[radi].PB(make_pair(0,0));
        return;
    }
    FREP(x,(-radi),radi){
        FREP(y,(-radi),radi){
            double dd=dis(make_pair(x,y));
            if(dd<=(double)radi && dd>(double)(radi-1)){
                circlepoints[radi].PB(make_pair(x,y));
            }
        }
    }
}

void print(int rad){
    int d=circlepoints[rad].size();
    FREP(i,0,(d-1)){
        cout<<circlepoints[rad][i].first<<" "<<circlepoints[rad][i].second<<"\n";
    }
    cout<<"\n";
}

char grid[61][61];

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,0,(n-1)){
        scanf("%s",grid[i]);
    }
    init();
    FREP(i,0,55){
        create(i);
    }
    /*FREP(i,0,9){
        print(i);
        cout<<"\n\n";
    }*/
    int maxradii=-1;
    FREP(i,0,n-1){
        FREP(j,0,(n-1)){
            if(grid[i][j]=='.'){
                int curmax=0;
                FREP(k,1,50){
                    int d=circlepoints[k].size();
                    int can=1;
                    FREP(m,0,(d-1)){
                        int x=i+circlepoints[k][m].first;
                        int y=j+circlepoints[k][m].second;
                        if(!VALID(x,y,n,n) || grid[x][y]!='.'){
                            can=0;
                            break;
                        }
                    }
                    if(!can){
                        break;
                    }
                    else{
                        curmax=k;
                    }
                }
                maxradii=max(maxradii,curmax);
            }

        }
    }
    cout<<maxradii<<"\n";
    return 0;
}
