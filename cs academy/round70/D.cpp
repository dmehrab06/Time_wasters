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

LLI chocos[100005];

int main(){
    LLI n; int k;
    while(cin>>n>>k){
        if(n<k){
            printf("-1\n");
        }
        else{
            int rem = (int)(n%k);
            LLI div = n/k;
            FREP(i,1,k)chocos[i] = div;
            RFREP(i,k,(k-rem+1))chocos[i]++;
            int val2cnt = rem;
            int val1cnt = k-rem;
            int dif = abs(val1cnt-val2cnt);
            int flag1 = 1;
            if(dif>1){
                int l = 1;
                int r = k;
                while(l<=r){
                    chocos[l]--;
                    chocos[r]++;
                    if(chocos[l]<=0){
                        flag1 = 0;
                        break;
                    }
                    l++;
                    r--;
                }
            }
            if(!flag1){
                printf("-1\n");
            }
            else{
                int ll = 1;
                int rr = k;
                vector<LLI>ans;
                while(ll<=rr){
                    ans.PB(chocos[ll]);
                    if(ll!=rr)ans.PB(chocos[rr]);
                    //cout<<chocos[ll]<<" "<<chocos[rr]<<"\n";
                    ll++;
                    rr--;
                }
                int ff = 1;
                FREP(i,1,(int)ans.size()-1){
                    if(ans[i]==ans[i-1]){
                        ff = 0;
                        break;
                    }
                }
                if(ff){
                    FREP(i,0,ans.size()-1){
                        cout<<ans[i]<<" ";
                    }
                    cout<<"\n";
                }
                else{
                    ll = 1;
                    rr = k;
                    vector<LLI>ans2;
                    while(ll<=rr){
                        ans2.PB(chocos[rr]);
                        if(ll!=rr)ans2.PB(chocos[ll]);
                        //cout<<chocos[ll]<<" "<<chocos[rr]<<"\n";
                        ll++;
                        rr--;
                    }
                    int ff3 = 1;
                    FREP(i,1,(int)ans2.size()-1){
                        if(ans2[i]==ans2[i-1]){
                            ff3 = 0;
                            break;
                        }
                    }
                    if(!ff3){
                        cout<<"-1\n";
                    }
                    else{
                        FREP(i,0,ans2.size()-1){
                            cout<<ans2[i]<<" ";
                        }
                        cout<<"\n";
                    }

                }
            }

        }

    }
    return 0;
}
