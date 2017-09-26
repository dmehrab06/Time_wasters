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

struct node{
    int deg;
    int id;
};

bool cmp(node a, node b){
    if(a.deg==b.deg)return a.id<b.id;
    return a.deg>b.deg;
}

int gr[5003][5003];

node seq[5005];
node tmp[5005];
int gcd(int a, int b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int gg(int n){
    int g=gcd(seq[1].deg,seq[2].deg);
    FREP(i,3,n){
        g=gcd(g,seq[3].deg);
    }
    return g;
}

int main(){
    memset(gr,0,sizeof(gr));
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int d;
        scanf("%d",&d);
        node nd;
        nd.deg=d;
        nd.id=i;
        seq[i]=nd;
        tmp[i]=nd;
    }
    int gc=gg(n);
    FREP(i,1,n){
        tmp[i].deg/=gc;
    }
    sort(seq+1,seq+1+n,cmp);
    int flag=true;
    if(n==1){
        printf("No\n");
        return 0;
    }
    while(true){
      /* FREP(i,1,n){
            cout<<seq[i].id<<" "<<seq[i].deg<<"\n";
        }*/
        int curdeg=seq[1].deg;
        if(curdeg==0)break;
        int lftdeg=curdeg;
        int ase=(n-1);
        RFREP(i,n,2){
            int bonton=lftdeg/ase;
          //  cout<<bonton<<"\n";
           // if(bonton>1)bonton--;
            int give=min(seq[i].deg,bonton);
            gr[seq[1].id][seq[i].id]+=give;
            gr[seq[i].id][seq[1].id]+=give;
            seq[1].deg-=give;
            seq[i].deg-=give;
            lftdeg-=give;
            ase--;
        }while(true){
      /* FREP(i,1,n){
            cout<<seq[i].id<<" "<<seq[i].deg<<"\n";
        }*/
        int curdeg=seq[1].deg;
        if(curdeg==0)break;
        int lftdeg=curdeg;
        int ase=(n-1);
        RFREP(i,n,2){
            int bonton=lftdeg/ase;
          //  cout<<bonton<<"\n";
           // if(bonton>1)bonton--;
            int give=min(seq[i].deg,bonton);
            gr[seq[1].id][seq[i].id]+=give;
            gr[seq[i].id][seq[1].id]+=give;
            seq[1].deg-=give;
            seq[i].deg-=give;
            lftdeg-=give;
            ase--;
        }
        //seq[1].deg=0;
        if(seq[1].deg!=0){
            flag=false;
            break;
        }
        sort(seq+1,seq+1+n,cmp);
    }
        //seq[1].deg=0;
        if(seq[1].deg!=0){
            flag=false;
            break;
        }
        sort(seq+1,seq+1+n,cmp);
    }
    if(flag==false){
        flag=true;
        memset(gr,0,sizeof(gr));
        FREP(i,1,n){
            seq[i]=tmp[i];
        }
        sort(seq+1,seq+1+n,cmp);
        while(true){
          /* FREP(i,1,n){
                cout<<seq[i].id<<" "<<seq[i].deg<<"\n";
            }*/
            int curdeg=seq[1].deg;
            if(curdeg==0)break;
            int lftdeg=curdeg;
            int ase=(n-1);
            RFREP(i,n,2){
                int bonton=lftdeg/ase;
              //  cout<<bonton<<"\n";
               // if(bonton>1)bonton--;
                int give=min(seq[i].deg,bonton);
                gr[seq[1].id][seq[i].id]+=give;
                gr[seq[i].id][seq[1].id]+=give;
                seq[1].deg-=give;
                seq[i].deg-=give;
                lftdeg-=give;
                ase--;
            }
            //seq[1].deg=0;
            if(seq[1].deg!=0){
                flag=false;
                break;
            }
            sort(seq+1,seq+1+n,cmp);
        }
        if(flag){
            printf("Yes\n");
            FREP(i,1,(n-1)){
                FREP(j,(i+1),n){
                    if(j>(i+1))printf(" ");
                    printf("%d",gr[i][j]*gc);
                }
                printf("\n");
            }
        }
        else printf("No\n");
    }
    else{
        printf("Yes\n");
        FREP(i,1,(n-1)){
            FREP(j,(i+1),n){
                if(j>(i+1))printf(" ");
                printf("%d",gr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

