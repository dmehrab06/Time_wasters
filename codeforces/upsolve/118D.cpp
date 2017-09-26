#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000
using namespace std;

int n1,n2,k1,k2;
int hdp[203][103][12];
int fdp[203][103][12];

int main(){

    for(int i=0;i<203;++i){
        for(int j=0;j<103;++j){
            for(int k=0;k<12;++k){
                hdp[i][j][k]=0;
                fdp[i][j][k]=0;
            }
        }
    }
    hdp[1][1][1]=1;
    fdp[1][1][1]=1;
    cin>>n1>>n2>>k1>>k2;
    for(int i=2;i<=n1+n2;++i){
        int curl=i-1;
        for(int j=0;j<n1;++j){
            for(int k=0;k<k1;++k){
                hdp[i][j+1][k+1]+=hdp[curl][j][k];
              //  if(i==1 && j==0 && k==0){
                //    cout<<"influenced by h[0][0][0]\n";
                //}
                if(hdp[i][j+1][k+1]>=MAXMOD)hdp[i][j+1][k+1]-=MAXMOD;
            }
        }
        for(int j=0;j<n2;++j){
            for(int k=0;k<k2;++k){
                fdp[i][j+1][k+1]+=fdp[curl][j][k];
                if(fdp[i][j+1][k+1]>=MAXMOD)fdp[i][j+1][k+1]-=MAXMOD;
            }
        }
       for(int j=curl;curl-j<n1;--j){
            for(int k=0;k<=k2;++k){
                hdp[i][curl-j+1][1]+=fdp[curl][j][k];
            //    if(i==1 && j==0 && k==0){
              //      cout<<"influenced by f[0][0][0]\n";
               // }
                if(hdp[i][curl-j+1][1]>=MAXMOD)hdp[i][curl-j+1][1]-=MAXMOD;
            }
        }
        for(int j=curl;curl-j<n2;--j){
            for(int k=0;k<=k1;++k){
                fdp[i][curl-j+1][1]+=hdp[curl][j][k];
                if(fdp[i][curl-j+1][1]>=MAXMOD)fdp[i][curl-j+1][1]-=MAXMOD;
            }
        }
    }


    int ans=0;
        for(int k=0;k<=k1;++k){
            ans+=hdp[n1+n2][n1][k];
            if(ans>=MAXMOD)ans-=MAXMOD;
        }


        for(int k=0;k<=k2;++k){
            ans+=fdp[n1+n2][n2][k];
            if(ans>=MAXMOD)ans-=MAXMOD;
        }


    cout<<ans<<"\n";
    return 0;
}
