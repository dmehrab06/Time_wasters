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
#define ff first
#define ss second
#define pi acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char perm[6][4]={"123","132","213","231","312","321"};

PII orig[6];
PII mapped[6];

bool scaletranslatevalid(PII tmp[], PII tmpmap[]){
   // cout<<"scale then translate\n";
    int f1=0;
    FREP(sx,-5000,5000){
        if(f1){
            break;
        }
        if(sx==0)continue;
        int a=tmpmap[1].ff-tmp[1].ff*sx;
        int fff=1;
        FREP(idx,2,3){
            int px=tmp[idx].ff*sx+a;
            if(px!=tmpmap[idx].ff){
                fff=0;
                break;
            }
        }
        if(fff){
            f1=1;
        }

    }
    int f2=0;
    FREP(sy,-5000,5000){
        if(f2){
            break;
        }
        if(sy==0)continue;
        int b=tmpmap[1].ss-tmp[1].ss*sy;
        int fff=1;
        FREP(idx,2,3){
            int py=tmp[idx].ss*sy+b;
            if(py!=tmpmap[idx].ss){
                fff=0;
                break;
            }
        }
        if(fff){
            f2=1;
        }

    }
    if(f1 && f2)return true;
    return false;
}

bool translatescalevalid(PII tmp[], PII tmpmap[]){
   // cout<<"scale then translate\n";
    int f1=0;
    FREP(sx,-5000,5000){
        if(f1){
            break;
        }
        if(sx==0)continue;
        int a=tmpmap[1].ff-tmp[1].ff*sx;
        //if((a%sx))continue;
        a/=sx;
        int fff=1;
        FREP(idx,2,3){
            int px=(tmp[idx].ff+a)*sx;
            if(px!=tmpmap[idx].ff){
                fff=0;
                break;
            }
        }
        if(fff){
            f1=1;
        }

    }
    int f2=0;
    FREP(sy,-5000,5000){
        if(f2){
            break;
        }
        if(sy==0)continue;
        int b=tmpmap[1].ss-tmp[1].ss*sy;
        //if((b%sy))continue;
        b/=sy;
        int fff=1;
        FREP(idx,2,3){
            int py=(tmp[idx].ss+b)*sy;
            if(py!=tmpmap[idx].ss){
                fff=0;
                break;
            }
        }
        if(fff){
            f2=1;
        }

    }
    if(f1 && f2)return true;
    return false;
}

PII resolve(double xx, double yy){
    double x=round(xx);
    double y=round(yy);
    return make_pair((int)x,(int)y);
}

void arrangearray(PII tmp[], PII tmpmap[], double x, double y, int idx1, int idx2, int idx3){
    double yy=y;
    double xx=x;
    double theta=atan2(yy,xx);
   // cout<<"theta now "<<(theta*180.0)/pi<<"\n";
    tmpmap[1]=mapped[idx1];
    tmpmap[2]=mapped[idx2];
    tmpmap[3]=mapped[idx3];
    FREP(pt,1,3){
        double curx=orig[pt].ff; double cury=orig[pt].ss;
        double nwx=curx*cos(theta)-cury*sin(theta);
        double nwy=curx*sin(theta)+cury*cos(theta);
        PII ret=resolve(nwx,nwy);
        tmp[pt].ff=ret.ff;
        tmp[pt].ss=ret.ss;
    }
}

int main(){
    int cs=1;
    while(scanf("%d %d %d %d %d %d",&orig[1].ff,&orig[1].ss,&orig[2].ff,&orig[2].ss,&orig[3].ff,&orig[3].ss)==6){
        int breaknow=1;
        FREP(i,1,3){
            if(orig[i].ff || orig[i].ss){
                breaknow=0;
                break;
            }
        }
        if(breaknow)break;
        FREP(i,1,3){
            scanf("%d %d",&mapped[i].ff,&mapped[i].ss);
        }
        int valid=0;
        FREP(i,0,5){
            int idx1=perm[i][0]-'0';
            int idx2=perm[i][1]-'0';
            int idx3=perm[i][2]-'0'; //map kora hoilo
           // cout<<idx1<<" "<<idx2<<" "<<idx3<<"\n";
            int validflag=0;
            //ekhon all possible rotation try korte hobe
            FREP(y,-10,10){
                PII tmp[6];
                PII tmpmap[6];
                arrangearray(tmp,tmpmap,10.0,y,idx1,idx2,idx3);
                if(scaletranslatevalid(tmp,tmpmap))validflag=1;
                if(translatescalevalid(tmp,tmpmap))validflag=1;
            }
           // cout<<"right side hoise\n";
            RFREP(x,10,-10){
                PII tmp[6];
                PII tmpmap[6];
                arrangearray(tmp,tmpmap,x,10.0,idx1,idx2,idx3);
                if(scaletranslatevalid(tmp,tmpmap))validflag=1;
                if(translatescalevalid(tmp,tmpmap))validflag=1;
            }
          //  cout<<"up side hoise\n";
            RFREP(y,10,-10){
                PII tmp[6];
                PII tmpmap[6];
                arrangearray(tmp,tmpmap,-10.0,y,idx1,idx2,idx3);
                if(scaletranslatevalid(tmp,tmpmap))validflag=1;
                if(translatescalevalid(tmp,tmpmap))validflag=1;
            }
          //  cout<<"left side hoise\n";
            FREP(x,-10,10){
                PII tmp[6];
                PII tmpmap[6];
                arrangearray(tmp,tmpmap,x,-10.0,idx1,idx2,idx3);
                if(scaletranslatevalid(tmp,tmpmap))validflag=1;
                if(translatescalevalid(tmp,tmpmap))validflag=1;
            }
           // cout<<"down side hoise\n";
            if(validflag==1){
                cout<<i<<" te map hoy\n";
                valid++;
            }
        }
        printf("Case %d: ",cs++);
        if(valid==0){
            printf("no solution\n");
        }
        else if(valid>1){
            printf("inconsistent solutions\n");
        }
        else if(valid==1){
            printf("equivalent solutions\n");
        }
    }
    return 0;
}
