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

vector<PII>blocks;


int cnt[100005];

bool issorted(){
    FREP(i,0,(int)sorter.size()-1){
        if(mainer[i]!=sorter[i]){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    FREP(i,1,n){
        int a; cin>>a;
        mainer.PB(a);
        sorter.PB(a);
    }
    SORTV(sorter);
    if(issorted()){
        FREP(i,0,mainer.size()-1){
            cnt[mainer[i]]++;
        }
        LLI s = 0;
        FREP(i,0,100000){
            s = s+ ((LLI)cnt[i]*(LLI)(cnt[i]+1))/2;
        }
        cout<<s<<"\n";
        cout<<"1 1\n";
    }
    else{
        mainer.PB(1000000);
        int cntok = 0;
        int cntnotok = -1;
        FREP(i,1,mainer.size()-1){
            if(mainer[i]>mainer[i-1]){
                if(cntnotok!=-1){
                    blocks.PB(make_pair(cntok,cntnotok));
                    cntnotok = -1;
                }
                cntok = i;
            }
            else if(mainer[i]<mainer[i-1]){
                cntnotok = i;
            }
            else if(mainer[i]==mainer[i-1]){
                if(cntnotok!=-1){
                    cntnotok = i;
                }
            }
        }
        if(cntnotok!=-1){
            blocks.PB(make_pair(cntok,cntnotok));
            cntnotok = -1;
        }
        if(blocks.size()>1){
            cout<<"0\n";
            return 0;
        }
        else{
            //cout<<blocks[0].first<<" "<<blocks[0].second<<"\n";
            VI nn;
            FREP(i,blocks[0].first,blocks[0].second){
                nn.PB(mainer[i]);
            }
            REVV(nn);
            FREP(i,blocks[0].first,blocks[0].second){
                mainer[i]=nn[i-blocks[0].first];
            }
            //reverse(mainer.begin()+blocks[0].first,mainer.begin()+blocks[0].second);
            //FREP(i,0,mainer.size()-1)cout<<mainer[i]<<" ";
            //cout<<"\n";
            if(!issorted()){
                cout<<"0\n";
                return 0;
            }
            else{
                set<int>differ;
                FREP(i,blocks[0].first,blocks[0].second){
                    differ.insert(mainer[i]);
                }
                LLI way = 1;
                if(differ.size()==1){
                    LLI len  =blocks[0].second-blocks[0].first+1;
                    way = len*(len+1);
                    way/=2;
                }
                cout<<way<<"\n";
                cout<<blocks[0].first+1<<" "<<blocks[0].second+1<<"\n";
            }
        }
    }
    return 0;
}
