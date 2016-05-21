#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int indiv2[100006];
int indiv1[100006];


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        indiv2[i]=0;
        indiv1[i]=0;
    }
    bool stillpossible=true;
    int mindiv1=10000000;
    int mindiv2=10000000;
    int mxdiv1=-1;
    int mxdiv2=-1;
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d %d",&u,&v);
        int mx=max(u,v);
        int mn=min(u,v);
        if(indiv2[mx] || indiv1[mn]){
            stillpossible=false;
        }
        if(stillpossible){
            indiv2[mn]=1;
            indiv1[mx]=1;
            if(mn<mindiv2){
                mindiv2=mn;
            }
            if(mn>mxdiv2){
                mxdiv2=mn;
            }
            if(mx<mindiv1){
                mindiv1=mx;
            }
            if(mx>mxdiv1){
                mxdiv1=mx;
            }
            if(mindiv1<mxdiv2){
                stillpossible=false;
            }
        }
    }
    if(!stillpossible){
        cout<<"0\n";
    }
    else{
        long long int ans=1;
        int left=mindiv1-mxdiv2;
        //cout<<mindiv1<<" "<<mxdiv2<<"\n";
        ans=left;
        if(m==0)ans=n-1;
        else if(mindiv1<mxdiv2){
            ans=0;
        }
        cout<<ans<<"\n";
    }
    return 0;

}
