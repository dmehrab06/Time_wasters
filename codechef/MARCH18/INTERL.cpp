#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAXN 10003
#define MAXIT 50

using namespace std;
using namespace __gnu_pbds;

typedef tree < pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<string>alls;
vector<int>curidx;

bool is_over(int idx){
	if(curidx[idx]==(int)alls[idx].size()){
        return true;
    }
    return false;
}

long long calc_cost(int start_idx, int n, int tot_size){
    curidx.clear();

    for(int i = 0; i<n; ++i)curidx.push_back(0);
    
    int cur = alls[start_idx][0]-'0'; curidx[start_idx] = 1;
    
    ordered_set X;
    for(int i = 0; i<n; ++i){
    	if(!is_over(i)){
    		int d = alls[i][curidx[i]]-'0';
    		X.insert(make_pair(d,i));
    	}
    }
    
    long long tot_cost = 0;

    for(int needtake = 1; needtake<tot_size; ++needtake){
       
        vector< pair<int,int> >candidates;
        
        int prevd = cur;

        int pos_1 = X.order_of_key(make_pair(prevd,-1));
        int pos_2 = X.order_of_key(make_pair(prevd,MAXN+1));

        int cursetsz = (int)X.size();

        for(int i = -1; i<=1; ++i){
        	pair<int,int>dummy;
        	int pp1 = pos_1+i;
        	int pp2 = pos_2+i;

        	if(pp1>=0 && pp1<cursetsz){
        		dummy = *(X.find_by_order(pp1));
        		candidates.push_back(dummy);
        	}

        	if(pp2>=0 && pp2<cursetsz){
        		dummy = *(X.find_by_order(pp2));
        		candidates.push_back(dummy);
        	}
        }

        int next_idx = -1;
        int curmin = 10000;
        int v = -1;

        for(int i = 0; i<(int)candidates.size(); ++i){
            pair<int,int>cur_cand = candidates[i];
            int val = cur_cand.first;
            int idx = cur_cand.second;
            int dif = (prevd-val)*(prevd-val);
            if(dif<curmin){
            	curmin = dif;
            	next_idx = idx;
            	v = val;
            }
        }

        tot_cost = tot_cost + curmin;
        cur = alls[next_idx][curidx[next_idx]]-'0';
        X.erase(make_pair(v,next_idx));
        curidx[next_idx]++;
        if(!is_over(next_idx)){
        	X.insert(make_pair(alls[next_idx][curidx[next_idx]]-'0',next_idx));
        }
    }
    return tot_cost;
}

void simulate(int start_idx, int n, int tot_size){
    curidx.clear();

    for(int i = 0; i<n; ++i)curidx.push_back(0);
    
    string interleaved = "";
    
    interleaved.push_back(alls[start_idx][0]); curidx[start_idx] = 1;
    
    ordered_set X;
    for(int i = 0; i<n; ++i){
        if(!is_over(i)){
            int d = alls[i][curidx[i]]-'0';
            X.insert(make_pair(d,i));
        }
    }

    int cursize = 1;
    
    printf("%d ",start_idx+1);
    
    long long tot_cost = 0;

    for(int needtake = 1; needtake<tot_size; ++needtake){
       
        vector< pair<int,int> >candidates;
        
        int prevd = (int)(interleaved[cursize-1]-'0');

        int pos_1 = X.order_of_key(make_pair(prevd,-1));
        int pos_2 = X.order_of_key(make_pair(prevd,MAXN+1));

        int cursetsz = (int)X.size();

        for(int i = -1; i<=1; ++i){
            pair<int,int>dummy;
            int pp1 = pos_1+i;
            int pp2 = pos_2+i;

            if(pp1>=0 && pp1<cursetsz){
                dummy = *(X.find_by_order(pp1));
                candidates.push_back(dummy);
            }

            if(pp2>=0 && pp2<cursetsz){
                dummy = *(X.find_by_order(pp2));
                candidates.push_back(dummy);
            }
        }

        int next_idx = -1;
        int curmin = 10000;
        int v = -1;

        for(int i = 0; i<(int)candidates.size(); ++i){
            pair<int,int>cur_cand = candidates[i];
            int val = cur_cand.first;
            int idx = cur_cand.second;
            int dif = (prevd-val)*(prevd-val);
            if(dif<curmin){
                curmin = dif;
                next_idx = idx;
                v = val;
            }
        }

        printf("%d ",next_idx+1);
        tot_cost = tot_cost + curmin;
        interleaved.push_back(alls[next_idx][curidx[next_idx]]);
        cursize++;
        X.erase(make_pair(v,next_idx));
        curidx[next_idx]++;
        if(!is_over(next_idx)){
            X.insert(make_pair(alls[next_idx][curidx[next_idx]]-'0',next_idx));
        }
    }
    printf("\n");
}

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int tot = 0;
	for(int i = 1; i<=n; ++i){
	    string s;
	    cin>>s;
	    tot = tot + (int)s.size();
	    alls.push_back(s);
	}
    long long min_cost = 1e14;
    int st_idx = -1;
    for(int it = 0; it<=MAXIT; ++it){
        int myidx = rand()%n;
        long long cc = calc_cost(myidx,n,tot);
        if(cc<min_cost){
            min_cost = cc;
            st_idx = myidx;
        }
    }
	simulate(st_idx,n,tot);

	/*ordered_set X;
	X.insert(make_pair(1,2));
	X.insert(make_pair(2,2));
	X.insert(make_pair(2,3));
	X.insert(make_pair(2,4));
	X.insert(make_pair(3,5));
	X.insert(make_pair(3,7));
	X.insert(make_pair(4,2));
	X.insert(make_pair(4,1));
	X.insert(make_pair(2,5));

	cout<<X.order_of_key(make_pair(1,0))<<endl;
	cout<<X.order_of_key(make_pair(1,100000))<<endl;
	cout<<X.order_of_key(make_pair(2,0))<<endl;
	cout<<X.order_of_key(make_pair(2,100000))<<endl;
	cout<<X.order_of_key(make_pair(3,0))<<endl;
	cout<<X.order_of_key(make_pair(3,100000))<<endl;
	cout<<X.order_of_key(make_pair(4,0))<<endl;
	cout<<X.order_of_key(make_pair(4,100000))<<endl;

	//cout<<(int)(lower_bound(X.begin(),X.end(),make_pair(2,0))-X.begin())<<endl;*/
	return 0;
}
