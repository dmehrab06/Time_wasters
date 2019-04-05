/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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

int dp[2003][2003][4];
int rev_dp1[2003][2003][4];
int rev_dp[2003][2003][4];

int arr[2003];
int revarr[2003];

void precalc(int n){
    FREP(i,1,n){
        if(arr[i]==1){
            dp[i][i][1] = 1;
        }
        else{
            dp[i][i][3] = 1;
        }
        dp[i][i][2] = 1;
    }
    FREP(dif,1,(n-1)){
        FREP(i,1,n-dif){
            int j = i+dif;
            //bring from i+1,j
            if(arr[i]==1){
                dp[i][j][1] = max(dp[i][j][1],dp[i+1][j][1]+1);
                dp[i][j][2] = max(dp[i][j][2],dp[i+1][j][2]+1);
                dp[i][j][2] = max(dp[i][j][2],dp[i+1][j][3]+1);
            }
            else{
                dp[i][j][3] = max(dp[i][j][3],dp[i+1][j][3]+1);
            }
            //bring from i,j-1
            if(arr[j]==1){
                dp[i][j][1] = max(dp[i][j][1],dp[i][j-1][1]+1);
            }
            else{
                dp[i][j][2] = max(dp[i][j][2],dp[i][j-1][2]+1);
                dp[i][j][2] = max(dp[i][j][2],dp[i][j-1][1]+1);
                dp[i][j][3] = max(dp[i][j][3],dp[i][j-1][3]+1);
            }
            dp[i][j][2] = max(dp[i][j][2],dp[i][j][1]);
            dp[i][j][2] = max(dp[i][j][2],dp[i][j][3]);
        }
    }
}

void precalcrev(int n){
    FREP(i,1,n){
        if(revarr[i]==1){
            rev_dp1[i][i][1] = 1;
        }
        else{
            rev_dp1[i][i][3] = 1;
        }
        rev_dp1[i][i][2] = 1;
    }
    FREP(dif,1,(n-1)){
        FREP(i,1,n-dif){
            int j = i+dif;
            //bring from i+1,j
            if(revarr[i]==1){
                rev_dp1[i][j][1] = max(rev_dp1[i][j][1],rev_dp1[i+1][j][1]+1);
                rev_dp1[i][j][2] = max(rev_dp1[i][j][2],rev_dp1[i+1][j][2]+1);
                rev_dp1[i][j][2] = max(rev_dp1[i][j][2],rev_dp1[i+1][j][3]+1);
            }
            else{
                rev_dp1[i][j][3] = max(rev_dp1[i][j][3],rev_dp1[i+1][j][3]+1);
            }
            //bring from i,j-1
            if(revarr[j]==1){
                rev_dp1[i][j][1] = max(rev_dp1[i][j][1],rev_dp1[i][j-1][1]+1);
            }
            else{
                rev_dp1[i][j][2] = max(rev_dp1[i][j][2],rev_dp1[i][j-1][2]+1);
                rev_dp1[i][j][2] = max(rev_dp1[i][j][2],rev_dp1[i][j-1][1]+1);
                rev_dp1[i][j][3] = max(rev_dp1[i][j][3],rev_dp1[i][j-1][3]+1);
            }
        }
    }
    FREP(i,1,n){
        FREP(j,i,n){
            int ii = n-i+1;
            int jj = n-j+1;
            rev_dp[jj][ii][1] = rev_dp1[i][j][1];
            rev_dp[jj][ii][2] = rev_dp1[i][j][2];
            rev_dp[jj][ii][3] = rev_dp1[i][j][3];
        }
    }
}

void printcheck(int n){
    FREP(i,1,n){
        FREP(j,i,n){
            FREP(k,1,3){
                cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k]<<" ";
            }
            cout<<"\n";
        }
    }
    FREP(i,1,n){
        FREP(j,i,n){
            FREP(k,1,3){
                cout<<"revdp["<<i<<"]["<<j<<"]["<<k<<"] = "<<rev_dp[i][j][k]<<" ";
            }
            cout<<"\n";
        }
    }
}

int solve(int n){
    int mx = 0;
    FREP(l,1,n){
        FREP(r,l,n){
            //[l,r] k reverse korbo
            FREP(x,1,3){
                FREP(y,x,3){
                    FREP(z,y,3){
                        if(x==2 && y==2)continue;
                        if(y==2 && z==2)continue;
                        int curans = dp[1][l-1][x]+rev_dp[l][r][y]+dp[r+1][n][z];
                        if(curans>mx){
                            mx = curans;
                            //cout<<"maxans for partition "<<l<<","<<r<<" with x = "<<x<<" y = "<<y<<" z = "<<z<<"\n";
                        }
                    }
                }
            }
        }
    }
    return mx;
}

int main(){
    MSET(dp,0);
    MSET(rev_dp1,0);
    MSET(rev_dp,0);
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
        revarr[n-i+1] = arr[i];
    }
    precalc(n);
    precalcrev(n);
    //printcheck(n);
    printf("%d\n",solve(n));
    return 0;
}
