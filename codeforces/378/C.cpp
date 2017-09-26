/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int origqueue[503];
int afterqueue[503];
PII rngqueue[503];
int rngsize=0;


typedef tree<
LLI,
null_type,
less<LLI>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector <PII> ans;

bool check(int n, int m){
    int curm=1;
    int curl=0;
    int curr=0;
    LLI cursum=0;
    while(curr<n){
        curr++;
        cursum+=origqueue[curr];
        if(cursum==afterqueue[curm]){
            PII oka=make_pair(curl+1,curr);
            rngqueue[++rngsize]=oka;
            cursum=0;
            curl=curr;
            curm++;
        }
        else if(cursum>afterqueue[curm]){
            return false;
        }
    }
    if(curm>m && cursum==0 && curl==n && rngsize==m)return true;
    return false;
}
int main(){
    int n,m;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&origqueue[i]);
    }
    scanf("%d",&m);
    FREP(i,1,m){
        scanf("%d",&afterqueue[i]);
    }
    if(!check(n,m)){
        printf("NO\n");
    }
    else{
        //ordered_set<LLI>::iterator it;
        bool f=true;
        RFREP(i,rngsize,1){
            vector<int>curset;
            vector<int>origpos;
            int curl=rngqueue[i].first;
            int curr=rngqueue[i].second;
            int mxwt=-1;
            int mxpos=-1;
            FREP(j,curl,curr){
                //if(origqueue[i]>mxwt)mxwt=origqueue
                curset.PB(origqueue[j]);
                origpos.PB(j);
            }
            int l=curset.size();
            int ll=0;
            int rr=(l-1);
            if(ll==rr)continue;
            FREP(j,ll,rr){
                if(curset[j]>mxwt){
                    mxwt=curset[j];
                    mxpos=j;
                }
                else if(curset[j]==mxwt){
                    if(j==ll){
                        if((rr>ll) && curset[j+1]<mxwt)
                            mxpos=j;
                    }
                    else if(j==rr){
                        if((rr>ll) && curset[j-1]<mxwt)
                            mxpos=j;
                    }
                    else{
                        if((rr-ll+1)>2 && (curset[j-1]<mxwt || curset[j+1]<mxwt)){
                            mxpos=j;
                        }
                    }
                }
            }
            //cout<<"in range "<<curl<<" "<<curr<<" mxwt "<<mxwt<<" maxpos "<<mxpos<<"\n";
            if(mxpos==rr && curset[mxpos-1]==mxwt){
                f=false;
                break;
            }
            else if(mxpos==ll && curset[mxpos+1]==mxwt){
                f=false;
                break;
            }
            else{
                if(mxpos==rr){
                    int bakiase=(rr-ll);
                    //bame sob khabe
                    int orig=origpos[mxpos];
                    FREP(k,1,bakiase){
                        ans.push_back(make_pair(orig,-1));
                        orig--;
                    }
                }
                else if(mxpos==ll){
                    int bakiase=(rr-ll);
                    //bame sob khabe
                    int orig=origpos[mxpos];
                    FREP(k,1,bakiase){
                        ans.push_back(make_pair(orig,1));
                    }
                }
                else{
                    //try to move right first
                    if(curset[mxpos+1]<mxwt){
                        int bakiase=rr-ll;
                        int rght=rr-mxpos;
                        int lft=bakiase-rght;
                        int orig=origpos[mxpos];
                        FREP(k,1,rght){
                            ans.push_back(make_pair(orig,1));
                        }
                        FREP(k,1,lft){
                            ans.push_back(make_pair(orig,-1));
                            orig--;
                        }
                    }
                    else{
                        if(curset[mxpos-1]==mxwt){
                            f=false;
                            break;
                        }
                        else{
                            int bakiase=rr-ll;
                            int rght=rr-mxpos;
                            int lft=bakiase-rght;
                            int orig=origpos[mxpos];

                            FREP(k,1,lft){
                                ans.push_back(make_pair(orig,-1));
                                orig--;
                            }
                            FREP(k,1,rght){
                                ans.push_back(make_pair(orig,1));
                            }
                        }
                    }
                }
            }
        }
        if(!f){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            int lll=ans.size();
            FREP(i,0,(lll-1)){
                printf("%d ",ans[i].first);
                if(ans[i].second==-1){
                    printf("L\n");
                }
                else{
                    printf("R\n");
                }
            }
        }
    }
    return 0;
}
