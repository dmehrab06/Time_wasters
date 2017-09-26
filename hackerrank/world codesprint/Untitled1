    #include <bits/stdc++.h>
    using namespace std;
    #define mp make_pair
    typedef pair<int,int> pii;
    typedef pair<int,pii> pip;
    typedef long long ll;

    char s[300010];
    char tmp[600020];
    int rad[600020];
    int N;

    void manacher()
    {
    	//rep(i,N*2+1)tmp[i]='#';
    	for(int i=0;i<(N*2+1);++i){
            tmp[i]='#'; //string er double size er ekta array
    	}
    	for(int i=0;i<N;++i){
            tmp[2*i+1]=s[i]; //prottekta char er age o pore #
    	}
    	/*tmp print kore dekhtesi ki obostha*/
    	for(int i=0;i<(N*2+1);++i){
            printf("%c",tmp[i]);
    	}
    	printf("\n");
    	//rep(i,N)tmp[i*2+1]=s[i];
    	int j=0;
    	int n=N*2+1;
    	int mxrad=-1;
    	for(int i=0;i<n;)
    	{
                printf("in i : %d\n",i);
                printf("j is currently : %d\n",j);
    			while(i-j>=0 && i+j<n && tmp[i-j]==tmp[i+j]){
                    j++; //i ke midpoint dhore dekhtesi bam e ar dan e palindrome form kore kina
                    //ei jonnoi # neya , because even len palindrome er midpoint dui letter er majhe
                }
    			rad[i]=j;
    			printf("accessing rad[%d] and making rad[%d] = %d\n",i,i,j);
    			if(i>mxrad)mxrad=i; //i er radius rakhlam oita
    			int k=1;
    			//rad[i-k]? o.O eita na -1 dibe ? rad[-1] gives 0 -_-
    			//printf("now (i-k) is %d and rad[i-k] is %d\n",i-k,rad[i-k]);
    			while(rad[i-k]<rad[i]-k){
                    rad[i+k]=rad[i-k];
                    printf("accessing rad[%d] and making rad[%d] = rad[%d] = %d\n",i+k,i+k,i-k,rad[i-k]);
                    if((i+k)>mxrad)mxrad=i+k;
                    k++;
                }
    			i+=k;
    			j=max(0,j-k); //j prottekbar 0 theke shuru hobe emon na, ei jonno while loop ta kom ghure
    	}
    	/*rad print kore dekhtesi ki obostha*/
    	for(int i=-1;i<=mxrad;++i){
            printf("rad[%d]: %d\n",i,rad[i]);
    	}
    	printf("\n");
    	//rad e ase otare midpoint nia joto len er max palindrome banano jay tar theke 1 besi
    }
    int sa[300001];
    int ra[300001];
    int sak;
    int ti[300001];
    int lcp[300001];
    bool cmp_sa(int a,int b)
    {
    	if(ra[a]!=ra[b])return ra[a]<ra[b];
    	int cha=(a+sak<=N)?ra[a+sak]:-1;
    	int chb=(b+sak<=N)?ra[b+sak]:-1;
    	return cha<chb;
    }
    void construct_sa(int n)
    {
    	//rep(i,n+1)
    	for(int i=0;i<(n+1);++i)
    	{
    		sa[i]=i;
    		ra[i]=(i<n)?s[i]:-1;
    	}
    	for(sak=1;sak<n;sak*=2)
    	{
    		sort(sa,sa+n+1,cmp_sa);
    		ti[sa[0]]=0;
    		for(int i=1;i<=n;i++)ti[sa[i]]=ti[sa[i-1]]+cmp_sa(sa[i-1],sa[i]);
    		//rep(i,n+1)ra[i]=ti[i];
    		for(int i=0;i<(n+1);++i)ra[i]=ti[i];
    	}
    }
    void construct_lcp(int n)
    {
    	//rep(i,n+1)ti[sa[i]]=i;
    	for(int i=0;i<(n+1);++i){
            ti[sa[i]]=i;
    	}
    	int h=0;
    	//rep(i,n)
    	for(int i=0;i<n;++i)
    	{
    		int j=sa[ti[i]-1];
    		if(h>0)h--;
    		while(i+h<n&&j+h<n&&s[i+h]==s[j+h])h++;
    		lcp[ti[i]]=h;
    	}
    }
    struct UnionFind
    {
    	int par[300001];
    	int ra[300001];
    	int sz[300001];
    	void init()
    	{
            //rep(i,300001)
            for(int i=0;i<300001;++i)
            {
                par[i]=i;
                ra[i]=0;
                sz[i]=0;
            }
    	}
    	int find(int x)
    	{
            return par[x]==x?x:par[x]=find(par[x]);
    	}
    	bool same(int a,int b)
    	{
            return find(a)==find(b);
    	}
    	void unite(int a,int b)
    	{
            if((a=find(a))!=(b=find(b)))
            {
                if(ra[a]<ra[b])
                    swap(ra[a],ra[b]);

                sz[a]+=sz[b];
                par[b]=a;
                ra[a]+=ra[a]==ra[b];
            }

    	}
    } uf;

    int main()
    {
    	FILE *in,*out;

    	in=stdin;out=stdout;
    	// in APIO 2014
    	//in=fopen("palindrome.in","r");
    	//out=fopen("palindrome.out","w");

    	fscanf(in,"%s",&s);
    	ll ans=0;
    	N=strlen(s); //bujhsi
    	manacher(); //->ekhon eikhane bujhte hobe
    	construct_sa(N);
    	construct_lcp(N);
    	vector<pip> lun;
    	//repn(i,1,N+1)
    	for(int i=1;i<(N+1);++i){
            lun.push_back(mp(lcp[i],mp(sa[i-1],sa[i])));
    	}
    	sort(lun.begin(),lun.end(),greater<pip>());
    	//odd
    	uf.init();
    	vector<pii> aq;
    	//rep(i,N)
    	for(int i=0;i<N;++i){
            aq.push_back(mp(rad[i*2+1]/2,i));
    	}
    	sort(aq.begin(),aq.end(),greater<pii>());
    	int ptr=0;
    	for(int i=0;i<N;++i)
    	{
    		while(ptr<N && lun[ptr].first>=aq[i].first)
    		{
    			uf.unite(lun[ptr].second.first,lun[ptr].second.second);
    			ptr++;
    		}
    		int ppuf=uf.find(aq[i].second);
    		uf.sz[ppuf]++;
    		ans=max(ans,ll(uf.sz[ppuf])*(aq[i].first*2-1));
    	}

    	//even
    	uf.init();
    	aq.clear();
    	for(int i=0;i<N;++i){
            aq.push_back(mp(rad[i*2]/2,i));
    	}
    	sort(aq.begin(),aq.end(),greater<pii>());
    	ptr=0;
    	//rep(i,N)
    	for(int i=0;i<N;++i)
    	{
    		while(ptr<N&&lun[ptr].first>=aq[i].first)
    		{
    			uf.unite(lun[ptr].second.first,lun[ptr].second.second);
    			ptr++;
    		}
    		int ppuf=uf.find(aq[i].second);
    		uf.sz[ppuf]++;
    		ans=max(ans,ll(uf.sz[ppuf])*(aq[i].first*2));
    	}

    	fprintf(out,"%lld\n",ans);
    	fclose(in);fclose(out);
    }
