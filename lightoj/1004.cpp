#include <iostream>
using namespace std;
int totalfloor;
int pyramid[210][210];
int dp[210][210];
long int func(int x,int y){
    if(x==((totalfloor*2)-1)){
        return pyramid[x][y];
    }
    if(y>totalfloor || y<1){
        return 0;
    }
    else if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else if(x<totalfloor){
       long int ret1,ret2;
       ret1=pyramid[x][y]+func(x+1,y);
       ret2=pyramid[x][y]+func(x+1,y+1);
       if(ret1>ret2){
        dp[x][y]=ret1;
       }
       else{
        dp[x][y]=ret2;
       }
       return dp[x][y];
    }
    else if(x>=totalfloor){
       long int ret1,ret2;
       ret1=pyramid[x][y]+func(x+1,y);
       ret2=pyramid[x][y]+func(x+1,y-1);
       if(ret1>ret2){
        dp[x][y]=ret1;
       }
       else{
        dp[x][y]=ret2;
       }
       return dp[x][y];
    }
}
int main(){
    int ii=1;
    int t;
    cin>>t;
    for(int i=0;i<210;++i){
            for(int j=0;j<210;++j){
                pyramid[i][j]=0;
            }
        }
    while(t--){
       
        cin>>totalfloor;
        for(int i=1;i<=totalfloor;++i){
            for(int j=1;j<=i;++j){
                cin>>pyramid[i][j];
            }
        }
        for(int i=(totalfloor+1);i<=((2*totalfloor)-1);++i){
            for(int j=1;j<=((2*totalfloor)-i);++j){
                cin>>pyramid[i][j];
            }
        }
        for(int i=0;i<210;++i){
            for(int j=0;j<210;++j){
                dp[i][j]=-1;
            }
        }
        long int result;
        result=func(1,1);
 
        cout<<"Case "<<ii<<": "<<result<<"\n";
        ii++;
        for(int i=0;i<=((2*totalfloor)+1);++i){
            for(int j=0;j<=totalfloor;++j){
                pyramid[i][j]=0;
            }
        }
 
    }
    return 0;
}
