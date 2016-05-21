#include <bits/stdc++.h>
#define eps 0.000000001

using namespace std;

double disbetween(double ax, double ay, double bx, double by){
    double a=(ax-bx)*(ax-bx);
    double b=(ay-by)*(ay-by);
    double c=a+b;
    return sqrt(c);
}


struct bottleinfo{
    int idx;
    double dis;
    bottleinfo(int a, double b){
        idx=a;
        dis=b;
    }
};

bool mycompare(bottleinfo &a, bottleinfo &b){
    if(fabs(a.dis-b.dis)<eps)return a.idx<b.idx;
    return a.dis<b.dis;
}

int main(){
    double adilx,adily,berax,beray,binx,biny;
    while(scanf("%lf %lf %lf %lf %lf %lf",&adilx,&adily,&berax,&beray,&binx,&biny)==6){
    int bottles;
    vector<double>alldisfrombin;
    vector<bottleinfo>disfromadil;
    vector<bottleinfo>disfrombera;
    scanf("%d",&bottles);
    double initialans=0;
    for(int i=1;i<=bottles;++i){
        double bx,by;
        scanf("%lf %lf",&bx,&by);
        double thisdis=disbetween(bx,by,binx,biny);
        alldisfrombin.push_back(thisdis);
        initialans+=2.0*thisdis;
        double adildis=disbetween(bx,by,adilx,adily);
        double beradis=disbetween(bx,by,berax,beray);
        bottleinfo foradil(i,adildis);
        bottleinfo forbera(i,beradis);
        disfromadil.push_back(foradil);
        disfrombera.push_back(forbera);
    }
    cout<<"initial ans "<<initialans<<"\n";
    //sort(disfromadil.begin(),disfromadil.end(),mycompare);
    //sort(disfrombera.begin(),disfrombera.end(),mycompare);
    //both will take something;
    //choose for adil;
    int minadil;
    double adilval=1000000000000000.0;
    for(int i=0;i<bottles;++i){
        int bottlei=disfromadil[i].idx;
        double adilportion=disfromadil[i].dis-alldisfrombin[bottlei-1];
        if(adilportion<adilval){
            adilval=adilportion;
            minadil=bottlei;
        }
    }
    int minbera1;
    double beraval1=1000000000000000.0;
    for(int i=0;i<bottles;++i){
        int bottlei=disfrombera[i].idx;
        double beraportion=disfrombera[i].dis-alldisfrombin[bottlei-1];
        if(beraportion<beraval1){
            beraval1=beraportion;
            minbera1=bottlei;
        }
    }
    int minbera2=-1;
    double beraval2=1000000000000000.0;
    for(int i=0;i<bottles;++i){
        int bottlei=disfrombera[i].idx;
        if(bottlei==minbera1)continue;
        double beraportion=disfrombera[i].dis-alldisfrombin[bottlei-1];
        if( beraportion<beraval2){
            beraval2=beraportion;
            minbera2=bottlei;
        }
    }
    int minadil2=-1;
    double adilval2=1000000000000000.0;
    for(int i=0;i<bottles;++i){
        int bottlei=disfromadil[i].idx;
        if(bottlei==minadil)continue;
        double adilportion=disfromadil[i].dis-alldisfrombin[bottlei-1];
        if(adilportion<adilval2){
            adilval2=adilportion;
            minadil2=bottlei;
        }
    }
    double ans1=1000000000000000.0,ans2=1000000000000000.0,ans3=1000000000000000.0,ans4=1000000000000000.0;
    if(minbera1==minadil){
        if(minbera2!=-1)
        ans1=adilval+beraval2;
        else{
            ans1=adilval;
        }
    }
    else{
        ans1=adilval+beraval1;
    }
    if(minbera1==minadil){
        if(minadil2!=-1)
        ans4=beraval1+adilval2;
        else{
            ans4=beraval1;
        }
    }
    else{
        ans1=adilval+beraval1;
    }
    ans2=adilval;
    ans3=beraval1;
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<"\n";
    double minans=min(min(ans1,ans4),min(ans2,ans3));
    double finans=initialans+minans;
    printf("%.8lf\n",finans);
    }
}
