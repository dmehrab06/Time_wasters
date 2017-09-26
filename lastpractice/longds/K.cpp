/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int ALPH = 2;
const int MAXBIT = 31;
class TrieNode {
public:
    TrieNode() {
        //value = 0;
        //parent = NULL;
        FREP(i,0,ALPH-1){
            children[i] = NULL;
            childfreq[i] = 0;
        }
    }
    int childfreq[ALPH];
    //int childofparent; //0 theke 25 er moddhe kichu ekta
    TrieNode* children[ALPH];
    //TrieNode* parent;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
        //count = 0;
    }

    void insert(int n) {
        TrieNode *p = root;
        int bitpos = MAXBIT;
        while(bitpos>=0){
            int v = n&(1<<bitpos);
            if(v){
                if((p->children[1])==NULL)p->children[1] = new TrieNode();
                p->childfreq[1]++;
                p = p->children[1];
            }
            else{
                if((p->children[0])==NULL)p->children[0] = new TrieNode();
                p->childfreq[0]++;
                p = p->children[0];
            }
            bitpos--;
        }
    }

    LLI getcnt(int rightxor, int k, TrieNode *curnode, int bitpos){
        if(curnode==NULL || bitpos<0){
            return 0;
        }
        int kbit = k & (1<<bitpos);
        int rbit = rightxor & (1<<bitpos);
        //cout<<bitpos<<" "<<kbit<<" "<<rbit<<"\n";

        if(kbit){
            if(rbit){
                //so 1 ase, 1 dia xor korle always 0 pamu, so 1 er sob nimu
                //0 dia korle sure na, so query chalano lagbe
                return (LLI)curnode->childfreq[1]+(LLI)getcnt(rightxor,k,curnode->children[0],bitpos-1);
            }
            else{
                //0 ase , 0 dia xor korle always 0 pamu, so 0 er sob nimu
                //1 dia korle sure na, so query chalaite hobe
                return (LLI)curnode->childfreq[0]+(LLI)getcnt(rightxor,k,curnode->children[1],bitpos-1);
            }
        }
        else{
            if(rbit){
                //1 ase 0 dia xor korle 1 , already boro, left side e query chalaia laav nai
                return (LLI)getcnt(rightxor,k,curnode->children[1],bitpos-1);
            }
            else{ //0 ase 1 dia xor korle 1, already boro, right side e query chalaia laav nai
                return (LLI)getcnt(rightxor,k,curnode->children[0],bitpos-1);
            }
        }
    }
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        Trie xortrie;
        int currightxor = 0;
        LLI ans = 0;
        xortrie.insert(0);
        while(n--){
            int val;
            scanf("%d",&val);
            currightxor = currightxor^val;
            //cout<<currightxor<<"\n";
            LLI curans = xortrie.getcnt(currightxor,k,xortrie.root,MAXBIT);
            //cout<<curans<<"\n\n";
            ans = ans+curans;
            xortrie.insert(currightxor);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
