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

int vneeded[1003];
int willappear[1003];
int sequence[1003];
int colormat[1003][1003];
int degreecompleted[1003];


ifstream fin("achromatic.in");
ofstream fout("achromatic.out");

int main(){
    FREP(i,1,1002){
        int deg=(i-1);
        int needed=deg/2+(deg%2);
        int vneed=needed*i;
        vneeded[i]=vneed;
    }
   /* FREP(i,1,10){
        cout<<vneeded[i]<<" ";
    }
    cout<<"\n";*/
    int n;
    fin>>n;
    if(n==4){
        fout<<2<<"\n";
        fout<<"1 2 1 2\n";
        return 0;
    }
    int ans=-1;
    FREP(i,1,1002){
        if(vneeded[i]>n){
            ans=(i-1);
            break;
        }
    }
    fout<<ans<<"\n";
    int did=0;
    int appearcompleted=0;
    int cur=1;
    while(did<n && appearcompleted<ans){
        sequence[++did]=cur;
        if(willappear[cur]<ans){
            willappear[cur]++;
            if(willappear[cur]==ans){
                appearcompleted++;
            }
        }
        int nxt=-1;
        //cout<<"cur is now "<<cur<<"\n";
        if(did%2){
            FREP(i,1,ans){
                if(i==cur){
                    continue;
                }
                if(colormat[cur][i]==0){
                    nxt=i;
                    break;
                }
            }
        }
        else{
            RFREP(i,ans,1){
                if(i==cur){
                    continue;
                }
                if(colormat[cur][i]==0){
                    nxt=i;
                    break;
                }
            }
        }
        if(nxt==-1){
            int mn=1000000;
            int mni=-1;
            FREP(i,1,ans){
                if(i==cur){
                    continue;
                }
                if(degreecompleted[i]<mn){
                    if(i==1 && (did!=(n-1))){
                        mn=degreecompleted[i];
                        mni=i;
                    }
                    else if(i!=1){
                        mn=degreecompleted[i];
                        mni=i;
                    }
                }
            }
            degreecompleted[cur]++;
            degreecompleted[mni]++;
            cur=mni;

        }
        else{
            colormat[cur][nxt]=1;
            colormat[nxt][cur]=1;
            degreecompleted[cur]++;
            degreecompleted[nxt]++;
            cur=nxt;
        }
    }
    if(did<n){
        FREP(i,2,ans){
            if(i!=cur){
                FREP(k,did+1,n){
                    if((k-did)%2)sequence[k]=i;
                    else sequence[k]=cur;
                }
                break;
            }
        }
    }
    FREP(i,1,n){
        fout<<sequence[i]<<" ";
    }
    fout<<"\n";
    return 0;
}
