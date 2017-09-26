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
//#define VLLI vector<long long int>
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

void multiply(int** a, int** b, int n, int MDD)
{
    int **mul = new int*[n];
    FREP(i,0,n-1){
        mul[i]=new int[n];
        FREP(j,0,n-1)mul[i][j]=0;
    }
    FREP(i,0,n-1){
        FREP(j,0,n-1){
            FREP(k,0,n-1){
                LLI tt =  (LLI)mul[i][j] + ((LLI)a[i][k]*(LLI)b[k][j])%MDD;
                tt %= MDD;
                mul[i][j] = (int)tt;
            }
        }
    }
    FREP(i,0,n-1)FREP(j,0,n-1)b[i][j]=mul[i][j];
}

int** getidentity(int n){
    int** II=new int*[n];
    FREP(i,1,n){
        II[i-1] = new int[n];
        FREP(j,1,n){
            if(i==j)II[i-1][j-1]=1;
            else II[i-1][j-1]=0;
        }
    }
    return II;
}

// Function to compute F raise to power n-2.
int** power(int** base, int pow , int k, int MDD)
{
    int** res =  getidentity(k);
    //cout<<"identity paisi\n";
    int** b=new int*[k];
    FREP(i,1,k){
        b[i-1] = new int[k];
        FREP(j,1,k){
            b[i-1][j-1]=base[i-1][j-1];
        }
    }
    while(pow){
        //cout<<pow<<"\n";
        if(pow & 1){
            multiply(b,res,k,MDD);
        }
        multiply(b,b,k,MDD);
        pow = pow>>1;
    }
    return res;
}

vector<VI> makevector(int n){
    vector <VI> mat;
    FREP(i,0,(n-1)){
        VI line;
        mat.PB(line);
        FREP(j,0,(n-1))mat[i].PB(0);
    }
    return mat;
}

void print(vector <VI> &mat){
    FREP(i,0,mat.size()-1){
        FREP(j,0,mat[i].size()-1){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

LLI findNthTerm(int n, int k)
{
    int **mat=new int*[k];
    FREP(i,1,k){
        mat[i-1] = new int[k];
        FREP(j,1,k){
            mat[i-1][j-1]=0;
        }
    }
    mat[0][0]=1; mat[0][k-1]=1;
    FREP(i,1,(k-1)){
        mat[i][i-1]=1;
    }
    //print(mat);
    int **aux=new int*[k];
    FREP(i,0,k-1){
        aux[i]=new int[1];
        if(i==0)aux[i][0]=2;
        else aux[i][0]=1;
    }
    //printf("aux\n");
    //print(aux);
    //cout<<"aux banaisi\n";
    if(n<k)return 1;
    int** mulmat = power(mat, n-k,k, 1000000007);
    LLI s = 0;
    FREP(i,0,(k-1)){
        s = s+ (LLI)mulmat[0][i]*(LLI)aux[i][0];
        s%=1000000007;
    }
    return s;
}

// Driver code

int main(){
    cout<<"10000\n";
    FREP(i,1,10000){
        cout<<"9 1000000000\n";
    }
}
