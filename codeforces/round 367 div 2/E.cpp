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

using namespace std;

//Data Structure used: 2D doubly linked list
//store val; up, down, left and right node
//take row+2, col+2 area to avoid null pointer hasty checking
//when swapping two rectangle only outer boundary pointers need to be updated
struct cell{
    int val;
    cell* up;
    cell* down;
    cell* left;
    cell* right;
    cell(){
        val=0;
        up=down=left=right=NULL;
    }
};

struct cellpairs{
    cell* one;
    cell* two;
};

int mat[1006][1006];

cell* construct(int n, int m){
    cell *head=new cell();
    int row=0;
    int col=0;
    cell* rh=head;
    cell* pre=NULL;
    cell* trh=rh;
    FREP(i,0,(n+1)){
        trh=rh;
        FREP(j,0,m){
            cell *cur=new cell();
            rh->right=cur;
            cur->left=rh;
            rh->up=pre;
            if(pre)pre->down=rh;
            rh->down=NULL;
            rh->val=mat[row][col];
            col++;
            cur->val=mat[row][col];
            rh=rh->right;
            if(pre)pre=pre->right;
        }
        rh->up=pre;
        if(pre)pre->down=rh;
        rh->right=NULL;
        rh->down=NULL;
        rh=new cell();
        pre=trh;
        row++;
        col=0;
    }
    return head;
}

cellpairs swaptoprow(cell *a, cell *b, int n, int m){
    cell* aup=a;
    cell* bup=b;
    cell* prea=a;
    cell* preb=b;
    FREP(i,1,m){
        cell* up1=aup->up;
        cell* up2=bup->up;
        up1->down=bup;
        up2->down=aup;
        aup->up=up2;
        bup->up=up1;
        prea=aup;
        preb=bup;
        aup=aup->right;
        bup=bup->right;
    }
    cellpairs ret;
    ret.one=prea;
    ret.two=preb;
    return ret;
}

void swapbottomrow(cell *a, cell *b, int n, int m){
    cell* aup=a;
    cell* bup=b;
    FREP(i,1,m){
        cell* d1=aup->down;
        cell* d2=bup->down;
        d1->up=bup;
        d2->up=aup;
        aup->down=d2;
        bup->down=d1;
        aup=aup->right;
        bup=bup->right;
    }
}

cellpairs swapleftcol(cell *a, cell *b, int n, int m){
    cell* aup=a;
    cell* bup=b;
    cell* prea=a;
    cell* preb=b;
    FREP(i,1,n){
        cell* l1=aup->left;
        cell* l2=bup->left;
        l1->right=bup;
        l2->right=aup;
        aup->left=l2;
        bup->left=l1;
        prea=aup;
        preb=bup;
        aup=aup->down;
        bup=bup->down;
    }
    cellpairs ret;
    ret.one=prea;
    ret.two=preb;
    return ret;
}

void swaprightcol(cell *a, cell *b, int n, int m){
    cell* aup=a;
    cell* bup=b;
    FREP(i,1,n){
        cell* r1=aup->right;
        cell* r2=bup->right;
        r1->left=bup;
        r2->left=aup;
        aup->right=r2;
        bup->right=r1;
        aup=aup->down;
        bup=bup->down;
    }
}

void print(cell* h, int n, int m){
    cell* head=(h->right)->down;
    cell* rh=head;
    cell* trh;
    FREP(i,1,n){
        trh=rh;
        FREP(j,1,m){
            printf("%d ",rh->val);
            rh=rh->right;
        }
        printf("\n");
        rh=trh->down;
    }
}

cell* findcell(int r, int c, cell* h){
    cell* rh=h;
    FREP(i,1,r){
        rh=rh->down;
    }
    FREP(i,1,c){
        rh=rh->right;
    }
    return rh;
}

void cellrangetest(cell* h){
    int row=0,col=0;
    cell* rh=h;
    cell* trh=rh;
    while(trh){
        while(rh){
            rh=rh->right;
            col++;
        }
        printf("row %d has %d cols\n",row,col);
        col=0;
        row++;
        rh=trh->down;
        trh=rh;
    }
}

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    FREP(i,1,n){
        FREP(j,1,m){
            scanf("%d",&mat[i][j]);
        }
    }
    cell* head=construct(n,m);
    FREP(i,1,q){
        int ax,ay,bx,by,h,w;
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&h,&w);
        cell* ahead=findcell(ax,ay,head);
        cell* bhead=findcell(bx,by,head);
        cellpairs rightcol=swaptoprow(ahead,bhead,h,w);
        cellpairs botrow=swapleftcol(ahead,bhead,h,w);
        swaprightcol(rightcol.one,rightcol.two,h,w);
        swapbottomrow(botrow.one,botrow.two,h,w);
    }
    print(head,n,m);
    return 0;
}

