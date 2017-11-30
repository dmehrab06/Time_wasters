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

class ZigZag{

    int dp[52][3];

    public:

        int longestZigZag(vector <int> sequence){
            memset(dp,-1,sizeof(dp));
            int l = sequence.size();
            FREP(i,0,(l-1)){
                dp[i][0] = 1; //he is first element
                FREP(j,0,(i-1)){
                    //dp[i][1] means se tar ager element er thek boro hobe
                    if(sequence[j]<sequence[i]){
                        dp[i][1] = max(dp[i][1],dp[j][0]+1);
                        dp[i][1] = max(dp[i][1],dp[j][2]+1);
                    }
                    if(sequence[j]>sequence[i]){
                        dp[i][2] = max(dp[i][2],dp[j][0]+1);
                        dp[i][2] = max(dp[i][2],dp[j][1]+1);
                    }
                }
            }
            int mxx = -1;
            FREP(i,0,(l-1))mxx = max(mxx,dp[i][0]);
            FREP(i,0,(l-1))mxx = max(mxx,dp[i][1]);
            FREP(i,0,(l-1))mxx = max(mxx,dp[i][2]);
            return mxx;
        }
};


int main(){
    vector<int>oka = {3,4,5,8,9,2,5,3,7};
    ZigZag z;
    cout<<z.longestZigZag(oka)<<"\n";
}
