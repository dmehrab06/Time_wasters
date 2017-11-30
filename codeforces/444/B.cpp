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

int cubes[4][10];

int highestonedigit(int n){
    int has[10];
    MSET(has,0);
    FREP(i,1,n){
        FREP(j,1,6){
            has[cubes[i][j]]  = 1;
        }
    }
    FREP(i,1,9){
        if(!has[i])return i;
    }
    return -1;
}

bool can2(int dig, int n){
    //cout<<"cheking "<<dig<<"\n";
    int need1 = dig%10;
    int need2 = dig/10;
    vector<int>has1;
    vector<int>has2;
    FREP(i,1,n){
        FREP(j,1,6){
            if(cubes[i][j]==need1){
                has1.PB(i);
            }
            if(cubes[i][j]==need2){
                has2.PB(i);
            }
        }
    }
    //FREP(i,0,has1.size()-1){cout<<has1[i]<<" ";}
    //cout<<"\n";
    //FREP(i,0,has2.size()-1){cout<<has2[i]<<" ";}
    //cout<<"\n";
    FREP(i,0,has1.size()-1){
        FREP(j,0,has2.size()-1){
            int one = has1[i];
            int two = has2[j];
            if((one!=two)){
                return true;
            }
        }
    }
    return false;
}

int highesttwodigit(int n){
    FREP(i,10,99){
        if(!can2(i,n))return i;
    }
    return -1;
}

bool can3(int dig, int n){
    int need1 = dig%10;
    int need2 = (dig/10)%10;
    int need3 = dig/100;
    vector<int>has1;
    vector<int>has2;
    vector<int>has3;
    FREP(i,1,n){
        FREP(j,1,6){
            if(cubes[i][j]==need1){
                has1.PB(i);
            }
            if(cubes[i][j]==need2){
                has2.PB(i);
            }
            if(cubes[i][j]==need3){
                has3.PB(i);
            }
        }
    }
    FREP(i,0,has1.size()-1){
        FREP(j,0,has2.size()-1){
            FREP(k,0,has3.size()-1){
                int one = has1[i];
                int two = has2[j];
                int three = has3[k];
                if((one!=two) && (two!=three) && (three!=one)){
                    return true;
                }
            }
        }
    }
    return false;
}

int highestthreedigit(int n){
    FREP(i,100,999){
        if(!can3(i,n))return i;
    }
    return -1;
}

int main(){

    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        FREP(j,1,6){
            scanf("%d",&cubes[i][j]);
        }
    }
    int one = highestonedigit(n);
    if(one!=-1){
        printf("%d\n",one-1);
    }
    else{
        int two = highesttwodigit(n);
        if(two!=-1){
            printf("%d\n",two-1);
        }
        else{
            int three = highestthreedigit(n);
            if(three!=-1){
                printf("%d\n",three-1);
            }
            else{
                printf("999\n");
            }
        }
    }
    return 0;

}
