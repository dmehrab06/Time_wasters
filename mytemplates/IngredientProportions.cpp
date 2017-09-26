#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class IngredientProportions {
public:
	vector <int> getMasses(vector <string>);
};

typedef long long int ll;

ll gcd(ll a, ll b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

ll findlcm(ll arr[], int n)
{
    ll ans = arr[0];
    for (int i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
                (gcd(arr[i], ans)) );

    return ans;
}

ll lcmarr[30];

int visited[20];
pair<ll,ll> ans [20];
vector < vector < pair<int, pair <int,int> >  > >graph;
		
	
void dfs(int cur){
	visited[cur]=1;
	int l=graph[cur].size();
	for(int i=0;i<l;++i){
		int v=graph[cur][i].first;
		int uprop=graph[cur][i].second.first;
		int vprop=graph[cur][i].second.second;
		if(!visited[v]){
			ans[v].first=ans[cur].first*vprop;
			ans[v].second=ans[cur].second*uprop;
			dfs(v);
		}
	}
	return;
}

vector <int> IngredientProportions::getMasses(vector <string> proportions) {
	int n=proportions.size();
	vector < pair<int, pair <int,int> >  >line;
	for(int i=0;i<=(n+3);++i){
		graph.push_back(line);
	} 	
	for(int i=0;i<n;++i){
		string cur=proportions[i];
		int u = cur[1]-'0';
		int v = cur[8]-'0';
		int up = cur[13]-'0';
		int vp = cur[15]-'0';
		graph[u].push_back(make_pair(v,make_pair(up,vp)));
		graph[v].push_back(make_pair(u,make_pair(vp,up)));
	}
	ans[0].first=(ll)1;
	ans[0].second=(ll)1;
	dfs(0);
	for(int i=0;i<(n+1);++i){
		lcmarr[i]=ans[i].second;
	}
	ll lc=findlcm(lcmarr,n+1);
	for(int i=0;i<(n+1);++i){
		ans[i].first*=(lc/ans[i].second);
	}
	ll gg= ans[0].first;
	for(int i=1;i<(n+1);++i){
		gg=gcd(gg,ans[i].first);
	}
	for(int i=0;i<(n+1);++i){
		ans[i].first/=gg;
	}
	vector<int>oka;
	for(int i=0;i<(n+1);++i){
		oka.push_back(ans[i].first);
	}
	return oka;
}


double test0() {
	string t0[] = {"#0 and #1 as 6:4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IngredientProportions * obj = new IngredientProportions();
	clock_t start = clock();
	vector <int> my_answer = obj->getMasses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {3, 2 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IngredientProportions * obj = new IngredientProportions();
	clock_t start = clock();
	vector <int> my_answer = obj->getMasses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {81, 72, 64 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IngredientProportions * obj = new IngredientProportions();
	clock_t start = clock();
	vector <int> my_answer = obj->getMasses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {105, 35, 21, 15, 105 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	IngredientProportions * obj = new IngredientProportions();
	clock_t start = clock();
	vector <int> my_answer = obj->getMasses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {60, 20, 63, 84 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
