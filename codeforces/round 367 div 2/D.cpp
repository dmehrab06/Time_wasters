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
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)

#define ALPHABET_SIZE (2)
#define INDEX(c) ((int)c - (int)'0') //string kore pass korte hobe

#define FREE(p) \
    free(p);    \
    p = NULL;

// forward declration
using namespace std;
typedef struct trie_node trie_node_t;

// trie node
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};

// trie ADT
typedef struct trie trie_t;

struct trie
{
    trie_node_t *root;
    int count;
};

trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if( pNode )
    {
        int i;

        pNode->value   = 0;

        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);

        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
    }

    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);

        if( !pCrawl->children[index] )
        {
            return 0;
        }

        pCrawl = pCrawl->children[index];
    }

    return (0 != pCrawl && pCrawl->value);
}
char matched[33];
void xorsearch(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);//either 0 or 1

        if( !pCrawl->children[index] )
        {
            pCrawl=pCrawl->children[1-index];
            matched[level]='0';
        }
        else{
            pCrawl = pCrawl->children[index];
            matched[level]='1';
        }
    }

    //return (0 != pCrawl && pCrawl->value);
}

int leafNode(trie_node_t *pNode)
{
    return (pNode->value != 0);
}

int isItFreeNode(trie_node_t *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }

    return 1;
}

bool deleteHelper(trie_node_t *pNode, char key[], int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->value )
            {
                // Unmark leaf node
                pNode->value = 0;

                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return true;
                }

                return false;
            }
        }
        else // Recursive case
        {
            int index = INDEX(key[level]);

            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                FREE(pNode->children[index]);

                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }

    return false;
}

void deleteKey(trie_t *pTrie, char key[])
{
    int len = strlen(key);

    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}

int main()
{
    //char keys[][8] = {"0010", "0110", "1001", "0011", "0011", "1001", "1111"};
    trie_t trie;
    char bits[33];
    FREP(i,0,31)bits[i]='0';
    bits[32]='\0';
    initialize(&trie);
    insert(&trie,bits);
    map<int,int>occ;
    int q;
    scanf("%d",&q);
    char type[3];
    FREP(i,1,q){
        int x;
        scanf("%s %d",type,&x);
        if(type[0]=='+'){
            occ[x]++;
            int msk=1;
            FREP(k,0,31){
                if(msk&x){
                    bits[31-k]='1';
                }
                else{
                    bits[31-k]='0';
                }
                x>>=1;
            }
            bits[32]='\0';
            insert(&trie,bits);

        }
        else if(type[0]=='-'){
            occ[x]--;
            if(occ[x]==0){
                int msk=1;
                FREP(k,0,31){
                    if(msk&x){
                        bits[31-k]='1';
                    }
                    else{
                        bits[31-k]='0';
                    }
                    x>>=1;
                }
                bits[32]='\0';
                deleteKey(&trie,bits);
              //  cout<<"delete korsi\n";
            }
        }
        else if(type[0]=='?'){
         //   int tx=x;
            int msk=1;
            FREP(k,0,31){
                if(msk&x){
                    bits[31-k]='0';
                }
                else{
                    bits[31-k]='1';
                }
                x>>=1;
            }
            bits[32]='\0';
            xorsearch(&trie,bits);
            int ans=0;
            FREP(k,0,31){
                ans<<=1;
                if(matched[k]=='1'){
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

