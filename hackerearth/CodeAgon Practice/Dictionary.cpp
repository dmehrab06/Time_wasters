/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int g[31][31];

int indegree[31];
int it[31];

vector <string> all;

vector <VI> gg;

vector <VI> ans;

void init(){
    memset(g,-1,sizeof(g));
    VI line;
    FREP(i,0,30)gg.PB(line);
    FREP(i,0,30)ans.PB(line);
}

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        value = 0;
        parent = NULL; //need parent for delete operation
        for (int i=0;i<26;i++){
            children[i] = NULL;
        }
        freq = 0;
    }
    int value;
    int freq;
    int childofparent; //0 theke 25 er moddhe kichu ekta
    TrieNode* children[26];
    TrieNode* parent;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Inserts a word into the trie.
    int insert(string s) {
        TrieNode *p = root;
        int len = s.size();
        for (int i=0;i<len;i++){
            int idx = s[i] - 'a';
            if (! p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p->children[idx]->parent = p;
            p->children[idx]->childofparent = idx;
            p = p->children[idx];
        }
        count++;
        p->value = count;
        p->freq++;
        return p->freq;
    }

    // Returns if the word is in the trie.
    void traverse(string key) {
        TrieNode *p = root;
        int len = key.size();
        for (int i=0;i<len;i++){
            int idx = key[i] - 'a';
            it[idx]=1;
            for(int j=0;j<26;++j){
                if(idx==j){
                    continue;
                }
                if(p->children[j]){
                    if(g[idx][j]==-1){
                        g[idx][j]=1; //idx comes before j
                        g[j][idx]=2; //j comes before idx
                    }
                }

            }
            p = p->children[idx];

        }
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

void solve(){
    FREP(curit,1,26){
        FREP(j,0,25){
            if(indegree[j]==0 && it[j]==curit){
                ans[curit].PB(j);
                int l=gg[j].size();
                FREP(k,0,(l-1)){
                    indegree[gg[j][k]]--;
                    it[gg[j][k]]=curit+1;
                }
            }
        }
    }
    FREP(i,1,26){
        SORTV(ans[i]);
    }
}

int main(){
    init();
    Trie trie;
    int n;
    cin>>n;
    string s;
    FREP(i,1,n){
        cin>>s;
        trie.insert(s);
        all.PB(s);
    }
    FREP(i,0,(n-1)){
        trie.traverse(all[i]);
    }
    //cout<<"hoise\n";
    FREP(i,0,25){
        FREP(j,0,25){
            if(g[i][j]==1){
                gg[i].PB(j);
                indegree[j]++;
            }
        }
    }
    solve();
    FREP(i,1,26){
        int l=ans[i].size();
        FREP(k,0,(l-1)){
            cout<<(char)(ans[i][k]+'a');
        }
        if(l>0)cout<<"\n";
    }
    return 0;
}

