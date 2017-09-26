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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

vector< vector < vector< int >  > >cnt;

vector< vector<int> >sq;

PII dummy = make_pair(-1,-1);

struct KeyHasher
{
  size_t operator()(const pair<PII,PII> & k) const
  {
    size_t hsh = 0 ;
    hsh = k.first.first*1000+k.first.second*100+k.second.first*10+k.second.second;
    return hsh;
  }
};

unordered_map< pair<PII,PII>, pair<int, pair<PII,PII> >,KeyHasher >areamap;

pair<int,pair<PII,PII> >findmax(pair<int,pair<PII,PII> >p1, pair<int,pair<PII,PII> > p2){
    if(p1.first>p2.first){
        return p1;
    }
    else return p2;
}

bool isvalidpalindrome(vector<int>digcnts){
    int odd=0;
    int even=0;
    int len=0;
    int zeros=digcnts[0];
    FREP(i,0,9){
        if(digcnts[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
        len+=digcnts[i];
    }
    if(len==1)return true;
    if(len==zeros)return false;
    if(len%2 && odd==1)return true;
    if(len%2==0 && odd==0)return true;
    return false;
}

int getcnt(int x, int y, int dig, int n, int m){
    if(ISVALID(x,y,n,m)){
        return cnt[x][y][dig];
    }
    return 0;
}

vector<int> findigcnt(int x1, int y1, int x2, int y2, int n, int m){
    vector<int>digs;
    FREP(i,0,9){
        int s1 = getcnt(x2,y2,i,n,m);
        int s2 = getcnt(x2,y1-1,i,n,m);
        int s3 = getcnt(x1-1,y2,i,n,m);
        int s4 = getcnt(x1-1,y1-1,i,n,m);
        int tot = s1-s2-s3+s4;
        digs.PB(tot);
    }
    return digs;
}

pair<int, pair<PII,PII> > solve(int n, int m){
    int mxx=0;
    PII top, bottom;
    FREP(x1,0,n-1){
        FREP(y1,0,m-1){
            FREP(x2,x1,(n-1)){
                FREP(y2,y1,(m-1)){
                    vector<int>digs = findigcnt(x1,y1,x2,y2,n,m);
                    if(isvalidpalindrome(digs)){
                        int area = (x2-x1+1)*(y2-y1+1);
                        if(area>mxx){
                            mxx=area;
                            top = make_pair(x1,y1);
                            bottom = make_pair(x2,y2);
                        }
                    }
                }
            }
        }
    }
    return make_pair(mxx,make_pair(top,bottom));
}

void printdigitstate(int n,int m, int dig){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<cnt[i][j][dig]<<" ";
        }
        cout<<"\n";
    }
}

void cntdig(int n, int m){
    for(int i=1;i<=n;++i){
        vector< vector <int> >line;
        cnt.push_back(line);
        for(int j=1;j<=m;++j){
            vector < int > line2;
            cnt[i-1].push_back(line2);
            for(int k=0;k<10;++k){
                cnt[i-1][j-1].push_back(0);
            }
        }
    }
    for(int dig=0;dig<10;++dig){
        (sq[0][0]==dig)?cnt[0][0][dig]=1:cnt[0][0][dig]=0;
        for(int j=1;j<m;++j){
            int add=0;
            if(sq[0][j]==dig)add=1;
            cnt[0][j][dig]=cnt[0][j-1][dig]+add;
        }
        for(int i=1;i<n;++i){
            int add=0;
            if(sq[i][0]==dig)add=1;
            cnt[i][0][dig]=cnt[i-1][0][dig]+add;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                int val1 = cnt[i-1][j][dig]; int val2 = cnt[i][j-1][dig];
                int val3 = cnt[i-1][j-1][dig]; int add=(sq[i][j]==dig)?1:0;
                cnt[i][j][dig]=val1+val2+add-val3;
            }
        }
    }
}

void takeinp(int n,int m){
    for(int i=1;i<=n;++i){
        vector<int>line;
        sq.push_back(line);
        for(int j=1;j<=m;++j){
            int x;
            scanf("%d",&x);
            sq[i-1].push_back(x);
        }
    }
}

pair<int, pair<PII,PII> >solvedp(int x1, int y1, int x2, int y2, int n ,int m){
    if(x1>x2 || y1>y2)return make_pair(0,make_pair(dummy,dummy));
    if(x1==x2 && y1==y2)return make_pair(1,make_pair(make_pair(x1,y1),make_pair(x2,y2)));
    PII top = make_pair(x1,y1); PII bottom = make_pair(x2,y2);
    pair<PII,PII>mapentry = make_pair(top,bottom);
    if(areamap.find(mapentry)!=areamap.end())return areamap[mapentry];
    vector<int> dighere = findigcnt(x1,y1,x2,y2,n,m);
    if(dighere[0]==((x2-x1+1)*(y2-y1+1))){
        int area = 1;
        pair<int, pair<PII,PII> >mapval = make_pair(area,make_pair(make_pair(x1,y1),make_pair(x1,y1)));
        areamap[mapentry]=mapval;
    }
    else if(isvalidpalindrome(dighere)){
        int area = (x2-x1+1)*(y2-y1+1);
        pair<int, pair<PII,PII> >mapval = make_pair(area,mapentry);
        areamap[mapentry] = mapval;
    }
    else{
        pair<int,pair<PII,PII> >ans1 = solvedp(x1+1,y1,x2,y2,n,m);
        pair<int,pair<PII,PII> >ans2 = solvedp(x1,y1,x2-1,y2,n,m);
        pair<int,pair<PII,PII> >ans3 = solvedp(x1,y1+1,x2,y2,n,m);
        pair<int,pair<PII,PII> >ans4 = solvedp(x1,y1,x2,y2-1,n,m);
        pair<int,pair<PII,PII> >ans = findmax(ans1,ans2);
        ans = findmax(ans,ans3); ans = findmax(ans,ans4);
        areamap[mapentry]=ans;
     }
     return areamap[mapentry];
}


int main() {
    //cout<<"hello\n";
    int n,m;
    scanf("%d %d",&n,&m);
    takeinp(n,m);
    //cout<<"inp nisi\n";
    cntdig(n,m);
    //cout<<"cnt hoise\n";
    //pair<int,pair<PII,PII>> ans=solve(n,m);
    pair<int,pair<PII,PII>> ans  = solvedp(0,0,n-1,m-1,n,m);
    cout<<ans.first<<"\n";
    cout<<ans.second.first.first<<" "<<ans.second.first.second<<" ";
    cout<<ans.second.second.first<<" "<<ans.second.second.second<<"\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
