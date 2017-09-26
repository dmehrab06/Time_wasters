/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define ULLI unsigned long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.00000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int dis[103][103];

int src[5003];
int des[5003];

LLI solve(int n, int m, int family){
    LLI total=0;
    int curnode=1;
    int curat=0; //1 means at src, 2 means at des
    int curload=0;
    int nxtsrc=1;
    int nxtdes=1;
    int nope=0;
    while(true){
        if(curat==0){
            int nxtcost=dis[curnode][src[nxtsrc]];
            if(nxtcost>=MXX){
                nope=1;
                break;
            }
            curat=1;
            curnode=src[nxtsrc];
            curload++;
            total+=nxtcost;
            cout<<"src "<<curnode<<" e gelam\n";
            cout<<"load ekhon "<<curload<<" holo\n";
            cout<<nxtcost<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
            nxtsrc++;
        }
        else if(curat==1){
            if(curload==2){
                //just go to destination man
                int nxtcost=dis[curnode][des[nxtdes]];
                if(nxtcost>=MXX){
                    nope=1;
                    break;
                }
                curat=2;
                curnode=des[nxtdes];
                curload--;
                total+=nxtcost;
                cout<<"dest "<<curnode<<" e gelam\n";
                cout<<"load ekhon "<<curload<<" holo\n";
                cout<<nxtcost<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                nxtdes++;

            }
            else if(curload==1){
                if(nxtsrc>family){
                    int nxtcost=dis[curnode][des[nxtdes]];
                    if(nxtcost>=MXX){
                        nope=1;
                        break;
                    }
                    total+=nxtcost;
                    curat=2;
                    curnode=des[nxtdes];
                    curload--;
                    cout<<"dest "<<curnode<<" e gelam\n";
                    cout<<"load ekhon "<<curload<<" holo\n";
                    cout<<nxtcost<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                    nxtdes++;
                }
                else{
                    int nxtcost1=dis[curnode][des[nxtdes]]+dis[des[nxtdes]][src[nxtsrc]];
                    int nxtcost2=dis[curnode][src[nxtsrc]]+dis[src[nxtsrc]][des[nxtdes]];
                    if(nxtcost1<nxtcost2){
                        nxtcost1=dis[curnode][des[nxtdes]];
                        if(nxtcost1>=MXX){
                            nope=1;
                            break;
                        }
                        total+=nxtcost1;
                        curat=2;
                        curnode=des[nxtdes];
                        curload--;
                        cout<<"dest "<<curnode<<" e gelam\n";
                        cout<<"load ekhon "<<curload<<" holo\n";
                        cout<<nxtcost1<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                        nxtdes++;

                    }
                    else{
                        nxtcost2=dis[curnode][src[nxtsrc]];
                        if(nxtcost2>=MXX){
                            nope=1;
                            break;
                        }
                        total+=nxtcost2;
                        curat=1;
                        curnode=src[nxtsrc];
                        curload++;
                        cout<<"src "<<curnode<<" e gelam\n";
                        cout<<"load ekhon "<<curload<<" holo\n";
                        cout<<nxtcost2<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                        nxtsrc++;
                    }
                }
            }
        }
        else if(curat==2){
            if(nxtdes>family){
                break;
            }
            if(curload==0){
                //just go to Src man
                int nxtcost=dis[curnode][src[nxtsrc]];
                if(nxtcost>=MXX){
                    nope=1;
                    break;
                }
                curat=1;
                curnode=src[nxtsrc];
                curload++;
                total+=nxtcost;
                cout<<"src "<<curnode<<" e gelam\n";
                cout<<"load ekhon "<<curload<<" holo\n";
                cout<<nxtcost<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                nxtsrc++;
            }
            else if(curload==1){
                if(nxtsrc>family){
                    int nxtcost=dis[curnode][des[nxtdes]];
                    if(nxtcost>=MXX){
                        nope=1;
                        break;
                    }
                    total+=nxtcost;
                    curat=2;
                    curnode=des[nxtdes];
                    curload--;
                    cout<<"dest "<<curnode<<" e gelam\n";
                    cout<<"load ekhon "<<curload<<" holo\n";
                    cout<<nxtcost<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                    nxtdes++;
                }
                else{
                    int nxtcost1=dis[curnode][des[nxtdes]]+dis[des[nxtdes]][src[nxtsrc]];
                    int nxtcost2=dis[curnode][src[nxtsrc]]+dis[src[nxtsrc]][des[nxtdes]];
                    if(nxtcost1<nxtcost2){
                        nxtcost1=dis[curnode][des[nxtdes]];
                        if(nxtcost1>=MXX){
                            nope=1;
                            break;
                        }
                        total+=nxtcost1;
                        curat=2;
                        curnode=des[nxtdes];
                        curload--;
                        cout<<"des "<<curnode<<" e gelam\n";
                        cout<<"load ekhon "<<curload<<" holo\n";
                        cout<<nxtcost1<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                        nxtdes++;


                    }
                    else{
                        nxtcost2=dis[curnode][src[nxtsrc]];
                        if(nxtcost2>=MXX){
                            nope=1;
                            break;
                        }
                        total+=nxtcost2;
                        curat=1;
                        curnode=src[nxtsrc];
                        curload++;
                        cout<<"src "<<curnode<<" e gelam\n";
                        cout<<"load ekhon "<<curload<<" holo\n";
                        cout<<nxtcost2<<" cost add holo. totalcost ei muhurte "<<total<<"\n";
                        nxtsrc++;
                    }
                }
            }
        }
    }
    if(nope==1){
        return -1;
    }
    return total;
}

void takeg(int n, int m, int family){

    FREP(i,1,n){
        FREP(j,1,n){
            if(i==j){
                dis[i][j]=0;
            }
            else{
                dis[i][j]=MXX;
            }
        }
    }

    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }

    FREP(i,1,family){
        scanf("%d %d",&src[i],&des[i]);
    }
}

void floyd(int n){
    FREP(k,1,n){
        FREP(i,1,n){
            FREP(j,1,n){
                if((dis[i][k]+dis[k][j])<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    FREP(i,1,n){
        FREP(j,1,n){

        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        takeg(n,m,k);
        floyd(n);
        LLI ans=solve(n,m,k);
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
