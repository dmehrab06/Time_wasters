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

vector< vector <int> > getgrid(int val, int r, int c){
    string base3 = "";
    for(int i = 1;i<=(r*c);++i){
        int pp = val%3;
        base3.PB(pp+'0');
        val/=3;
    }
    REVV(base3);
    vector< VI >gg;
    VI line;
    FREP(i,0,r-1){
        gg.PB(line);
        FREP(j,0,c-1){
            gg[i].PB(0);
        }
    }
    for(int i=0;i<base3.size();++i){
        int oka = base3[i]-'0';
        int rr = i/c;
        int cc = i%c;
        gg[rr][cc] = oka;
    }
    return gg;
}

bool isvalid(vector<VI>grid){
    int rr = grid.size();
    int cc = grid[0].size();

    FREP(i,0,rr-1){
        if(grid[i][0]!=0 || grid[i][cc-1]!=0){
            return false;
        }
    }
    FREP(j,0,cc-1){
        if(grid[rr-1][j]!=0)return false;
    }
    FREP(i,0,rr-1){
        FREP(j,0,cc-2){
            if(grid[i][j]==2 && grid[i][j+1]==1){
                return false;
            }
        }
    }
    return true;
}

void printans(vector<VI>grid){
    int rr = grid.size();
    int cc = grid[0].size();

    FREP(i,0,rr-1){
        FREP(j,0,cc-1){
            if(grid[i][j]==0){
                printf(".");
            }
            else if(grid[i][j]==1){
                printf("/");
            }
            else{
                printf("\\");
            }
        }
        printf("\n");
    }
    return;
}

bool simulate(vector<VI>grid, VI rw){
    int rr = grid.size();
    int cc = grid[0].size();
    vector<int>result;
    FREP(i,0,cc-1)result.PB(0);
    FREP(j,0,cc-1){
        int currow = 0;
        int curcol = j;
        while(currow<(rr-1)){
            if(grid[currow][curcol]==1){
                curcol--;
            }
            else if(grid[currow][curcol]==2){
                curcol++;
            }
            currow++;
        }
        result[curcol]++;
    }
    return rw==result;
}

void solve(vector<int>rw, int c, int cs){
    printf("Case #%d: ",cs);
    FREP(rr,1,c){
        int tot = rr*c;
        int upto = pow(3,tot)-1;
        cout<<rr<<"\n";
        FREP(mask,0,upto){
            vector<VI>gg = getgrid(mask,rr,c);
            if(isvalid(gg)){
                if(simulate(gg,rw)){
                    printf("%d\n",rr);
                    printans(gg);
                    return;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int col;
        scanf("%d",&col);
        vector<int>rw;
        FREP(i,1,col){
            int a;
            scanf("%d",&a);
            rw.PB(a);
        }
        solve(rw,col,cs);
    }
    return 0;
}
