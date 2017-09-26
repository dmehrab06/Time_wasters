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
#define ALPHABET_SIZE 2
#define INDEX(c) ((int)c - (int)'0')
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI arr[100005];
char matched[66];
char bits[66];

// trie node
struct trie_node{
    LLI value; // non zero if leaf
    trie_node *children[ALPHABET_SIZE];
};


struct mytrie{
    trie_node *root;
};

trie_node *getNode(void){
    trie_node *pNode=NULL;
    pNode=(trie_node *)malloc(sizeof(trie_node));
    if(pNode){
        pNode->value=0;
        FREP(i,0,ALPHABET_SIZE-1){
            pNode->children[i]=NULL;
        }
    }
    return pNode;
}

void initialize(mytrie *pTrie){
    pTrie->root=getNode();
}

void insert(mytrie *pTrie, char key[]){ //inserting a new val in trie
    int length=strlen(key);
    int index;
    trie_node *pCrawl;
    pCrawl=pTrie->root;

    FREP(level,0,length-1){
        index=INDEX(key[level]);
        if(pCrawl->children[index]){
            // Skip current node
            pCrawl=pCrawl->children[index];
        }
        else{
            // Add new node
            pCrawl->children[index]=getNode();
            pCrawl=pCrawl->children[index];
        }
    }
}


void xorsearch(mytrie *pTrie, char key[]){ //searching for max xor in trie
    int length=strlen(key);
    int index;
    trie_node *pCrawl;
    pCrawl=pTrie->root;
    FREP(level,0,length-1){
        index=1-INDEX(key[level]);//either 0 or 1
        if(!pCrawl->children[index]){
            pCrawl=pCrawl->children[1-index];
            matched[level]='0';
        }
        else{
            pCrawl=pCrawl->children[index];
            matched[level]='1';
        }
    }
}

LLI takeinp(int n){ //taking inputs
    LLI lxor=0;
    FREP(i,1,n){
        scanf("%lld",&arr[i]);
        lxor=lxor^arr[i];
    }
    return lxor;
}

void placebits(LLI val){ //placing bits in current array to be passed on to the search method
    LLI msk=1;
    FREP(k,0,63){
        if(msk&val) bits[63-k]='1';
        else bits[63-k]='0';
        val>>=1;
    }
    bits[64]='\0';
}

LLI getmatchedans(){ //retrieve max xor for current prefix
    LLI ans=0;
    FREP(k,0,63){
        ans=ans*2;
        if(matched[k]=='1'){
            ans++;
        }
    }
    return ans;
}

LLI go(int n){
    mytrie trie_t; initialize(&trie_t); placebits(0); insert(&trie_t,bits);
    LLI lxor=takeinp(n); LLI mxx=lxor;
    LLI rxor=0;
    RFREP(i,n,1){
        rxor=rxor^arr[i]; //increasing suffix length
        lxor=lxor^arr[i]; //decreasing prefix length
        //cout<<lxor<<" "<<rxor<<"\n";
        placebits(rxor);
        insert(&trie_t,bits); //inserting new suffix in trie
        placebits(lxor);
        xorsearch(&trie_t,bits); //checking max xor that can be achieved for current prefix
        LLI curmax=getmatchedans();
        //cout<<curmax<<"\n";
        mxx=max(curmax,mxx); //updating ans
    }
    return mxx;
}

int main()
{
    int n;
    scanf("%d",&n);
    LLI mxx=go(n);
    printf("%lld\n",mxx);
    return 0;
}


