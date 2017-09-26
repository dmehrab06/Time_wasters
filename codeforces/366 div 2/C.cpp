#include <bits/stdc++.h>
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=N && (Y)>=1 && (Y)<=(M))
using namespace std;

vector<int>notievent;
int notis[300005];
int lastread[300005];
int lastunread[300005];
int total=0;

void init(){
    for(int i=0;i<300005;++i){
        notis[i]=0;
        lastread[i]=-1;
        lastunread[i]=-1;
    }
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int idx=1;
    int maxquery3found=0;
    notievent.push_back(-1);
    for(int i=1;i<=q;++i){
        int type;
        scanf("%d",&type);
        if(type==1){
            int app;
            scanf("%d",&app);
            lastunread[app]=idx;
            notis[app]++;
            idx++;
            total++;
            notievent.push_back(app);
            printf("%d\n",total);
        }
        else if(type==2){
            int app;
            scanf("%d",&app);
            if(lastunread[app]!=-1)lastread[app]=lastunread[app];
            lastunread[app]=-1;
            total-=notis[app];
            notis[app]=0;
            printf("%d\n",total);
        }
        else if(type==3){
            int ti;
            scanf("%d",&ti);
            if(ti<=maxquery3found){
                //kissu kormu na
            }
            else{
                for(int k=maxquery3found+1;k<=ti;++k){
                    int cur=notievent[k];
                    if(lastread[cur]>=k){
                        //laav hoy nai kuno
                    }
                    else{
                        lastread[cur]=k;
                        total--;
                        notis[cur]--;
                        if(lastread[cur]==lastunread[cur]){
                            lastunread[cur]=-1;
                        }
                    }
                }
                maxquery3found=ti;
                printf("%d\n",total);
            }
        }
    }
    return 0;
}
