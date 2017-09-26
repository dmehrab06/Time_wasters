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

int biggest[203];
int smallest[203];
int mynum[203];

string inc(string given){
    reverse(given.begin(),given.end());
    string ans="";
    int oka=given.size();
    int shuru=given[0]-'0'+1;
    int arr[203];
    arr[0]=shuru;
    FREP(i,1,(oka-1)){
        arr[i]=given[i]-'0'+arr[i-1]/10;
        arr[i-1]%=10;
    }
    arr[oka]=arr[oka-1]/10;
    arr[oka-1]%=10;
    if(arr[oka]==0){
        //same ache
        FREP(i,0,(oka-1)){
            ans.PB(arr[i]+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    else{
        FREP(i,0,(oka)){
            ans.PB(arr[i]+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}

bool issmaller(int n){
    //n should be even
    FREP(i,1,n){
        if(mynum[i]>biggest[i])return false;
    }
    return true;
}

void gensmall(int n){
    //n will be even
    smallest[1]=1;
    FREP(i,2,(n/2)){
        smallest[i]=0;
    }
    FREP(i,(n/2+1),(n-1)){
        smallest[i]=1;
    }
    smallest[n]=0;
}

void genbig(int n){
    //n will be even
    FREP(i,1,(n/2)){
        biggest[i]=9;
    }
    FREP(i,(n/2+1),(n)){
        biggest[i]=8;
    }
}

ifstream fin("anti.in");
ofstream fout("anti.out");

int main(){
    string s;
    while(fin>>s){
        if(s.size()==1 && s[0]=='0')break;
        string sss=inc(s);
        //cout<<sss<<"\n";
        int ll=sss.size();
        FREP(i,0,(ll-1)){
            mynum[i+1]=sss[i]-'0';
        }
       /* cout<<"in mynum ";
        FREP(i,1,ll){
            cout<<mynum[i];
        }
        cout<<"\n";*/
        if(ll%2){
            gensmall(ll+1);
            FREP(i,1,(ll+1)){
                fout<<smallest[i];
            }
            fout<<"\n";
        }
        else{
            genbig(ll);
            if(!issmaller(ll)){
                //fout<<"bello\n";
                gensmall(ll+2);
                FREP(i,1,(ll+2)){
                    fout<<smallest[i];
                }
                fout<<"\n";
            }
            else{
                //eikhane holo moja
                while(1){
                    int start=ll/2+1;
                    while(start<=ll){
                        if(mynum[start]==mynum[ll-start+1]){
                            break;
                        }
                        else{
                            start++;
                        }
                    }
                    if(start>ll){
                        FREP(i,1,ll){
                            fout<<mynum[i];
                        }
                        fout<<"\n";
                        break;
                    }
                    else{
                        mynum[start]++;
                        RFREP(i,start-1,1){
                            mynum[i]=mynum[i]+mynum[i+1]/10;
                            mynum[i+1]%=10;
                        }
                        FREP(i,start+1,ll){
                            mynum[i]=0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
