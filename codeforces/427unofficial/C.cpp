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

int starbright[21][103][103];
int cumbright[21][103][103];

pair<int,PII> starinfo[12][100005];

void takeinp(int stars, int mxxbright){
    FREP(i,1,stars){
        scanf("%d %d %d",&starinfo[0][i].second.first,&starinfo[0][i].second.second,&starinfo[0][i].first);
    }
    FREP(time,1,11){
        FREP(i,1,stars){
            starinfo[time][i].first = starinfo[time-1][i].first+1;
            if(starinfo[time][i].first>mxxbright)starinfo[time][i].first = 0;
            starinfo[time][i].second.first = starinfo[time-1][i].second.first;
            starinfo[time][i].second.second = starinfo[time-1][i].second.second;
        }
    }
    FREP(time,0,11){
        FREP(i,1,stars){
            int x = starinfo[time][i].second.first;
            int y = starinfo[time][i].second.second;
            int brght = starinfo[time][i].first;
            starbright[time][x][y]+=brght;
        }
    }
}

void calccumsum(int time, int x, int y){
    //memset(cumbright,0,sizeof(cumbright));
    cumbright[time][1][1] = starbright[time][1][1];
    FREP(i,2,x)cumbright[time][i][1]=cumbright[time][i-1][1]+starbright[time][i][1];
    FREP(i,2,y)cumbright[time][1][i]=cumbright[time][1][i-1]+starbright[time][1][i];
    FREP(i,2,x){
        FREP(j,2,y){
            cumbright[time][i][j]+=cumbright[time][i-1][j];
            cumbright[time][i][j]+=cumbright[time][i][j-1];
            cumbright[time][i][j]+=starbright[time][i][j];
            cumbright[time][i][j]-=cumbright[time][i-1][j-1];
        }
    }
}

void docum(){
    FREP(i,0,11){
        calccumsum(i,101,101);
    }
    /*FREP(time,0,11){
        cout<<"time : "<<time<<"     time: "<<time<<"\n";
        FREP(i,1,5){
            FREP(j,1,5){
                cout<<starbright[time][i][j]<<" ";
            }
            cout<<"     ";
            FREP(j,1,5){
                cout<<cumbright[time][i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }*/
}

int calc(int time, int x1, int y1, int x2, int y2){
    int ans1 = cumbright[time][x2][y2];
    int ans2 = cumbright[time][x1-1][y2];
    int ans3 = cumbright[time][x2][y1-1];
    int ans4 = cumbright[time][x1-1][y1-1];
    return ans1-ans2-ans3+ans4;
}

int ansquery(int tt, int x1, int x2, int y1, int y2){
        return calc(tt,x1,y1,x2,y2);

}


int main(){
    int n,q,c;
    scanf("%d %d %d",&n,&q,&c);
    takeinp(n,c);
    docum();
    FREP(i,1,q){
        int t, x1, y1,x2,y2;
        scanf("%d %d %d %d %d",&t,&x1,&y1,&x2,&y2);
        printf("%d\n",ansquery(t%(c+1),x1,x2,y1,y2));
    }
    return 0;
}
