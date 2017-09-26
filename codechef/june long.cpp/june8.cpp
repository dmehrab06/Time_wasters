#include <bits/stdc++.h>
#define VALID(X,Y) ((X)>=1 && (X)<=10 && (Y)>=1 && (Y)<=10)
using namespace std;

int grid[12][12];

struct pt{
    int x,y;
    pt(){
        x=0;
        y=0;
    }
    pt(int a,int b){
        x=a;
        y=b;
    }
};

vector < vector < pt > >figures;

bool isplacable(int figureid, int x, int y){
    int l=figures[figureid].size();
    for(int i=0;i<l;++i){
        int curx=figures[figureid][i].x;
        int cury=figures[figureid][i].y;
        if(!VALID(x+curx,y+cury) || grid[x+curx][y+cury]){
            return false;
        }
    }
    return true;
}

void place(int figureid, int x, int y){
    int l=figures[figureid].size();
    for(int i=0;i<l;++i){
        int curx=figures[figureid][i].x;
        int cury=figures[figureid][i].y;
        grid[x+curx][y+cury]=1;
    }
}

void tryclear(){
    vector<int>rowtoclear;
    for(int i=1;i<=10;++i){
        int has=1;
        for(int j=1;j<=10;++j){
            if(grid[i][j]==0){
                has=0;
                break;
            }
        }
        if(has){
            rowtoclear.push_back(i);
          //  printf("cleared row %d\n",i);
        }
    }
    vector<int>columnclear;
    for(int i=1;i<=10;++i){
        int has=1;
        for(int j=1;j<=10;++j){
            if(grid[j][i]==0){
                has=0;
                break;
            }
        }
        if(has){
            columnclear.push_back(i);
          //  printf("cleared column %d\n",i);
        }
    }
    for(int i=0;i<rowtoclear.size();++i){
        for(int j=1;j<=10;++j){
            grid[rowtoclear[i]][j]=0;
        }
    }
    for(int i=0;i<columnclear.size();++i){
        for(int j=1;j<=10;++j){
            grid[j][columnclear[i]]=0;
        }
    }
}


void init(){
    vector<pt>line;
    for(int i=1;i<=20;++i){
        figures.push_back(line);
    }
    for(int i=1;i<=19;++i){
        if(i!=12 && i!=17)figures[i].push_back(pt(0,0));
    }
    figures[2].push_back(pt(-1,0));
    figures[4].push_back(pt(-1,0));
    figures[4].push_back(pt(-2,0));
    figures[3].push_back(pt(0,1));
    figures[5].push_back(pt(0,1));
    figures[5].push_back(pt(0,2)); //upto 5 done
    figures[6].push_back(pt(-1,0));
    figures[6].push_back(pt(-2,0));
    figures[6].push_back(pt(-3,0));
    figures[7].push_back(pt(0,1));
    figures[7].push_back(pt(0,2));
    figures[7].push_back(pt(0,3));
    figures[8].push_back(pt(-1,0));
    figures[8].push_back(pt(-2,0));
    figures[8].push_back(pt(-3,0));
    figures[8].push_back(pt(-4,0));
    figures[9].push_back(pt(0,1));
    figures[9].push_back(pt(0,2));
    figures[9].push_back(pt(0,3));
    figures[9].push_back(pt(0,4));
    figures[10].push_back(pt(0,1));
    figures[10].push_back(pt(-1,0));
    figures[10].push_back(pt(-1,1)); // upto 10 done
    figures[11].push_back(pt(0,1));
    figures[11].push_back(pt(-1,0));
    figures[11].push_back(pt(-1,1));
    figures[11].push_back(pt(0,2));
    figures[11].push_back(pt(-2,0));
    figures[11].push_back(pt(-2,2));
    figures[11].push_back(pt(-2,1));
    figures[11].push_back(pt(-1,2));
    figures[12].push_back(pt(0,2));
    figures[12].push_back(pt(-2,0));
    figures[12].push_back(pt(-2,2));
    figures[12].push_back(pt(-2,1));
    figures[12].push_back(pt(-1,2)); //12 done
    figures[13].push_back(pt(0,2));
    figures[13].push_back(pt(-2,2));
    figures[13].push_back(pt(0,1));
    figures[13].push_back(pt(-1,2)); //13 done
    figures[14].push_back(pt(-1,0));
    figures[14].push_back(pt(-2,0));
    figures[14].push_back(pt(0,1));
    figures[14].push_back(pt(0,2));
    figures[15].push_back(pt(-1,0));
    figures[15].push_back(pt(-2,0));
    figures[15].push_back(pt(-2,1));
    figures[15].push_back(pt(-2,2)); //15 done
    figures[16].push_back(pt(-1,0));
    figures[16].push_back(pt(-1,1));
    figures[17].push_back(pt(-1,0));
    figures[17].push_back(pt(-1,1));
    figures[17].push_back(pt(0,1));
    figures[18].push_back(pt(-1,1));
    figures[18].push_back(pt(0,1));
    figures[19].push_back(pt(-1,0));
    figures[19].push_back(pt(0,1));
}

