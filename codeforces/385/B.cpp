/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define PB push_back
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
using namespace std;

char grid[503][503];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,0,(n-1)){
        scanf("%s",grid[i]);
    }
    int sf=0;
    int sx,sy;
    int ex,ey;int tot=0;
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            if(grid[i][j]=='X' && !sf){
                sx=i;
                sy=j;
                sf=1;
            }
            if(grid[i][j]=='X'){
                ex=i;
                ey=j;
                tot++;
            }
        }
    }
    int cc=0;
    FREP(i,sx,ex){
        FREP(j,sy,ey){
            if(grid[i][j]!='X'){
                printf("NO\n");
                return 0;
            }
            cc++;
        }
    }
    printf("%s\n",cc==tot?"YES":"NO");
}
