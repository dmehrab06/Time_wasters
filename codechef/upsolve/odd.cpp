#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


int leftconfig[78];
int rightconfig[78];
int leftconfig2[78];
int rightconfig2[78];
int lsize;
int rsize;
//1=2*n
//2=2*n+1
int total;

void swapleftright(){
    int temparray[78];
    for(int i=1;i<=lsize;++i){
        temparray[i]=leftconfig[i];
    }
    int tsize=lsize;
    for(int i=1;i<=rsize;++i){
        leftconfig[i]=rightconfig[i];
    }
    lsize=rsize;
    for(int i=1;i<=tsize;++i){
        rightconfig[i]=temparray[i];
    }
    rsize=tsize;
    return;
}

long long int binsearch(int l,int r){
    //cout<<"left "<<l<<" right "<<r<<"\n";
    if(l>r){
        return 0;
    }
    int mid=(l+r)/2;
    //cout<<" checking in parent "<<mid<<"\n";
    long long int lmax=mid;
    for(int i=1;i<=lsize;++i){
        lmax=lmax*2;
        if(leftconfig[i]==2){
            lmax++;
        }
        if(lmax>total){
            lmax=-1;
            break;
        }
    }
    long long int rmax=mid;
    for(int i=1;i<=rsize;++i){
        rmax=rmax*2;
        if(rightconfig[i]==2){
            rmax++;
        }
        if(rmax>total){
            rmax=-1;
            break;
        }
    }
    if(lmax==-1 || rmax==-1){
        return binsearch(l,mid-1);
    }
    else{
        int mid2=mid+1;
        if(mid2>total){
            return mid;
        }
        long long int lmax2=mid2;
        for(int i=1;i<=lsize;++i){
            lmax2=lmax2*2;
            if(leftconfig[i]==2){
                lmax2++;
            }
            if(lmax2>total){
                lmax2=-1;
                break;
            }
        }
        long long int rmax2=mid2;
        for(int i=1;i<=rsize;++i){
            rmax2=rmax2*2;
            if(rightconfig[i]==2){
                rmax2++;
            }
            if(rmax2>total){
                rmax2=-1;
                break;
            }
        }
        if(lmax2==-1 || rmax2==-1){
            return mid;
        }
        else{
            return binsearch(mid+1,r);
        }
    }

}



int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);

    while(t--){
        int u,v;
        scanf("%d %d %d",&total,&u,&v);
        //if(u>v){
          //  int temp=u;
            //u=v;
            //v=temp;
        //}
        map<int,int>LCA;
        int paru=u;
        int ltoreach=0;
        while(paru>=1){
            LCA[paru]=ltoreach;
            if(paru%2){
                leftconfig2[ltoreach]=2;
            }
            else{
                leftconfig2[ltoreach]=1;
            }
            ltoreach++;
            paru/=2;

        }
        int parv=v;
        int rtoreach=0;
        while(parv>=1){

            if(parv%2){
                rightconfig2[rtoreach]=2;
            }
            else{
                rightconfig2[rtoreach]=1;
            }
            if(LCA.find(parv)!=LCA.end())break;
            rtoreach++;
            parv/=2;

        }
        //cout<<parv<<"\n";
        lsize=LCA[parv];
        int ll=lsize-1;
        rsize=rtoreach;
        int rr=rsize-1;
        for(int i=1;ll>=0;++i){
            leftconfig[i]=leftconfig2[ll];
            ll--;
        }
        for(int i=1;rr>=0;++i){
            rightconfig[i]=rightconfig2[rr];
            rr--;
        }
        if((lsize>=1 && leftconfig[1]==2) || (rsize>=1 && rightconfig[1]==1)){
            swapleftright();
        }
        /*cout<<"left\n";
        for(int i=1;i<=lsize;++i){
            cout<<leftconfig[i]<<"\n";

        }
        cout<<"right\n";
        for(int i=1;i<=rsize;++i){
            cout<<rightconfig[i]<<"\n";

        }
        cout<<"sesh\n";*/
        if(u>total || v>total){
            cout<<"0\n";
        }
        else{
            long long int ans=binsearch(1,total);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
