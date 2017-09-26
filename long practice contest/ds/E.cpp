#include <cstdio>
#include <algorithm>
#include <vector>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define ENTER 1
#define EXIT 2
using namespace std;

struct dancer{
    int type;
    int time;
    dancer(){
        type=0;
        time=0;
    }
    dancer(int a,int b){
        type=a;
        time=b;
    }
};

bool mycompare(dancer &a, dancer &b){
    if(a.time==b.time)return a.type<b.type;
    return a.time<b.time;
}



int main(){
    int t;
    scanf("%d",&t);
    //int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        vector<dancer>all;
        for(int i=1;i<=n;++i){
            int s,e;
            scanf("%d %d",&s,&e);
            all.push_back(dancer(ENTER,s));
            all.push_back(dancer(EXIT,e));
        }
        sort(all.begin(),all.end(),mycompare);
        int cur=0;
        int mx=0;
        int ll=all.size();
        for(int i=0;i<ll;++i){
            dancer nw=all[i];
            if(nw.type==ENTER){
                cur++;
                if(cur>mx){
                    mx=cur;
                }
            }
            else if(nw.type==EXIT){
                cur--;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
