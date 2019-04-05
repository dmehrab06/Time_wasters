#include <bits/stdc++.h>

using namespace std;

//int divcount[10000001];
//int iscomp[10000001];

int arr[10003];
//int dp[10002][5002];

int getsum(int l, int r){
    if(l>r)return 0;
    if(l==0)return arr[r];
    return arr[r]-arr[l-1];
}

int divcount(int n){
    int ss = sqrt(n);
    int div = 0;
    for(int i=1;i<=ss;++i){
        if((n%i)==0){
            div++;
            int j = n/i;
            if(i!=j)div++;
        }
    }
    return div;
}

long long int penalty(vector<int>& shuffler, int n){
    int l = 0;
    long long int s = 0;
    //cout<<"shuffler now:\n";
    for(int i = 0;i<shuffler.size();++i){
        //cout<<shuffler[i]<<"\n";
        int r = shuffler[i]-1;
        //int ss = getsum(l,r);
        //cout<<"sum from "<<l<<" to "<<r<<" is "<<getsum(r,l);
        s = s+divcount(getsum(l,r));
        l = r+1; 
    }
    //cout<<"\n";
    s = s+divcount(getsum(l,n-1));
    //cout<<"penalty for this is: "<<s<<"\n\n";
    return s;
}

void solve(int n, int k){
    srand(time(0));
    vector<int>poss;
    vector<int>ans;
    long long int minpenalty = 1000000000000000000; 
    for(int i = 1;i<=(n-1);++i){
        poss.push_back(i);
    }
    //shuffle and take k from them
    int maxiter = 200;
    for(int i = 1;i<=maxiter; ++i){
        random_shuffle(poss.begin(),poss.end());
        vector<int>curposs;
        for(int j = 0; j<k; ++j){
            curposs.push_back(poss[j]);
        }
        sort(curposs.begin(),curposs.end());
        long long int pen = penalty(curposs,n);
        if(pen<minpenalty){
            minpenalty = pen;
            ans = curposs;
        }
    }
    for(int i = 0;i<ans.size();++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

/*void sieve(){
    divcount[1] = 1;
    for(int i = 2;i<=1000000; ++i){
        if(iscomp[i]==0){
            for(int j = (i+i); j<=1000000; j+=i){
                if(iscomp[j]==0){
                    iscomp[j] = i;
                }
            }    
        }
    }
    for(int i = 2; i<=1000000; ++i){
        if(iscomp[i]==0){
            divcount[i] = 2;
        }
        else{
            int s = 1;
            int t = i;
            while(t>1){
                int divv = iscomp[t];
                if(divv==0){
                    s = s<<1;
                    break;
                }
                int tot = 0;
                while((t%divv)==0){
                    t/=divv;
                    tot++;
                }
                s = s*(tot+1);
            }
            divcount[i] = s;
        }
    }
}*/

int main(){
    //sieve();
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    
    for(int i = 1;i<n; ++i)arr[i] = arr[i-1]+arr[i];

    solve(n,k);
    return 0;
}