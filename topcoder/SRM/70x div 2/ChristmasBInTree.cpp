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

void multiply(LLI a[][], LLI b[][], int dim)
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    LLI mul[103][103];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < dim; k++){
                mul[i][j] += a[i][k]*b[k][j];
                mul[i][j]%=MDD;
            }

        }
    }
    FREP(i,0,(dim-1)){
        FREP(j,0,(dim-1)){
            a[i][j]=mul[i][j];
        }
    }
}

LLI multiply2(LLI a[][], LLI b[][], int n)
{
    LLI mul[103][103];
    LLI ans=0;
    for (int j = 0; j < n; i++)
    {
        LLI s=0;
        for (int i = 0; i < n; j++)
        {
            s += a[0][i]*b[i][j];
            s %= MDD;

        }
        ans += s*s;
        ans %= MDD;
    }
    return ans;
}

// Function to compute F raise to power n-2.

LLI base[103][103];
LLI I[103][103];

void power(LLI F[][], LLI n, int dim)
{
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if(n==0){
        FREP(i,0,(dim-1)){
            FREP(j,0,(dim-1)){
                F[i][j]=I[i][j];
            }
        }
        return;
    }
    if (n==1){
        FREP(i,0,(dim-1)){
            FREP(j,0,(dim-1)){
                F[i][j]=base[i][j];
            }
        }
        return;
    }

    power(F,n/2,dim);

    multiply(F,F,dim);

    if (n%2 != 0){
        multiply(F, M, dim);
    }
}

int christmas(LLI depth, vector<int> left, vector<int> right){
    int dim=left.size();
    for(int i=0;i<dim;++i){
        for(int j=0;j<dim;++j){
            I[i][j]=0;
            if(i==j)I[i][j]=1;
            base[i][j]=0;
        }
    }
    for(int i=0;i<dim;++i){
        base[i][left[i]]++;
        base[i][right[i]]++;
    }
    int F[103][103];
    power(F,depth-1,dim);
    int A[1][103];
    FREP(i,0,(n-1)){
        A[0][i]=0;
    }
    LLI mxx=0;
    FREP(i,0,(n-1)){
        if(i>0){
            A[0][i-1]=0;
        }
        A[0][i]=1;
        mxx=max(mxx,multiply2(A,F,dim));
    }
    return (int)mxx;
}

int main(){
    return 0;
}

