/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

vector<PII>fucku;
int pass[200005];
int need[200005];
int passed[200005];
int prep[200005];
int lastday[200005];
int n,m;
void init(int day){
    fucku.clear();
    FREP(i,1,m){
        passed[i]=0;
        prep[i]=0;
        lastday[i]=-1;
    }
    RFREP(i,day,1){
        int ex=pass[i];
        if(ex && lastday[ex]==-1){
            lastday[ex]=i;
        }
    }
    FREP(i,1,m){
        if(lastday[i]!=-1){
            PII p=make_pair(lastday[i],i);
            fucku.PB(p);
        }
    }
    sort(fucku.begin(),fucku.end());
}

bool can(int day){
    int it=0;
    int fin=fucku.size();
    FREP(i,1,day){
        if(pass[i]!=0){
            if(i!=lastday[pass[i]]){
                //prepare for another exam
                int ex=-1;
                while(true){
                    if(it==fin)break;
                    PII p=fucku[it];
                    if(prep[p.second]==need[p.second]){
                        it++;
                    }
                    else{
                        ex=p.second;
                        break;
                    }
                }
                if(ex!=-1){
                    prep[ex]++;
                }
            }
            else{
                int ex=pass[i];
                if(prep[ex]!=need[ex])return false;
                else{
                    passed[ex]=1;
                }
            }
        }
        else{
            int ex=-1;
            while(true){
                if(it==fin)break;
                PII p=fucku[it];
                if(prep[p.second]==need[p.second]){
                    it++;
                }
                else{
                    ex=p.second;
                    break;
                }
            }
            if(ex!=-1){
                prep[ex]++;
            }
        }
    }
    FREP(i,1,m){
        if(passed[i]==0)return false;
    }
    return true;
}

int main(){
    //int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n)
        scanf("%d",&pass[i]);

    FREP(i,1,m)scanf("%d",&need[i]);
    int l=1;
    int r=n;
    int ans=-1;
    while(true){
        int mid=(l+r)/2;
        init(mid);
        bool b=can(mid);
        if(b){
            if(mid==1){
                ans=mid;
                break;
            }
            else{
                init(mid-1);
                bool b2=can(mid-1);
                if(b2){
                    r=mid;
                }
                else{
                    ans=mid;
                    break;
                }
            }
        }
        else{
            if(mid==n){
                break;
            }
            else{
                l=mid+1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
