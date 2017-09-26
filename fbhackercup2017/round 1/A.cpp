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

    vector < vector <LLI> > grid;

    int curpointer[303];

    LLI solve(int n, int m){
        FREP(i,0,(n-1)){
            FREP(j,0,(m-1)){
                grid[i][j]=grid[i][j]+(2*j)+1;
            }
        }

        LLI s=0;
        FREP(i,0,(n-1)){
            LLI mnn=-1;
            LLI mnrow=-1;
            //cout<<"iteration "<<i<<"\n";
            FREP(row,0,i){
                if(curpointer[row]>=m)continue;
                if(mnn==-1 || (curpointer[row]<m && grid[row][curpointer[row]]<mnn)){
                    mnn=grid[row][curpointer[row]];
                    mnrow=row;
                }
            }
            //cout<<mnn<<" "<<mnrow<<"\n";
            s+=mnn;
            curpointer[mnrow]++;
        }
        return s;
    }

    void takeg(int n, int m){
        vector <LLI> line;
        grid.clear();
        FREP(i,1,(n+2)){
            grid.PB(line);
        }
        FREP(i,1,n){
            FREP(j,1,m){
                LLI a;
                scanf("%lld",&a);
                grid[i-1].PB(a);
            }
        }
        FREP(i,0,n-1){
            SORTV(grid[i]);
        }
        FREP(i,0,(n-1)){
            curpointer[i]=0;
        }
    }

    int main(){

        int t;
        scanf("%d",&t);
        int cs=1;
        while(t--){
            int n,m;
            scanf("%d %d",&n,&m);
            takeg(n,m);
            LLI ans=solve(n,m);
            printf("Case #%d: %lld\n",cs++,ans);
        }
        return 0;
    }
