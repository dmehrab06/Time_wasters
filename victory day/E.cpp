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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char grid[10][10];

bool checkrook(int curx, int cury, int desx, int desy, int n, int m){
    int dirx[4]={-1,1,0,0};
    int diry[4]={0,0,1,-1};
    FREP(i,0,3){
        int xx=curx;
        int yy=cury;
        while(true){
            xx+=dirx[i];
            yy+=diry[i];
            if(ISVALID(xx,yy,n,m) && xx==desx && yy==desy){
                return true;
            }
            else{
                if(!ISVALID(xx,yy,n,m)){
                    break;
                }
                else if(grid[xx][yy]!='.'){
                    return false;
                }
            }
        }
    }
    return false;
}

bool checkpawn(int curx, int cury, int desx, int desy, int n, int m){
    if(ISSML(grid[curx][cury])){
        if(ISVALID(curx-1,cury-1,n,m) && (curx-1)==desx && (cury-1)==desy){
            return true;
        }
        if(ISVALID(curx-1,cury+1,n,m) && (curx-1)==desx && (cury+1)==desy){
            return true;
        }
    //    return false;
    }
    else{
        if(ISVALID(curx+1,cury-1,n,m) && (curx+1)==desx && (cury-1)==desy){
            return true;
        }
        if(ISVALID(curx+1,cury+1,n,m) && (curx+1)==desx && (cury+1)==desy){
            return true;
        }
    //    return false;
    }
    return false;
}

bool checkking(int curx, int cury, int desx, int desy, int n, int m){
    int dirx[8]={-1,-1,-1,0,0,1,1,1};
    int diry[8]={-1,0,1,1,-1,0,-1,1};
    FREP(i,0,7){
        int xx=curx+dirx[i];
        int yy=cury+diry[i];
        if( ISVALID(xx,yy,n,m) && xx==desx && yy==desy)return true;
    }
    return false;
}

bool checkknight(int curx, int cury, int desx, int desy, int n, int m){
    int dirx[8]={2,2,-2,-2,1,1,-1,-1};
    int diry[8]={-1,1,1,-1,2,-2,2,-2};
    FREP(i,0,7){
        int xx=curx+dirx[i];
        int yy=cury+diry[i];
        if(ISVALID(xx,yy,n,m) && xx==desx && yy==desy)return true;
    }
    return false;
}

bool checkbishop(int curx, int cury, int desx, int desy, int n, int m){
    int dirx[4]={-1,1,-1,1};
    int diry[4]={-1,1,1,-1};
    FREP(i,0,3){
        int xx=curx;
        int yy=cury;
        while(true){
            xx+=dirx[i];
            yy+=diry[i];
            if(ISVALID(xx,yy,n,m) && xx==desx && yy==desy){
                return true;
            }
            else{
                if(!ISVALID(xx,yy,n,m)){
                    break;
                }
                else if(grid[xx][yy]!='.'){
                    return false;
                }
            }
        }
    }
    return false;
}

bool checkqueen(int curx, int cury, int desx, int desy, int n, int m){
    int dirx[8]={-1,-1,-1,0,0,1,1,1};
    int diry[8]={-1,0,1,1,-1,0,-1,1};
    FREP(i,0,7){
        int xx=curx;
        int yy=cury;
        while(true){
            xx+=dirx[i];
            yy+=diry[i];
            if(ISVALID(xx,yy,n,m) && xx==desx && yy==desy){
                return true;
            }
            else{
                if(!ISVALID(xx,yy,n,m)){
                    break;
                }
                else if(grid[xx][yy]!='.'){
                    return false;
                }
            }
        }
    }
    return false;
}

int main(){
    FREP(i,0,7){
        scanf("%s",grid[i]);
    }
    string ss;
    cin>>ss;
    int desy=ss[0]-'a';
    int desx=ss[1]-'1';
    if(ISSML(grid[desx][desy])){
        FREP(i,0,7){
            FREP(j,0,7){
                if(ISCAP(grid[i][j])){
                    bool f;
                    if(grid[i][j]=='P'){
                        f=checkpawn(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='C'){
                        f=checkknight(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='T'){
                        f=checkrook(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='B'){
                        f=checkbishop(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='R'){
                        f=checkqueen(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='K'){
                        f=checkking(i,j,desx,desy,8,8);
                    }
                    if(f){
                        printf("Sim\n");
                        return 0;
                    }
                }
            }
        }
        printf("Nao\n");
        return 0;
    }
    else{
        FREP(i,0,7){
            FREP(j,0,7){
                if(ISSML(grid[i][j])){
                    bool f;
                    if(grid[i][j]=='p'){
                        f=checkpawn(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='c'){
                        f=checkknight(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='t'){
                        f=checkrook(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='b'){
                        f=checkbishop(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='r'){
                        f=checkqueen(i,j,desx,desy,8,8);
                    }
                    else if(grid[i][j]=='k'){
                        f=checkking(i,j,desx,desy,8,8);
                    }
                    if(f){
                        printf("Sim\n");
                        return 0;
                    }
                }
            }
        }
        printf("Nao\n");
        return 0;
    }
    return 0;
}
