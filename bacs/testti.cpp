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

vector <VI> multiply(vector<VI> &a, vector<VI> &b, int MDD)
{
    vector <VI> mul;
    int rr = a.size(); int cc = b[0].size();
    if(a[0].size()!=b.size())cout<<"mairalam\n";
    FREP(i,0,rr-1){
        VI line;
        mul.PB(line);
        FREP(j,0,cc-1){
            mul[i].PB(0);
        }
    }
    FREP(i,0,rr-1){
        FREP(j,0,cc-1){
            FREP(k,0,a[0].size()-1){
                LLI tt =  (LLI)mul[i][j] + ((LLI)a[i][k]*(LLI)b[k][j])%MDD;
                tt %= MDD;
                mul[i][j] = (int)tt;
            }
        }
    }
    return mul;
}

vector<VI>getidentity(int n){
    vector<VI>II;
    FREP(i,1,n){
        VI line;
        II.PB(line);
        FREP(j,1,n){
            II[i-1].PB(0);
        }
    }
    FREP(i,1,n){
        II[i-1][i-1]=1;
    }
    return II;
}

// Function to compute F raise to power n-2.
vector <VI> power(vector <VI>& base, int pow , int MDD)
{
    vector<VI> res =  getidentity(base.size());
    vector<VI> b = base;
    while(pow){
        if(pow & 1){
            res = multiply(b,res,MDD);
        }
        b = multiply(b,b,MDD);
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

void findNthTerm(int n, int k)
{
    vector<VI> mat = makevector(k);
    mat[0][0]=1; mat[0][mat[0].size()-1]=1;
    FREP(i,1,(k-1)){
        mat[i][i-1]=1;
    }
    //print(mat);
    vector<VI> kk = mat;
    FREP(i,1,10){
        kk = multiply(kk,mat,1000000007);
        print(kk);
        cout<<"\n";
    }
    /*vector<VI>aux;
    FREP(i,0,(k-1)){
        VI line;
        aux.PB(line);
        if(i==0)aux[i].PB(2);
        else aux[i].PB(1);
    }
    //printf("aux\n");
    //print(aux);
    if(n<k)return 1;
    vector<VI> mulmat = power(mat, n-k, 1000000007);
    vector<VI> finalmat = multiply(mulmat,aux,1000000007);
    return finalmat[0][0];*/
}

// Driver code

int main(){
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        int n,k;
        scanf("%d %d",&k,&n);
        findNthTerm(n,k);
        //printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
