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
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

VI mainer;
VI sorter;

int cnt[100005];

vector<PII>blocks;

int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        int a; cin>>a;
        mainer.PB(a);
        sorter.PB(a);
    }
    SORTV(mainer); SORTV(sorter);
    int l = -1; int r = -1;
    FREP(i,0,mainer.size()-1){
        if(mainer[i]==sorter[i]){
            if(l!=-1){
                blocks.PB(make_pair(l,r));
                l = -1;
                r = -1;
            }
        }
        else{
            if(l==-1){
                l = i;
                r = i;
            }
            else{
                r = i;
            }
        }
    }
    if(l!=-1)blocks.PB(make_pair(l,r));
    if(blocks.size()>1){
        cout<<"0\n";
    }
    else{
        if(blocks.size()==0){
            FREP(i,0,mainer.size()-1){
                cnt[mainer[i]]++;
            }
            LLI s = 0;
            FREP(i,0,100000){
                s = s+ ((LLI)i*(LLI)(i+1))/2;
            }
            cout<<s<<"\n";
        }
        else if(blocks.size()==1){
            set<int>diff;
            FREP(i,blocks[0].first,blocks[0].second){
                diff.insert(mainer[i]);
            }
            if(diff.size()>1){
                sort(mainer.begin()+blocks[0].first,mainer.begin()+blocks[0].second);
                FREP(i,0,mainer.size()-1){
                    if(mainer[i]!=sorter[i]){
                        cout<<"0\n";
                        return 0;
                    }
                }
                cout<<"1\n";
                cout<<blocks[0].first+1<<" "<<blocks[0].second+1<<"\n";
            }
            else{
                sort(mainer.begin()+blocks[0].first,mainer.begin()+blocks[0].second);
                FREP(i,0,mainer.size()-1){
                    if(mainer[i]!=sorter[i]){
                        cout<<"0\n";
                        return 0;
                    }
                }
                LLI len = blocks[0].second-blocks[0].first+1;
                LLI ans = (len)*(len+1)/2;
                cout<<ans<<"\n";
                cout<<blocks[0].first+1<<" "<<blocks[0].second+1<<"\n";
            }
        }
    }
    return 0;
}