void printgrid(){
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            if(grid[i][j]==1){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int main(){
    init();

    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            grid[i][j]=0;
        }
    }
    int figure1,figure2,figure3;
    int did=0;
    while(cin>>figure1>>figure2>>figure3 && (figure1!=-1 && figure2!=-1 && figure3!=-1)){
        vector<int>can;
        vector<int>cant;
        vector<int>cantid;
        vector<int>canx;
        vector<int>cany;
        int placed1=0;
        if(did>=100){
            cout<<"-1 -1 -1 -1 -1 -1 -1 -1 -1\n";
            flush(cout);
            continue;
        }
        did++;
        for(int i=1;i<=10;++i){
            for(int j=1;j<=10;++j){
                if(isplacable(figure1,i,j)){
                    place(figure1,i,j);
                    //8printgrid();
                    can.push_back(1);
                    canx.push_back(i);
                    cany.push_back(j);
                    placed1=1;
                    tryclear();
                    //printgrid();
                    break;
                }
            }
            if(placed1)break;
        }
        if(placed1==0){
            cant.push_back(1);
            cantid.push_back(figure1);
        }
        tryclear();
        int placed2=0;
        for(int i=1;i<=10;++i){
            for(int j=1;j<=10;++j){
                if(isplacable(figure2,i,j)){
                    place(figure2,i,j);
                   // printgrid();
                    can.push_back(2);
                    canx.push_back(i);
                    cany.push_back(j);
                    placed2=1;
                    tryclear();
                    //printgrid();
                    break;
                }
            }
            if(placed2)break;
        }
        if(placed2==0){
            cant.push_back(2);
            cantid.push_back(figure2);
        }
        tryclear();
        int placed3=0;
        for(int i=1;i<=10;++i){
            for(int j=1;j<=10;++j){
                if(isplacable(figure3,i,j)){
                    place(figure3,i,j);
                    //printgrid();
                    can.push_back(3);
                    canx.push_back(i);
                    cany.push_back(j);
                    placed3=1;
                    tryclear();
                    //printgrid();
                    break;
                }
            }
            if(placed3)break;
        }
        if(placed3==0){
            cant.push_back(3);
            cantid.push_back(figure3);
        }
        tryclear();
        //tryagain
        /*if(cant.size()>0){

            while(1){
                vector<int>justidx;
                for(int i=0;i<cant.size();++i){
                    int curid=cantid[i];
                    int curidx=cant[i];
                    for(int j=1;j<=10;++j){
                        for(int k=1;k<=10;++k){
                            if(isplacable(curid,j,k)){
                                place(curid,j,k);
                               // printgrid();
                                can.push_back(curidx);
                                canx.push_back(j);
                                cany.push_back(k);
                                justidx.push_back(curidx);
                                tryclear();
                                //printgrid();
                                break;
                            }
                        }
                    }
                }
                if(justidx.size()==0){
                    break;
                }
                else{
                    for(int i=0;i<justidx.size();++i){
                        int a=justidx[i];
                        int delidx=-1;
                        for(int it=0;it<cant.size();++it){
                            if(cant[it]==a){
                                delidx=it;
                                break;
                            }
                        }
                        if(delidx!=-1){
                            cant.erase(cant.begin()+delidx);
                            cantid.erase(cantid.begin()+delidx);
                        }
                    }
                }
            }

        }*/
        //tryagain
        int printed=0;
        for(int i=0;i<can.size();++i){
            cout<<can[i]<<" "<<canx[i]<<" "<<cany[i];
            flush(cout);
            printed++;
            if(printed<3){
                cout<<" ";
                flush(cout);
            }
        }
        for(int i=0;i<cant.size();++i){
            cout<<"-1 -1 -1";
            flush(cout);
            printed++;
            if(printed<3){
                cout<<" ";
                flush(cout);
            }
        }
        tryclear();
        cout<<"\n";
        flush(cout);
        //printgrid();
    }
    return 0;
}
