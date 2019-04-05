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

#define MXCHILD 2

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        value = 0;
        for (int i=0;i<MXCHILD;i++){
            children[i] = NULL;
        }
        freq = 0;
    }
    int value;
    int freq;
    TrieNode* children[MXCHILD];
    int available[MXCHILD];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }
    int insert(int val) {
        TrieNode *p = root;
        int len = 30; //int msk = 1;
        for (int i=len;i>=1;i--){
            int idx = (val & (1<<(i-1)))?1:0;
            if (!p->children[idx]){
                p->children[idx] = new TrieNode();
                p->available[idx] = 0;
            }
            (p->available[idx])++;
            p = p->children[idx];
        }
        count++;
        p->value = count;
        p->freq++;
        return p->freq;
    }

    // Returns if the word is in the trie.
    int xortrie(int key){
        TrieNode *p = root;
        int len = 30; //int msk  = 1;
        int val = 0;
        for(int i = len;i>=1;--i){
            int idx = (key & (1<<(i-1)))?1:0;
            if(p->children[idx] && (p->available[idx]>0)){
                val = val*2;
                (p->available[idx])--;
                p = p->children[idx];
            }
            else{
                val = val*2+1;
                (p->available[1-idx])--;
                p = p->children[1-idx];
            }
        }
        return val;
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int arr[300005];

int main(){
    Trie trie;
    int n;
    scanf("%d",&n);
    FREP(i,1,n)scanf("%d",&arr[i]);
    FREP(i,1,n){
        int xx;
        scanf("%d",&xx);
        trie.insert(xx);
    }
    FREP(i,1,n){
        int ans = trie.xortrie(arr[i]);
        printf("%d ",ans);
    }
    printf("\n");
    return 0;
}

