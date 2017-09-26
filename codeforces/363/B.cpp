#include <bits/stdc++.h>
#define MXX 1000000007
using namespace std;

int grid[1003][1003];
int rowhas[1003];
int colhas[1003];

void init(){
    for(int i=0;i<1003;++i){
        for(int j=0;j<1003;++j){
            grid[i][j]=0;
        }
        colhas[i]=0;
        rowhas[i]=0;
    }
}
int n,m;

int findbomb(int x, int y){
    int ans=rowhas[x]+colhas[y];
    if(grid[x][y]==1){
        ans--;
    }
    return ans;
}
int main(){
    int bombs=0;
    init();
    scanf("%d %d",&n,&m);
    char cc[1003];
    for(int i=1;i<=n;++i){
        scanf("%s",cc);
        for(int j=0;j<m;++j){
            if(cc[j]=='*'){
                bombs++;
                grid[i][j+1]=1;
                rowhas[i]++;
                colhas[j+1]++;
            }
        }
    }
    int flag=0;
    int ansx;
    int ansy;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int curx=i;
            int cury=j;
            int found=findbomb(curx,cury);
            if(found==bombs){
                ansx=curx;
                ansy=cury;
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag){
        cout<<"YES\n";
        cout<<ansx<<" "<<ansy<<"\n";
    }
    else{
        cout<<"NO\n";
    }
}
