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

ifstream fin("lucky.in");
ofstream fout("lucky.out");

int grid[103][103];

int main(){
    int r,c;
    fin>>r>>c;
    FREP(i,1,r){
        FREP(j,1,c){
            fin>>grid[i][j];
        }
    }
    int total=0;
    FREP(i,1,r){
        FREP(j,1,c){
            int cur=grid[i][j];
            int curx=i;int cury=j;
            //check left
            int f=1;
            RFREP(k,(curx-1),1){
                if(grid[k][cury]>=cur){
                    f=0;
                    break;
                }
            }
            if(f)total++;
            f=1;
            RFREP(k,(cury-1),1){
                if(grid[curx][k]>=cur){
                    f=0;
                    break;
                }
            }
            if(f)total++;
            f=1;
            FREP(k,curx+1,r){
                if(grid[k][cury]>=cur){
                    f=0;
                    break;
                }
            }
            if(f)total++;
            f=1;
            FREP(k,cury+1,c){
                if(grid[curx][k]>=cur){
                    f=0;
                    break;
                }
            }
            if(f)total++;
        }
    }
    fout<<total<<"\n";
    fin.close();
    fout.close();
    return 0;
}
