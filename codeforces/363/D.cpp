#include <bits/stdc++.h>
#define MXX 1000000007
using namespace std;

int representative[200005];
bool ispar[200005];
bool madecycle[200005];
bool hascycle[200005];
int responsible[200005];
int findrep(int a){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
}

void init(){
    for(int i=0;i<200005;++i){
        representative[i]=i;
        ispar[i]=false;
        hascycle[i]=false;
        madecycle[i]=false;
        responsible[i]=-1;
    }
}
int trasharray[200005];
int originalarray[200005];
void printtrash(int n){
    for(int i=1;i<=n;++i){
        printf("%d ",trasharray[i]);
    }
    printf("\n");
}
int main(){
    int n;
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        trasharray[i]=a;
        originalarray[i]=a;
        if(a!=i){
            int up=findrep(a);
            int vp=findrep(i);
            if(up==vp){
                madecycle[i]=true;
            }
            else{
                unionfind(a,i);
            }
        }
    }
    set<int>components;
    for(int i=1;i<=n;++i){
        findrep(i);
    }
    for(int i=1;i<=n;++i){
        components.insert(representative[i]);
        if(representative[i]==i)ispar[i]=true;
    }
    for(int i=1;i<=n;++i){
        if(madecycle[i]==true){
            hascycle[representative[i]]=true;
            responsible[representative[i]]=i;
        }
    }
    int nocyclepar=-1;
    for(int i=1;i<=n;++i){
        if(ispar[i]==true && hascycle[i]==false){
            nocyclepar=i;
            break;
        }
    }
    int comps=components.size();
    set<int>::iterator it;
    it=components.begin();
    int firstpar=*it;
    if(comps==1){
        int onlypar=*it;
        if(hascycle[onlypar]){
            int rsp=responsible[onlypar];
            trasharray[rsp]=rsp;
            cout<<"1\n";
            printtrash(n);
        }
        else{
            cout<<"0\n";
            printtrash(n);
        }
    }
    else{
        int changed=0;
        if(nocyclepar==-1){
            trasharray[responsible[firstpar]]=responsible[firstpar];
            nocyclepar=firstpar;
            changed++;
        }
        for(it=components.begin();it!=components.end();++it){
            int curparent=*it;
            if(hascycle[curparent]){
                trasharray[responsible[curparent]]=nocyclepar;
            }
            else{
                if(curparent==nocyclepar){
                    continue;
                }
                else{
                    trasharray[curparent]=nocyclepar;
                }
            }
        }
        cout<<changed<<"\n";
        printtrash(n);
    }
    return 0;
}
