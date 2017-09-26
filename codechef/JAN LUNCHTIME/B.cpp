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

int orig[56];
int tempa[56];
int tempb[56];

vector<int>movea;
vector<int>moveb;

void init(){
    movea.clear();
    moveb.clear();
}

int calca(int n){
    int c=0;
    FREP(i,1,n){
        FREP(j,(i+1),n){
            if(tempa[i]>tempa[j]){
                c++;
            }
        }
    }
    return c;
}

int calcb(int n){
    int c=0;
    FREP(i,1,n){
        FREP(j,(i+1),n){
            if(tempb[i]>tempb[j]){
                c++;
            }
        }
    }
    return c;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            scanf("%d",&orig[i]);
            tempa[i]=orig[i];
            tempb[i]=orig[i];
        }
        //doing with tempa
        FREP(i,1,n){
            int curpos;
            FREP(k,1,n){
                if(tempa[k]==i){
                    curpos=k;
                    break;
                }
            }
            if(curpos==i){
                continue;
            }
            else if(curpos<i){
                while(curpos!=i){
                    if(tempa[curpos+1]!=(curpos+1)){
                        movea.PB(curpos);
                        swap(tempa[curpos+1],tempa[curpos]);
                        curpos++;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                while(curpos!=i){
                    if(tempa[curpos-1]!=(curpos-1)){
                        movea.PB(curpos-1);
                        swap(tempa[curpos-1],tempa[curpos]);
                        curpos--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        RFREP(i,n,1){
            int curpos;
            FREP(k,1,n){
                if(tempb[k]==i){
                    curpos=k;
                    break;
                }
            }
            if(curpos==i){
                continue;
            }
            else if(curpos<i){
                while(curpos!=i){
                    if(tempb[curpos+1]!=(curpos+1)){
                        moveb.PB(curpos);
                        swap(tempb[curpos+1],tempb[curpos]);
                        curpos++;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                while(curpos!=i){
                    if(tempb[curpos-1]!=(curpos-1)){
                        moveb.PB(curpos-1);
                        swap(tempb[curpos-1],tempb[curpos]);
                        curpos--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        int aperm=calca(n);
        int bperm=calcb(n);
        cout<<aperm<<" "<<bperm<<"\n";
        if(aperm<bperm){
            int l=movea.size();
            printf("%d\n",l);
            FREP(k,0,(l-1)){
                printf("%d ",movea[k]);
            }
            printf("\n");
        }
        else{
            int l=moveb.size();
            printf("%d\n",l);
            FREP(k,0,(l-1)){
                printf("%d ",moveb[k]);
            }
            printf("\n");
        }
        //printf("%d\n",total);
    }
    return 0;
}
