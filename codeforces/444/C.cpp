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

int groups[13][6][4]={{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20},{21,22,23,24}},
                      {{22,24,2,4},{1,6,3,8},{5,7,10,12},{13,14,15,16},{17,18,19,20},{21,9,23,11}},
                      {{5,2,7,4},{9,6,11,8},{22,10,24,12},{13,14,15,16},{17,18,19,20},{21,1,23,3}},
                      {{1,8,3,6},{5,10,7,12},{9,21,11,23},{13,14,15,16},{17,18,19,20},{2,22,4,24}},
                      {{1,21,3,23},{5,2,7,4},{9,6,11,8},{13,14,15,16},{17,18,19,20},{10,22,12,24}},
                      {{1,2,17,19},{5,6,7,8},{14,16,11,12},{13,3,15,4},{9,10,18,20},{21,22,23,24}},
                      {{1,2,14,16},{5,6,7,8},{17,19,11,12},{13,9,15,10},{3,18,4,20},{21,22,23,24}},
                      {{1,2,13,15},{5,6,7,8},{17,19,11,12},{10,14,9,16},{3,18,4,20},{21,22,23,24}},
                      {{11,12,13,15},{5,6,7,8},{17,1,19,2},{3,14,4,16},{10,18,9,20},{21,22,23,24}},
                      {{1,2,3,4},{13,14,7,8},{9,10,11,12},{21,22,15,16},{5,6,19,20},{17,18,23,24}},
                      {{1,2,3,4},{17,18,7,8},{9,10,11,12},{5,6,15,16},{21,22,19,20},{13,14,23,24}},
                      {{1,2,3,4},{9,10,11,12},{13,14,7,8},{5,6,19,20},{17,18,23,24},{21,22,15,16}},
                      {{1,2,3,4},{9,10,11,12},{13,14,23,24},{5,6,15,16},{17,18,7,8},{21,22,19,20}},
                    };

int sqcolor[25];

bool check(){
    FREP(i,1,12){
        int ff = 1;
        FREP(j,0,5){
            int gpcolor = sqcolor[groups[i][j][0]];
            int f = 1;
            FREP(k,0,3){
                if(sqcolor[groups[i][j][k]]!=gpcolor){
                    f = 0;
                    break;
                }
            }
            if(!f){
                ff = 0;
                break;
            }
        }
        if(ff){
            return true;
        }
    }
    return false;
}

int main(){

    FREP(i,1,24)scanf("%d",&sqcolor[i]);
    if(check()){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;

}
