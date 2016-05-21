#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    int par;
    int serial;
    struct node *left, *right;
};

int ans[100008];

// A utility function to create a new BST node
struct node *newNode(int item, int par,int serial)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->par=par;
    temp->serial=serial;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
       // printf("%d %d\n", root->key,root->par);
       if(root->par!=-1){
            ans[root->serial]=root->par;
       }
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key, int par,int serial)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key,par,serial);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key,node->key,serial);
    else if (key > node->key)
        node->right = insert(node->right, key, node->key,serial);

    /* return the (unchanged) node pointer */
    return node;
}

// Driver Program to test above functions
int nods[100008];
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
       int n;
       scanf("%d",&n);
       for(int i=1;i<=n;++i){
        scanf("%d",&nods[i]);
       }
    struct node *root = NULL;
    root = insert(root, nods[1],-1,1);
    for(int i=2;i<=n;++i){
        insert(root, nods[i],-1,i);
    }

    // print inoder traversal of the BST
    inorder(root);
    for(int i=2;i<=n;++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
