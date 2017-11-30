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

string genstring(int mask, int len){
    string res = "";
    int msk  = 1;
    FREP(i,1,len){
        if(mask&msk){
            res.PB('b');
        }
        else{
            res.PB('a');
        }
        msk<<=1;
    }
    return res;
}

int longestpalin(string st){
    int ll = -1;
    FREP(i,0,st.size()-1){
        FREP(j,i,st.size()-1){
            int f = 1;
            int ki = i;
            int kj = j;
            while(ki<kj){
                if(st[ki]!=st[kj]){
                    f=0;
                    break;
                }
                ki++;
                kj--;
            }
            if(f){
                if((j-i+1)>ll){
                    ll = j-i+1;
                }
            }
        }
    }
    return ll;
}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ll,A;
        scanf("%d %d",&ll,&A);
        if(A==1){
            string rr = "";
            FREP(i,0,(ll-1))rr.PB('a');
            cout<<ll<<" "<<rr<<"\n";
        }
        else if(A==2){
            if(ll<=8){
                int mxmask = (1<<ll)-1;
                int mnn = 100000;
                string rr  = "";
                FREP(i,0,mxmask){
                    string ss  = genstring(i,ll);
                    int aa =  longestpalin(ss);
                    if(aa<mnn){
                        mnn=aa;
                        rr = ss;
                    }
                }
                cout<<mnn<<" "<<rr<<"\n";
            }
            else{
                char arr[6] = {'a','a','b','a','b','b'};
                int need = ll-2;
                string rr = "";
                FREP(i,1,need){
                    rr.PB(arr[(i-1)%6]);
                }
                rr = "aa"+rr;
                cout<<4<<" "<<rr<<"\n";
            }
        }
        else{
            char arr[3]={'a','b','c'};
            string rr = "";
            FREP(i,0,ll-1){
                rr.PB(arr[i%3]);
            }
            cout<<1<<" "<<rr<<"\n";
        }
    }
    return 0;

}
