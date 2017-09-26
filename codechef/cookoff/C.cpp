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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,b;
        scanf("%d %d",&n,&b);
        if(b==0){
            if(n%2){
                printf("YES\n");
                FREP(i,1,(n-1)){
                    printf("%d %d\n",i,i+1);
                }
            }
            else{
                if(n==2){
                    printf("NO\n");
                }
                else{
                    printf("YES\n");
                    FREP(i,2,n){
                        printf("%d %d\n",1,i);
                    }
                }
            }
        }
        else if(b==1){
            if(n%2){
                if(n==3){
                    printf("NO\n");
                }
                else{
                    printf("YES\n");
                    FREP(i,1,(n-3)){
                        printf("%d %d\n",i,i+1);
                    }
                    printf("%d %d\n",n-2,n-1);
                    printf("%d %d\n",n-2,n);
                }
            }
            else{
                printf("YES\n");
                FREP(i,1,(n-1)){
                    printf("%d %d\n",i,i+1);
                }
            }
        }
        else{
            int minneed = b*4;
            if(n<minneed){
                printf("NO\n");
            }
            else{
                printf("YES\n");
                int rrad = b;
                int lcomps = 2*b-1;
                FREP(i,1,b){
                    printf("%d %d\n",i,i+1);
                }
                cout<<"first part\n";
                FREP(i,1,rrad){
                    printf("%d %d\n",b+1+(i-1),b+1+i);
                }
                cout<<"second part\n";
                FREP(i,1,lcomps){
                    printf("%d %d\n",1,b+rrad+1+i);
                }
                cout<<"third part\n";
                int extra = n-minneed;
                FREP(i,1,extra){
                    if(i%2){
                        printf("%d %d\n",1,b+rrad+1+lcomps+i);
                    }
                    else{
                        printf("%d %d\n",b+rrad,b+rrad+1+lcomps+i);
                    }
                }
                cout<<"Extra part\n";
            }
        }
        //printf("%d\n",min(downsegment,upsegment));
    }
    return 0;
}
