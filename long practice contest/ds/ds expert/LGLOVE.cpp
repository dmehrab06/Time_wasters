#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
/*
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
*/

int gcd(int m,int n)
{
	int rem;
	while(n>0)
	{
		rem=m%n;
		m=n;
		n=rem;
	}
	return m;

}


int lcm(int a,int b)
{
	int hc;
	int rem,m=a,n=b;
	while(n>0)
	{
		rem=m%n;
		m=n;
		n=rem;
	}
	hc=m%MOD;
	return (a%MOD*b%MOD)/(hc%MOD);
}

void cal(int *a,int *b,int x,int y)
{
	int i,j,hc,p,l,no;
	for(i=x;i<=y;i++)
	{
		hc=1;
		p=1;
		no=a[i];
		l=a[i]-1;
		while(l>0)
		{
			no=lcm(no,l);
			l--;
		}
//		for(j=2;j<=a[i];j++)
//		{
//			hc=gcd(j,hc);
//			p=p*j;
//		}
//		c[i]=hc;
//		b[i]=p/hc;
		b[i]=no;
	}
	return;
}
		


int main()
{
	int n,m,t,x,y,pr,hc,i,j,p,lc;
	scanf("%d%d",&n,&m);
	int a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=0;
		c[i]=0;
	}
	cal(a,b,0,n-1);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==0)
		{
			scanf("%d",&p);
			for(j=x;j<=y;j++)
				a[j]+=p;
			cal(a,b,x,y);
		}
//		if(t==1 || t==2)
//		{
		else if(t==1)
		{
			lc=b[y];
			for(j=y-1;j>=x;j--)
			{
				lc=(lcm(lc,b[j]))%MOD;
//				hc=gcd(hc,b[j]);
			}
			printf("%d\n",lc);
		}
		else if(t==2)
		{
			hc=b[y];
			for(j=y-1;j>=x;j--)
			{
//				lc=lcm(lc,b[j]);
				hc=gcd(hc,b[j])%MOD;
			}
			printf("%d\n",hc);
		}
//		}
//		printf("=============\n");
//		for(j=0;j<n;j++)
//		{
//			printf("%d ",a[j]);
//		}
//		printf("\n===========\n");
//		printf("-----------\n");
//		for(j=0;j<n;j++)
//		{
//			printf("%d ",b[j]);
//		}
//		printf("\n-----------\n");
	}
	return 0;
}
