#define W 0
#define G 1
#define B 2
#define valid(nx,ny,ROW,COLUMN) (nx>=0 && nx<ROW && ny>=0 && ny<COLUMN)
#define MAX 100
#include <iostream>
using namespace std;
typedef struct xx{
    int row;
    int column;
}node;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
class Queue{
    int head;
    int tail;
    node *queue;
 
public:
    Queue(int n){
        queue=new node[n];
        head=0;
        tail=0;
    }
    void enqueue(node n){
        queue[head]=n;
        head++;
    }
    node dequeue(){
        tail++;
        return queue[tail-1];
    }
    int isempty(){
        if(tail==head)return 1;
        return 0;
    }
};
 
int main(){
    int maze[30][30];
    char s[30];
    node source;
    int t;
    int tt=1;
    cin>>t;
    while(t--){
    int row,column;
    cin>>column>>row;
        for(int i=0;i<row;++i){
 
                cin>>s;
                for(int j=0;j<column;++j){
                    char ch=s[j];
                    if(ch=='@'){
                        source.row=i;
                        source.column=j;
                    }
                    if(ch=='@' || ch=='.'){
                        maze[i][j]=0;
                    }
                    else{
                        maze[i][j]=1;
                    }
                }
        }
            int reached=0;
            maze[source.row][source.column]=1;
            reached++;
            Queue q(1000);
            q.enqueue(source);
            node temp;
 
            while(!(q.isempty())){
                temp=q.dequeue();
                int x=temp.row;
                int y=temp.column;
                for(int k=0;k<4;k++){
 
 
                    int nx=x+fx[k]; //Add fx[k] with current row
                    int ny=y+fy[k]; //Add fy[k] with current col
                    if(valid(nx,ny,row,column)){
                        if(maze[nx][ny]==0){
                            node temp2;
                            temp2.row=nx;
                            temp2.column=ny;
                            q.enqueue(temp2);
                            maze[nx][ny]=1;
                            reached++;
                        }
                    }
                }
                //color[a]=B;
 
            }
            cout<<"Case "<<tt<<": "<<reached<<"\n";
            tt++;
 
 
 
}
    return 0;
}
