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

using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


LLI MDD=1000000009;

void multiply(LLI a[3][3], LLI b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    LLI mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++){
                mul[i][j] += a[i][k]*b[k][j];
                mul[i][j]%=MDD;
            }

        }
    }
    FREP(i,0,2){
        FREP(j,0,2){
            a[i][j]=mul[i][j];
        }
    }
}

// Function to compute F raise to power n-2.
void power(LLI F[3][3], int n)
{
    LLI M[3][3] = {{3,4,5}, {6,7,8}, {9,10,11}};
    LLI I[3][3]  = {{1,0,0},{0,1,0},{0,0,1}};
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if(n==0){
        FREP(i,0,2){
            FREP(j,0,2){
                F[i][j]=I[i][j];
            }
        }
        return;
    }
    if (n==1){
        FREP(i,0,2){
            FREP(j,0,2){
                F[i][j]=M[i][j];
            }
        }
        return;
    }

    power(F,n/2);

    multiply(F,F);

    if (n%2 != 0){
        multiply(F, M);
    }


    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
}

int main(){
    int t;
    scanf("%d",&t);
    //int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        LLI oka[3][3]={{3,4,5}, {6,7,8}, {9,10,11}};
    //int I[3][3]  = {{1,0,0},{0,1,0},{0,0,1}};
        power(oka,n-1);
        LLI tot=0;
        FREP(i,0,2){
            FREP(j,0,2){
                tot=tot+oka[i][j];
                tot%=MDD;
            }
        }
        printf("%lld\n",tot);
    }
    return 0;
}

