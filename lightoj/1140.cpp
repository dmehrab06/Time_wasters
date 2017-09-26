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

LLI ncr[14][14];
LLI arr2[14];
LLI arr1[14];
LLI tenpow[14];
LLI prefix0[14];
LLI calc(int n, int r){
	if(n<r){
		return ncr[n][r]=0;
	}
	if(r==0 || n==r){
		return ncr[n][r]=1;
	}
	if(ncr[n][r]!=-1){
		return ncr[n][r];
	}
	LLI ret=calc(n-1,r)+calc(n-1,r-1);
	return ncr[n][r]=ret;
}	

void precalc(){
	memset(ncr,-1,sizeof(ncr));
	FREP(i,1,12){
		FREP(j,0,i){
			ncr[i][j]=calc(i,j);
		}
	}

	FREP(i,1,12){
		LLI zero=i;
		LLI start=1;
		FREP(j,0,(i-1)){
			arr2[i]+=zero*start*ncr[i][j];
			zero--;
			start*=9;
		}
	}

	FREP(i,1,12){
		arr1[i]=arr2[i]*9;
		arr1[i]=arr1[i]+arr1[i-1];
	}

	tenpow[0]=1;
	//prefix0[0]=1;
	FREP(i,1,12){
		tenpow[i]=tenpow[i-1]*10;
		//prefix0[i]=prefix0[i-1]+tenpow[i];
	}

	FREP(i,1,12){
		prefix0[i]=0;
		int start=i;
		int ninest=1;
		while(start>0){
			prefix0[i]+=start*ninest;
			start--;
			ninest*=9;
		}
	}

	FREP(i,0,12){
		cout<<"arr1["<<i<<"] = "<<arr1[i]<<"\n";
	}
	FREP(i,0,12){
		cout<<"arr2["<<i<<"] = "<<arr2[i]<<"\n";
	}
}

int findpos(LLI n){
	if(n==0)return 0;
	VI ll;
	while(n){
		ll.PB(n%10);
		n/=10;
	}
	return ll.size()-1;
}

int findmex(LLI n, int pos){
	return n/tenpow[pos];
}

LLI rec(LLI num, int pos, int mex, int f){
	cout<<"in "<<num<<" "<<pos<<" "<<mex<<"\n";
	if(pos>0 && mex>0){
		LLI a=arr1[pos-1];
		LLI b=(mex-1)*arr2[pos];
		LLI c=num%tenpow[pos];
		LLI d=c/tenpow[pos-1];
		LLI e=rec(c,pos-1,(int)d,1);
		LLI ff=0;
		if(f){
			ff=prefix0[pos];
		}
		return a+b+e+ff;
	}

	else if(pos==0){
		return 1;
	}
	else{
		LLI a=arr1[pos-1];
		LLI c=num%tenpow[pos];
		LLI b=c+1;
		LLI d=c/tenpow[pos-1];
		LLI e=rec(c,pos-1,(int)d,1);
		LLI ff=0;
		if(f){
			ff=prefix0[pos-1];
		}
		return a+b+e+ff;
		//return a+b+e;	
	}
}

int main()
{
	/* code */
	int t;
	scanf("%d",&t);
	int cs=1;
	precalc();
	while(t--){
		LLI m,n;
		scanf("%lld %lld",&m,&n);
		if(m>0 && n>0){
			m--;
			int npos=findpos(n);
			int nmex=findmex(n,npos);
			int mpos=findpos(m);
			int mmex=findmex(m,mpos);
			LLI ans1=rec(n,npos,nmex,1);
			LLI ans2=rec(m,mpos,mmex,1);
			cout<<ans1<<" "<<ans2<<"\n";
			printf("Case %d: %lld\n",cs++,ans1-ans2);
		}
		else if(n==0){
			printf("Case %d: 1\n",cs++);
		}
		else{
			int npos=findpos(n);
			int nmex=findmex(n,npos);
			LLI ans1=rec(n,npos,nmex,1);
			cout<<ans1<<"\n";
			printf("Case %d: %lld\n",cs++,ans1+1);
		}
		//LLI n;
		//cin>>n;
		//cout<<rec(n)<<"\n";
	}
	return 0;
}