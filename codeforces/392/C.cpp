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

LLI students[103][103];

int main(){
    int n,m,x,y;
    LLI k;
    cin>>n>>m>>k>>x>>y;
    LLI prothom=(n*m);
    LLI mnn=1000000000000000007;
    LLI mxx=-1;
    if(n==1){
        LLI allasked=k/m;
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                students[i][j]+=allasked;
            }
        }
        LLI left=k%m;
        FREP(i,0,left-1){
            students[0][i]++;
        }
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                mnn=min(students[i][j],mnn);
                mxx=max(students[i][j],mxx);
            }
        }
        cout<<mxx<<" "<<mnn<<" "<<students[x-1][y-1]<<"\n";
        return 0;
    }
    if(k<prothom){
        FREP(i,0,(k-1)){
            students[i/m][i%m]++;
        }
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                mnn=min(students[i][j],mnn);
                mxx=max(students[i][j],mxx);
            }
        }
        cout<<mxx<<" "<<mnn<<" "<<students[x-1][y-1]<<"\n";
        return 0;
    }
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            students[i][j]++;
        }
    }
    k-=(n*m);
    LLI nextdiv=(n-1)*m;
    LLI traverse=k/nextdiv;
    LLI lefttraverse=k%nextdiv;
    if(traverse%2==0){
        FREP(i,1,(n-2)){
            FREP(j,0,(m-1)){
                students[i][j]+=traverse;
            }
        }
        FREP(j,0,(m-1)){
            students[0][j]+=(traverse/2);
            students[n-1][j]+=(traverse/2);
        }
        int start=0;
        while(lefttraverse>0){
            students[n-2-start/m][start%m]++;
            lefttraverse--;
            start++;
        }
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                mnn=min(students[i][j],mnn);
                mxx=max(students[i][j],mxx);
            }
        }
        cout<<mxx<<" "<<mnn<<" "<<students[x-1][y-1]<<"\n";
        return 0;

    }
    else{
        FREP(i,1,(n-2)){
            FREP(j,0,(m-1)){
                students[i][j]+=traverse;
            }
        }
        FREP(j,0,(m-1)){
            students[0][j]+=(traverse/2+1);
            students[n-1][j]+=(traverse/2);
        }
        int start=0;
        while(lefttraverse>0){
            students[start/m+1][start%m]++;
            lefttraverse--;
            start++;
        }
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                mnn=min(students[i][j],mnn);
                mxx=max(students[i][j],mxx);
            }
        }
        cout<<mxx<<" "<<mnn<<" "<<students[x-1][y-1]<<"\n";
        return 0;

    }
}
