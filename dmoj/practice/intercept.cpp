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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double mat[19][20];

int forwardElim(double mat[][20], int N);

// function to calculate the values of the unknowns
void backSub(double mat[][20], int N);

void gaussianElimination(double mat[][20], int N)
{

    int singular_flag = forwardElim(mat,N);

    if (singular_flag != -1)
    {
        printf("Singular Matrix.\n");
        if (mat[singular_flag][N])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return;
    }
    backSub(mat,N);
}

// function for elemntary operation of swapping two rows
void swap_row(double mat[][20], int i, int j, int N)
{
    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

// function to print matrix content at any stage
void print(double mat[][20], int N)
{
    /*for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<=N; j++)
            printf("%.0lf", mat[i][j]);

    printf("\n");*/
}

// function to reduce matrix to r.e.f.
int forwardElim(double mat[][20], int N)
{
    for (int k=0; k<N; k++)
    {
        int i_max = k;
        int v_max = mat[i_max][k];
        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;

        if (!mat[k][i_max])
            return k; // Matrix is singular

        if (i_max != k)
            swap_row(mat, k, i_max,N);


        for (int i=k+1; i<N; i++)
        {
            double f = mat[i][k]/mat[k][k];

            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;

            mat[i][k] = 0;
        }

    }
    return -1;
}

void backSub(double mat[][20], int N)
{
    double x[19];
    for (int i = N-1; i >= 0; i--)
    {
        x[i] = mat[i][N];

        for (int j=i+1; j<N; j++)
        {
            x[i] -= mat[i][j]*x[j];
        }

        x[i] = x[i]/mat[i][i];
    }

    //printf("\nSolution for the system:\n");
    for (int i=N-1; i>=0; i--)
        printf("%.0lf ", x[i]);
    printf("\n");

}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        FREP(i,0,(n-1)){
            int x;
            scanf("%d",&x);
            double s=1.0;
            FREP(j,0,(n)){
                mat[i][j]=s;
                s=s*x;
            }
            mat[i][n+1]=0.0;
        }
        int xp,yp;
        scanf("%d %d",&xp,&yp);
        double sp=1.0;
        FREP(j,0,(n)){
            mat[n][j]=sp;
            sp=sp*xp;
        }
        mat[n][n+1]=yp;
        gaussianElimination(mat,n+1);
    }


    return 0;
}
