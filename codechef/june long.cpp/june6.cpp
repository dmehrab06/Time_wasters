#include <bits/stdc++.h>
#define MDD 1000000007

using namespace std;

int P[1003][1003];
int P2[1003][1003];
int Cumsum[1003][1003];

void CumsumMatrix(int N, int M){
    for(int i=0;i<=N;++i){
        Cumsum[i][0]=0;
    }
    for(int j=0;j<=M;++j){
        Cumsum[0][j]=0;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            Cumsum[i][j]=Cumsum[i-1][j]+Cumsum[i][j-1]-Cumsum[i-1][j-1]+P2[i][j];
        }
    }

}

long long int RangeSum(int x1, int y1, int x2, int y2){
    int mat1=Cumsum[x2][y2];
    int mat2=Cumsum[x1-1][y2];
    int mat3=Cumsum[x2][y1-1];
    int mat4=Cumsum[x1-1][y1-1];
    long long int ans=(long long int)mat1+(long long int)mat4-(long long int)mat2-(long long int)mat3;
    return ans; // ans->x represent Row number sored in ans and similarly ans->y represent column store in ans
}

long long int modpow(long long int b, long long int x,long long int MD)
{
    if(x==0){
        return 1;
    }
    if(x==1){
        return b;
    }
    long long int hf=modpow(b,x/2,MD);
    if(x%2==0){
        return (hf*hf)%MD;
    }
    else{
        return (((hf*hf)%MD)*b)%MD;
    }
}
long long int findMMI(long long int n,long long int M)
{
    return modpow(n,M-2,M);
}

int LR[1003][1003];
int RL[1003][1003];
int maxinwindow[1003][1003];

void slidewindow(int a, int b, int n, int m){
    int extra=1;
    for(int i=1;i<=n;i++){
        for(int j=1;(j+b-1)<=m;){
            LR[i][j]=P2[i][j];
            int endblock=j+b-1;
            int k=j+1;
            while(k<=endblock){
                LR[i][k]=max(LR[i][k-1],P2[i][k]);
                k++;
            }
            j+=b;
            extra=j;
        }
        if(extra<=m){
            LR[i][extra]=P2[i][extra];
            int endblock=m;
            int k=extra+1;
            while(k<=endblock){
                LR[i][k]=max(LR[i][k-1],P2[i][k]);
                k++;
            }
        }
    }
    int mblockend=(m/b)*b;
    for(int i=1;i<=n;i++){
        if(mblockend!=m){
            RL[i][m]=P2[i][m];
            int endblock=mblockend+1;
            int k=m-1;
            while(k>=endblock){
                RL[i][k]=max(RL[i][k+1],P2[i][k]);
                k--;
            }
        }
        for(int j=mblockend;(j-b+1)>=1;){
            RL[i][j]=P2[i][j];
            int endblock=j-b+1;
            int k=j-1;
            while(k>=endblock){
                RL[i][k]=max(RL[i][k+1],P2[i][k]);
                k--;
            }
            j-=b;
        }
    }
    int lefttorightwindowsize=m-b+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=lefttorightwindowsize;++j){
            maxinwindow[i][j]=max(RL[i][j],LR[i][j+b-1]);
        }
    }
    //ekbar max bair kora hoia gese , eibar maxwindow er upor punoray//
    extra=1;
    for(int j=1;j<=lefttorightwindowsize;j++){
        for(int i=1;(i+a-1)<=n;){
            LR[i][j]=maxinwindow[i][j];
            int endblock=i+a-1;
            int k=i+1;
            while(k<=endblock){
                LR[k][j]=max(LR[k-1][j],maxinwindow[k][j]);
                k++;
            }
            i+=a;
            extra=i;
        }
        if(extra<=n){
            LR[extra][j]=maxinwindow[extra][j];
            int endblock=n;
            int k=extra+1;
            while(k<=endblock){
                LR[k][j]=max(LR[k-1][j],maxinwindow[k][j]);
                k++;
            }
        }
    }
    int nblockend=(n/a)*a;
    for(int j=1;j<=lefttorightwindowsize;j++){
        if(nblockend!=n){
            RL[n][j]=maxinwindow[n][j];
            int endblock=nblockend+1;
            int k=n-1;
            while(k>=endblock){
                RL[k][j]=max(RL[k+1][j],maxinwindow[k][j]);
                k--;
            }
        }
        for(int i=nblockend;(i-a+1)>=1;){
            RL[i][j]=maxinwindow[i][j];
            int endblock=i-a+1;
            int k=i-1;
            while(k>=endblock){
                RL[k][j]=max(RL[k+1][j],maxinwindow[k][j]);
                k--;
            }
            i-=a;
        }
    }
    int toptobottomwindowsize=n-a+1;
    for(int j=1;j<=lefttorightwindowsize;j++){
        for(int i=1;i<=toptobottomwindowsize;++i){
            maxinwindow[i][j]=max(RL[i][j],LR[i+a-1][j]);
        }
    }
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            scanf("%d",&P2[i][j]);
        }
    }
    CumsumMatrix(N,M);
    int q;
    scanf("%d",&q);
     //to find the sum later on
    for(int k=1;k<=q;++k){
        int a,b;
        scanf("%d %d",&a,&b);
        slidewindow(a,b,N,M);

        long long int ans=1000000000000000000;
        for(int i=1;(i+a-1)<=N;++i){
            for(int j=1;(j+b-1)<=M;++j){
                long long int s=RangeSum(i,j,i+a-1,j+b-1);
                //int mx=RMQ(i,j,i+a-1,j+b-1);
               // cout<<s<<" "<<mx<<"\n";
                int mx=maxinwindow[i][j];
              //  cout<<mx<<"\n";
                long long int cur=(long long int)mx*a*b-s;
                if(cur<ans){
                    ans=cur;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

