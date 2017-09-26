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

char sher[1003];

char mor[1003];

int freq1[12];
int freq2[12];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s %s",sher,mor);
    FREP(i,0,(n-1)){
        freq1[mor[i]-'0']++;
        freq2[mor[i]-'0']++;
    }
    int getflick=0;
    FREP(i,0,(n-1)){
        int cur=sher[i]-'0';
        int ase=0;
        FREP(j,cur,9){
            if(freq1[j]>0){
                ase=1;
                freq1[j]--;
                break;
            }
        }
        if(!ase){
            FREP(j,0,(cur-1)){
                if(freq1[j]>0){
                    freq1[j]--;
                    break;
                }
            }
            getflick++;
        }
    }
    int giveflick=0;
    FREP(i,0,(n-1)){
        int cur=sher[i]-'0';
        int ase=0;
        FREP(j,cur+1,9){
            if(freq2[j]>0){
                ase=1;
                freq2[j]--;
                break;
            }
        }
        if(ase){
            giveflick++;
        }
        else{
            FREP(j,0,(cur)){
                if(freq2[j]>0){
                    freq2[j]--;
                    break;
                }
            }
        }
    }
    printf("%d\n%d\n",getflick,giveflick);
    return 0;
}
