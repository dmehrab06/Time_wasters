/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
#define MAX 505
string G[MAX];
int Left[MAX][MAX];
int Right[MAX][MAX];
int Up[MAX][MAX];
int Down[MAX][MAX];

//boro jhamela ache

void process(int r,int c){
    for(int rr=0;rr<r;rr++){
        for(int cc=0;cc<c;cc++){
            if(G[rr][cc]=='#') Left[rr][cc]=0;
            else Left[rr][cc]=Left[rr][cc-1]+1;
        }
    }

    for(int cc=0;cc<c;cc++){
        for(int rr=0;rr<r;rr++){
            if(G[rr][cc]=='#') Up[rr][cc]=0;
            else Up[rr][cc]=Up[rr-1][cc]+1;
        }
    }

    for(int rr=0;rr<r;rr++){
        for(int cc=c-1;cc>=0;cc--){
            if(G[rr][cc]=='#') Right[rr][cc]=0;
            else Right[rr][cc]=Right[rr][cc+1]+1;
        }
    }

    for(int cc=0;cc<c;cc++){
        for(int rr=r-1;rr>=0;rr--){
            if(G[rr][cc]=='#') Down[rr][cc]=0;
            else Down[rr][cc]=Down[rr+1][cc]+1;
        }
    }
}

ifstream fin("reduce.in");

vector < pair<string,int> > mycomms;

void init(){
    mycomms.clear();
}

void takeg(int r, int c){
    FREP(i,0,r-1)fin>>G[i];
}

string getrot(PII dir){
    if(dir.first==-1)return "U";
    if(dir.first==1)return "D";
    if(dir.second==-1)return "L";
    if(dir.second==1)return "R";
    return "BAZINGA";
}

PII getdir(string dir){
    if(dir=="U") return make_pair(-1,0);
    if(dir=="D") return make_pair(1,0);
    if(dir=="L") return make_pair(0,-1);
    if(dir=="R") return make_pair(0,1);
    return make_pair(-3213,-2131);
}

PII rot(PII curdir){
    int mul = (curdir.first)?-1:0;
    PII rr = curdir;
    swap(rr.first,rr.second);
    if(mul)rr.first *= mul;
    if(mul)rr.second *= mul;
    return rr;
}

PII soron(PII curpos, PII curdir, int x){
    return make_pair(curpos.first+x*curdir.first,curpos.second+x*curdir.second);
}

PII getnextpos(PII curpos, PII curdir, int x){
    while(x>0){
        string rott = getrot(curdir);
        int dd = 0;
        if(rott=="L")dd = Left[curpos.first][curpos.second]-1;
        if(rott=="R")dd = Right[curpos.first][curpos.second]-1;
        if(rott=="U")dd = Up[curpos.first][curpos.second]-1;
        if(rott=="D")dd = Down[curpos.first][curpos.second]-1;
        if(dd>=x)return soron(curpos,curdir,x);
        else{
            curpos = soron(curpos,curdir,dd);
            x-=dd;
            curdir = rot(curdir);
        }
    }
    return make_pair(-1,-1); //should not be
}

bool ispossible(int rotnumber, PII src, PII dest, PII curdir){
    FREP(i,1,rotnumber)curdir = rot(curdir);
    set< pair< PII, PII> >vis;
    while(true){
        PII nxt;
        if(getrot(curdir)=="L"){
            int dd = Left[src.first][src.second]-1;
            nxt = getnextpos(src,curdir,dd);
            if(dest.first==src.first && INRANGEI(dest.second,nxt.second,src.second))return true;
        }
        else if(getrot(curdir)=="R"){
            int dd = Right[src.first][src.second]-1;
            nxt = getnextpos(src,curdir,dd);
            if(dest.first==src.first && INRANGEI(dest.second,src.second,nxt.second))return true;
        }
        else if(getrot(curdir)=="D"){
            int dd = Down[src.first][src.second]-1;
            nxt = getnextpos(src,curdir,dd);
            if(dest.second==src.second && INRANGEI(dest.first,src.first,nxt.first))return true;
        }
        else{
            int dd = Up[src.first][src.second]-1;
            nxt = getnextpos(src,curdir,dd);
            if(dest.second==src.second && INRANGEI(dest.first,nxt.first,src.first))return true;
        }
        pair<PII,PII>curstate = make_pair(src,curdir);
        if(vis.find(curstate)!=vis.end())return false;
        vis.insert(curstate);
        curdir = rot(curdir);
        src = nxt;
    }
}

int simulate( int x, int y, string orient, int q){
    PII curpos = make_pair(x,y);
    PII curdir = getdir(orient);
    int pending = 0;
    int inbetween  = 0;
    PII pss = curpos;
    FREP(i,1,q){
        //cout<<curpos.first+1<<" "<<curpos.second+1<<"\n";
        string commtype;
        fin>>commtype;
        if(commtype=="R"){
            if(pending){
                PII nxtpos = getnextpos(curpos,curdir,pending);
                if(nxtpos==curpos){
                    if(inbetween==1){
                        //continue;
                    }
                    else{
                        mycomms.PB(make_pair("F",pending));
                    }
                }
                else{
                    mycomms.PB(make_pair("F",pending));
                }
                pending = 0;
                inbetween = 0;
                curpos = nxtpos;
            }
            curdir = rot(curdir);
            mycomms.PB(make_pair("R",0));
            cout<<curpos.first+1<<" "<<curpos.second+1<<"\n";
            cout<<curdir.first<<" "<<curdir.second<<"\n";
        }
        else{
            int x;
            fin>>x;
            pending+=x;
            inbetween++;
            pss = getnextpos(pss,curdir,x);
            cout<<pss.first+1<<" "<<pss.second+1<<"\n";
            cout<<curdir.first<<" "<<curdir.second<<"\n";
        }
        cout<<"\n\n";
    }
    //cout<<"sesh\n";
    int totmove = 0;
    curpos = make_pair(x,y);
    curdir = getdir(orient);
    FREP(i,1,mycomms.size()-1){
        //cout<<curpos.first<<" "<<curpos.second<<"\n";
        pair<string,int>cm = mycomms[i];
        if(cm.first=="R"){
            curdir = rot(curdir);
        }
        else{
            int gg = cm.second;
            PII nxtpos = getnextpos(curpos,curdir,gg);
            FREP(k,0,3){
                if(ispossible(k,curpos,nxtpos,curdir)){
                    totmove+=(k+1);
                    break;
                }
            }
            curpos =  nxtpos;
        }
    }
    return totmove;
}

int main(){
    int t;
    fin>>t;
    FREP(cs,1,t){
        init();
        int r,c,q;
        fin>>r>>c>>q;
        int x,y; string orient;
        fin>>x>>y>>orient;
        x--; y--;
        takeg(r,c);
        process(r,c);
        int ans = simulate(x,y,orient,q);
        cout<<ans<<"\n";
    }
    fin.close();
    return 0;
}
