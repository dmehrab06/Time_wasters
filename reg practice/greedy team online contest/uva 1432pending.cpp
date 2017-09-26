#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 2000000005
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
using namespace std;

vector<double>wide;
vector<double>height;

bool checkacross(double cut){
    vector<double>donemn;
    vector<double>donemx;
    sort(wide.begin(),wide.end());
    donemn.push_back(0.0);
    donemx.push_back(0.0);
    int l=wide.size()-1;
    //int f=1;
    FREP(i,0,l){
        donemn.push_back(max(0.0,wide[i]-cut));
        donemx.push_back(min(75.0,wide[i]+cut));
        if(donemn[i+1]>donemx[i]){
            return false;
        }
    }
    if(donemx[l+1]<75.0)return false;
    return true;
}

bool checkupdown(double cut){
    vector<double>donemn;
    vector<double>donemx;
    sort(height.begin(),height.end());
    donemn.push_back(0.0);
    donemx.push_back(0.0);
    int l=height.size()-1;
    //int f=1;
    FREP(i,0,l){
        donemn.push_back(max(0.0,height[i]-cut));
        donemx.push_back(min(100.0,height[i]+cut));
        if(donemn[i+1]>donemx[i]){
            return false;
        }
    }
    if(donemx[l+1]<100.0)return false;
    return true;
}

int main(){
    int nx,ny;
    double cut;
    while(scanf("%d %d %lf",&nx,&ny,&cut)==3){
        if(nx==0 && ny==0)break;
        wide.clear();
        height.clear();
        FREP(i,1,nx){
            double a;
            scanf("%lf",&a);
            wide.push_back(a);
        }
        FREP(i,1,ny){
            double a;
            scanf("%lf",&a);
            height.push_back(a);
        }
        if(checkacross(cut/(2.0)) && checkupdown(cut/(2.0))){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
