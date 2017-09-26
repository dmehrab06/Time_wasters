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
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;

typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, LLI p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

LLI fib(LLI N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    if (N == 1)
        return 1;
    T = pow(T, N-1);

    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

/* Driver program to test above function */
/*int main()
{
    LLI n;
  while(cin>>n){
    printf("%lld\n", fib(n));
  }
  getchar();
  return 0;
}*/

int main(){
    int t;
    scanf("%d",&t);
	LLI n;
	//F[0]=F[1]=1;
	int cs=1;

	while(t--){
        scanf("%lld",&n);
        printf("Case %d: ",cs++);
        if(n==1){
            printf("8\n");
        }
        else if(n==2){
            printf("16\n");
        }
        else{
            LLI oka=fib(n+2)-3;
            while(oka<0){
                oka+=MOD;
            }
            //cout<<n+2<<" "<<oka<<"\n";
            //cout<<oka<<"\n";
            oka=(oka)*(LLI)16;
            //cout<<oka<<"\n";
            LLI sub=(LLI)8*(n-2);
            //cout<<sub<<"\n";
            sub%=MOD;
            oka=oka-sub;
            while(oka<0){
                oka+=MOD;
            }
            oka+=16;
            oka%=MOD;
            printf("%lld\n",oka);
        }
       // cout << (n==0 ? 0 : f(n-1)) << endl;
	}
	return 0;


}
