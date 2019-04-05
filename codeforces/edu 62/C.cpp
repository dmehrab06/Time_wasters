/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9
#define MDD 1000000007

using namespace std;

vector< pair<int,int> >music;

int main(){
    
    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0; i<n; ++i){
        int t,b;
        scanf("%d %d",&t,&b);
        music.push_back(make_pair(b,t));
    }

    sort(music.begin(),music.end());

    multiset< int > curplaylist;

    long long run_sum = 0;

    long long mxx = 0;
    

    for(int i = (n-1); i>=(n-k+1); --i){
        int curb = music[i].first;
        curplaylist.insert(music[i].second);
        run_sum = run_sum + music[i].second;
        mxx = max(mxx,run_sum*curb);
    }

    for(int i = (n-k); i>=0; --i){
        long long curb = music[i].first;
        long long r = run_sum+music[i].second;
        mxx = max(mxx,curb*r);
        curplaylist.insert(music[i].second);
        run_sum = run_sum+music[i].second;
        int min_l = *(curplaylist.begin());
        curplaylist.erase(curplaylist.begin());
        run_sum = run_sum-min_l;
    }

    
    cout<<mxx<<"\n";
    return 0;
}